// C++ program to implement heap operations like insertion, deletion and heapify
// Code written by Priyanshu Jha

#include <iostream>
#include <vector>
#include <utility> // we can also use utility class to use inbuilt swap() function
// #define n 6;
using namespace std;

// class heap
class heap
{
public:
    void heapify(vector<int> &v, int i);
    void insertElement(vector<int> &v, int e);
    void deleteElement(vector<int> &v, int e);
    void printArray(vector<int> &v);
    void swap(int *a, int *b);
};

// main function
int main()
{
    vector<int> v;
    // int x;

    // taking the size of the array
    // cout<<"Enter the size of the array: ";
    // cin>>n;

    // taking elements in the array
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter element " << (i + 1) << ": ";
    //     cin >> x;
    //     v.push_back(x);
    // }

    // creating the object of class heap
    heap h;

    // inserting elements
    /*
        We can also take input from the user

        int m;
        cout<<"Enter how many elements you want to insert: ";
        cin>>m;
        for(int i = 0; i < m; i++){
            int x;
            cout << "Enter element " << (i + 1) << ": ";
            cin >> x;
            h.insertElement(v, x);
        }
    */

    h.insertElement(v, 93);
    h.insertElement(v, 6);
    h.insertElement(v, 65);
    h.insertElement(v, 46);
    h.insertElement(v, 31);
    h.insertElement(v, 5);

    // printing the array after insertion
    h.printArray(v);
}

// function to heapify the heap
void heap::heapify(vector<int> &v, int i)
{
    int n = v.size(); // n = size of the array
    int largest = i;  // assume i = largest

    int left = 2 * i + 1;  // left element of the node
    int right = 2 * i + 2; // right element of the node

    // if left is larger than largest than largest = left
    if (left < n && v[largest] < v[left])
    {
        largest = left;
    }

    // if right is larger than largest than largest = right
    if (right < n && v[largest] < v[right])
    {
        largest = right;
    }

    // if largest = i then no need to heapify
    if (largest != i)
    {
        swap(&v[i], &v[largest]);
        heapify(v, largest);
    }
}

// function to insert the element in the heap
void heap::insertElement(vector<int> &v, int e)
{
    int n = v.size();

    if (n == 0)
    {
        v.push_back(e);
    }
    else
    {
        v.push_back(e);
        for (int i = (n / 2) - 1; i >= 0; i++)
        {
            heapify(v, i);
        }
    }
}

// function to delete an element from the heap
void heap::deleteElement(vector<int> &v, int e)
{
    int n = v.size();

    if (n == 0)
    {
        v.pop_back();
    }

    int i;

    for (int i = 0; i < n; i++)
    {
        if (e == v[i])
        {
            break;
        }
    }

    swap(&v[i], &v[n - 1]);
    v.pop_back();

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(v, i);
    }
}

// function to print the array
void heap::printArray(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

// function to swap two numbers
void heap::swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*
    BASIC HEAP CONCEPTS

    ** heap is a complete binary tree

    node = i
    parent of node = floor(i / 2)
    left child of node = (2 * i) + 1
    right child of node = (2 * i) + 2
*/
