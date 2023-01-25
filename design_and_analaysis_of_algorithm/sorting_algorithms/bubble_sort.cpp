#include <bits/stdc++.h>
using namespace std;

// class bubble
class bubble{
    public:
        void sort(vector<int>&v, int n);
        void printArray(vector<int>&v, int n);
        // vector<int>&v is call by reference to actuallly change the original vector, if we pass vector<int>v that is call by value then the vector will be changed only in the function that is the copy of vector will be created.
};

// main function
int main(){
    int x;
    vector<int> v;
    
    // take the size of the array
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
        
    // taking input in the array (vector)
    for(int i=0; i<n; i++){
        cout<<"Enter element "<<(i + 1)<<": ";
        cin>>x;
        v.push_back(x);
    }
    
    bubble b; // creating the object of class bubble
    // calling methods
    b.sort(v, n);
    b.printArray(v, n);
    
    // displaying the elements of the array
    // for(int i = 0; i<n; i++){
    //     cout<<v[i]<<endl;
    // }
    
    return 0;
}

// 16 15 7 3 9
/*
    Dry run
    
    1st pass
    16 15 7 3 9
    15 16 7 3 9
    15 7 16 3 9
    15 7 3 16 9
    15 7 3 9 16
    
    2nd pass
    15 7 3 9 16
    7 15 3 9 16
    7 3 15 9 16
    7 3 15 9 16
    
    3rd pass
    7 3 15 9 16
    3 7 15 9 16
    3 7 15 9 16
    3 7 9 15 16
    
    4th pass
    3 7 9 15 16
    3 7 9 15 16
    3 7 9 15 16
    3 7 9 15 16
*/

// function to sort the elements
void bubble::sort(vector<int>&v, int n){
    // outer loop is for pass
    for(int i=0; i<n-1; i++){
        // inner loop is for elements comparision
        for(int j = 0; j < n-1-i; j++){
            if(v[j] > v[j + 1]){
                //elements swapping
                int temp;
                temp = v[j];
                v[j] = v[j+1];
                v[j + 1] = temp;
            }
        }
    }
}

// function to print the array (vector)
void bubble::printArray(vector<int>&v, int n){
    for(int i = 0; i < n; i++){
        cout<<v[i]<<endl;
    }
}
