// C++ program to implement randomized quick sort
// Code written by Priyanshu Jha

#include <iostream>
#include <vector>
#include <utility> // to use swap() inbuilt function
#include <cstdlib> // to use rand() inbuilt function
using namespace std;

// class quick
class quick{
    public:
        void sort(vector<int> &v, int l, int r);
        int partition(vector<int> &v, int l, int r);
        void swap(int &a, int &b);
        void printArray(vector<int> &v);
};

// main function
int main(){
    vector<int>v;
    int n;
    int x;
    
    // taking size of the array
    cout<<"Enter the size of the array: ";
    cin>>n;
    
    // taking elements in the array
    for(int i = 0; i < n; i++){
        cout<<"Enter element "<<(i + 1)<<": ";
        cin>>x;
        v.push_back(x);
    }
    cout<<endl;
    
    // creating the object of class quick
    class quick obj;
    // calling methods
    obj.printArray(v);
    cout<<endl;
    obj.sort(v, 0, n - 1);
    obj.printArray(v);
    
    return 0;
}

/*
    DRY RUN
    2 6 8 18 20 4
*/

// function to divide the array into sub arrays (partition)
int quick::partition(vector<int> &v, int l, int r){
    // randomly selecting pivot element from the subarray
    int randomIndex = rand() % (r - l + 1) + l;
    swap(v[randomIndex], v[r]);
    
    int pivot = v[r];
    int i = l - 1;
    
    for(int j = l; j < r; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    
    swap(v[i + 1], v[r]);
    
    return (i + 1);
}

// function to implement quick sort
void quick::sort(vector<int> &v, int l, int r){
    if(l < r){
        int piv = partition(v, l, r);
        sort(v, l, piv - 1);
        sort(v, piv + 1, r);
    }
}

// function to print the array
void quick::printArray(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
}

// function to swap two elements
void quick::swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
