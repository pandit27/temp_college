// C++ code to implement radix sort
// Code written by Priyanshu Jha

#include <iostream>
#include <vector>
#define n 10// defining the size of our array
using namespace std;

class radixSort
{
public:
    void rSort(vector<int> &v, vector<int> &a);
    void cSort(vector<int> &v, vector<int> &a, int position);
    void printArray(vector<int> &v);
    /*
        vector<int>&v is call by reference to actuallly change the original vector, if we pass vector<int>v that is call by value then the vector will be changed only in the function that is the copy of vector will be created.
    */
};

int main()
{
    vector<int> v;
    vector<int> a;
    // int n, x;
    int x;

    // taking the size of the vector
    // cout << "Enter the size of the array: ";
    // cin >> n;

    // taking elements in the array
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> x;
        v.push_back(x);
    }
    cout << endl;

    // creating the object of class radixSort
    radixSort obj;

    // calling methods
    cout << "Before Sorting \n";
    obj.printArray(v);
    cout << endl;
    cout << "After Sorting \n";
    obj.rSort(v, a);
    obj.printArray(v);

    return 0;
}

// function to perform counting sort on an array
void radixSort::rSort(vector<int> &v, vector<int> &a)
{
    int max = 0;

    // finding the maximum element
    for(int i = 1; i < n; i++){
        if(v[i] > max){
            max = v[i];
        }
    }

    // calling count sort for each digit
    for(int pos = 0; int(max / pos) > 0; pos = pos * 10){
        cSort(v, a, pos);
    }

    // now lets copy the elements of temp to the array v
    for(int i = 0; i < n; i++){
        v[i] = a[i];
    }
}

// function to perform counting sort
void radixSort::cSort(vector<int> &v, vector<int> &a, int pos){
    // lets define an array count of size 10
    vector<int>c(10, 0);

    for(int i = 0; i < n; i++){
        c[(int(v[i] / pos) % 10)]++;
    }

    for(int i = 1; i < 10; i++){
        c[i] = c[i] + c[i - 1];
    }

    // lets create an array temp
    vector<int>temp(n);

    for(int i = (n - 1); i >= 0; i--){
        temp[--c[(int(v[i] / pos) % 10)]] = v[i];
    }
}

// function to print the elements of the array
void radixSort::printArray(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

/*
    LOGIC

    v = [487, 6, 520, 80, 90, 320, 14, 95, 897, 645] // array

    size = n = 16

    
*/

/*
    DRY RUN

    v = [487, 6, 520, 80, 90, 320, 14, 95, 897, 645] => unsorted array

    v = [6, 14, 80, 90, 95, 320, 487, 520, 645, 897] => sorted array
*/
