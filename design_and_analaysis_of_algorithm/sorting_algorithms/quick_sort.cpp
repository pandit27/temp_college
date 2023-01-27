// C++ program to implement quick sort
// Written by Priyanshu Jha

#define n 6 // defining the size of the array
#include <iostream>
#include <vector>
#include <utility> // to use swap() inbuilt function
using namespace std;

// class quick
class quick{
    public:
        void sort(vector<int> &v, int l, int r);
        int partition(vector<int> &v, int l, int r);
        // void swap(int *a, int *b);
        void printArray(vector<int> &v);
};

// main function
int main(){
    vector<int>v;
    // int n, x;
    int x;
    
    // taking size of the array
    // cout<<"Enter the size of the array: ";
    // cin>>n;
    
    // taking elements in the array
    for(int i = 0; i < n; i++){
        cout<<"Enter element "<<(i + 1)<<": ";
        cin>>x;
        v.push_back(x);
    }
    
    // creating the object of class quick
    class quick obj;
    // calling methods
    obj.printArray(v);
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
    int pivot, i;
    pivot = v[r];
    i = l - 1;
    
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
    for(int i = 0; i < n; i++){
        cout<<v[i]<<endl;
    }
}

/*
    we can also create our own swap function
    
    void quick::swap(int *a, int *b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
/*
