// C++ program to implement selection sort
// Written by Priyanshu Jha

#include <iostream>
#include <utility> // this is for swap() function
#include <vector>
using namespace std;

// class insert
class selection{
    public:
        void sort(vector<int>&v, int n);
        void printArray(vector<int>&v, int n);
};

int main(){
    int n, x;
    vector<int>v;
    
    // taking size of the array
    cout<<"Enter the size of the array: ";
    cin>>n;
    
    // taking elements in the array
    for(int i = 0; i < n; i++){
        cout<<"Enter element "<<(i + 1)<<": ";
        cin>>x;
        v.push_back(x);
    }

    selection obj; // creating object of class selection
    // calling methods
    obj.printArray(v, n);
    obj.sort(v, n);
    obj.printArray(v, n);
    
    return 0;
}

/*
    DRY RUN
    9 2 6 18 5 4
    
    1st pass
    9 | 2 6 18 5 4
    9 2 | 6 18 5 4
    2 9 | 6 18 5 4
    
    2nd pass
    2 9 | 6 18 5 4
    2 9 4 | 6 18 5
    2 4 9 | 6 18 5
    
    3rd pass
    2 4 9 | 6 18 5
    2 4 9 5 | 6 18
    2 4 5 9 | 6 18
    
    4th pass
    2 4 5 9 | 6 18
    2 4 5 9 6 | 18
    2 4 5 6 9 | 18
    
    5th pass
    2 4 5 6 9 | 18
    2 4 5 6 9 18 => sorted array
*/

// method for sorting our array (vector)
void selection::sort(vector<int>&v, int n){
    // outer loop is for passes
   for(int i = 0; i < n - 1; i++){
       /*
            initializing v[i] as minimum at first and then comparing to find the minimum element in ith pass
       */
       int min_index = i;
       // inner loop is for comparisions
       for(int j = i + 1; j < n; j++){
           if(v[j] < v[min_index]){
            //   swap(v[j], v[min_index]); => not proper insertion sort
            min_index = j;
           }
       }
       // swapping of elements
       swap(v[min_index], v[i]);
   }
}

// method for printing the array (vector)
void selection::printArray(vector<int>&v, int n){
    for(int i = 0; i < n; i++){
        cout<<v[i]<<endl;
    }
}

/*
    we can also create our own swap function instead of using inbuilt swap() function

    void swap(int *a, int *b){
        int temp;
        temp = a;
        a = b;
        b = temp;
*/
