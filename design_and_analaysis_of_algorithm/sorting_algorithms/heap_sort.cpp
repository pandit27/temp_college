// C++ program to implement heap sort
// Code written by Priyanshu Jha

#include <iostream>
#include <vector>
// #define n 6;
using namespace std;

// class heap
class heap
{
public:
    void h_sort(vector<int> &v, int n);
    void heapify(vector<int> &v, int i);
    void insertElement(vector<int> &v, int n, int e);
    void deleteElement(vector<int> &v, int n, int e);
    void printArray(vector<int> &v, int n);
    void swap(int *a, int *b);
};

// main function
int main()
{
    vector<int> v;
    int n, x;

    // taking the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // taking elements in the array
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> x;
        v.push_back(x);
    }

    // creating the object of class heap
    heap h;

    // calling methods
    h.h_sort(v, n);
    h.printArray(v, n);

    return 0;
}

// function to perform heap sort
void heap::h_sort(vector<int> &v, int n)
{
    // heapify the heap first to get the largest element at index 0
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(v, i);
    }

    // now swap v[0] with v[n - 1] and reduce the size of n by 1
    for (int i = (n - 1); i >= 0; i--)
    {
        swap(&v[0], &v[i]);
        heapify(v, i);
    }
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

// function to insert an element in the heap
void heap::insertElement(vector<int> &v, int n, int e)
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
void heap::deleteElement(vector<int> &v, int n, int e)
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
void heap::printArray(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
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
    Basic heap concepts

    ** heap is a complete binary tree

    node = i
    parent of node = floor(i / 2)
    left child of node = 2 * i
    right child of node = (2 * i) + 1
*/

/*
    LOGIC

    1) First heapify the tree

    2) now the largest element is at index 0

    3) now swap v[0] and v[n - 1]

    4) reduce the size of heap by 1

    5) now again heapify and again the larger element is at index 0

    6) again swap v[0] and v[n - 2]

    7) repeat this til the size of the heap is 0

    8) you will get a sorted array
*/

/*
    TIME COMPLEXITY

    O(n * log(n))
*/

/*
    DRY RUN

    v = [4, 1, 86, 5, 14, 7] => unsorted array

    v = [1, 4, 5, 7, 14, 86] => sorted array
*/
