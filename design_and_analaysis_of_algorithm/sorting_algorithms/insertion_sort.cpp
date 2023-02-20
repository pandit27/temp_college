// C++ program to implement insertion sort 
// Written by Priyanshu Jha

#include <iostream>
#include <vector>
using namespace std;

// class insert
class insert{
    public:
        void sort(vector<int>&v, int n);
        void printArray(vector<int>&v, int n);
};

// main function
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
    
    insert i; // creating object of class insert
    // calling methods
    cout<<"unsorted array \n";
    i.printArray(v, n);
    i.sort(v, n);
    cout<<"sorted array \n";
    i.printArray(v, n);
    cout<<"executed successfully";
    
    return 0;
}

/*
    DRY RUN
    4 6 78 1 5 9
    
    1st pass
    4 | 6 78 1 5 9 (temp = 6)
    4 | ? 78 1 5 9
    4 6 | 78 1 5 9
    
    2nd pass
    4 6 | 78 1 5 9 (temp = 78)
    4 6 | ? 1 5 9
    4 6 78 | 1 5 9
    
    3rd pass
    4 6 78 | 1 5 9 (temp = 1)
    4 6 78 | ? 5 9
    4 6 78 1 | 5 9
    4 6 1 78 | 5 9
    4 1 6 78 | 5 9
    1 4 6 78 | 5 9 
    
    4th pass
    1 4 6 78 | 5 9 (temp = 5)
    1 4 6 78 | ? 9
    1 4 6 78 5 | 9
    1 4 6 5 78 | 9
    1 4 5 6 78 | 9
    
    5th pass
    1 4 5 6 78 | 9 (temp = 9)
    1 4 5 6 78 9
    1 4 5 6 9 78 => sorted array
    
    no. of passes required for size n is equal to (n - 1)
*/

// method for sorting our array (vector)
void insert::sort(vector<int>&v, int n){
    // outer loop is for passes
    for(int i = 1; i < n; i++){
        int j;
        // inner loop is for comparision
        for(int j = i-1; j >= 0; j--){
            if(v[j] > v[j+1]){
                int temp;
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// method for printing the array (vector)
void insert::printArray(vector<int>&v, int n){
    for(int i = 0; i < n; i++){
        cout<<v[i]<<endl;
    }
}

// we can also reduce its time coplexity by using binary search algorithm to find the appropriate position to insert the element
// optimized insertion sort => insertion sort + binary search
