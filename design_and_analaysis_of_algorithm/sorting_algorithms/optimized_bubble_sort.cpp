// This is optimized bubble sorting algorithm
// Written by Priyanshu Jha

#include <iostream>
#include <vector>
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

// 1 4 2 3 5
/*
    Dry run
    
    1st pass
    1 4 2 3 5
    1 4 2 3 5
    1 2 4 3 5
    1 2 3 4 5
    
    2nd pass
    loop will break
*/

// function to sort the elements
void bubble::sort(vector<int>&v, int n){
    // outer loop is for pass
    for(int i=0; i<n-1; i++){
        bool flag = false; // flag variable to check if the array is already sorted
        // inner loop is for elements comparision
        for(int j = 0; j < n-1-i; j++){
            if(v[j] > v[j + 1]){
                //elements swapping
                int temp;
                temp = v[j];
                v[j] = v[j+1];
                v[j + 1] = temp;
                // if swapping is not done it means that this array (vector) is already sorted so flag = false and the loop will break and the time complexity is optimized
                flag = true;
            }
        }
            // if array is already sorted then this loop will break
            if(flag == false){
                break;
            }
    }
}

// function to print the array (vector)
void bubble::printArray(vector<int>&v, int n){
    for(int i = 0; i < n; i++){
        cout<<v[i]<<endl;
    }
}
