// C++ code to implement counting sort
// Code written by Priyanshu Jha

#include <iostream>
#include <vector>
#define n 16 // defining the size of our array
using namespace std;

class countingSort
{
public:
    void sort(vector<int> &v);
    void printArray(vector<int> &v);
    /*
        vector<int>&v is call by reference to actuallly change the original vector, if we pass vector<int>v that is call by value then the vector will be changed only in the function that is the copy of vector will be created.
    */
};

int main()
{
    vector<int> v;
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

    // creating the object of class countingSort
    countingSort obj;

    // calling methods
    cout << "Before Sorting \n";
    obj.printArray(v);
    cout << endl;
    cout << "After Sorting \n";
    obj.sort(v);
    obj.printArray(v);

    return 0;
}

// function to perform counting sort on an array
void countingSort::sort(vector<int> &v)
{
    int y;

    // finding the largest element of the array
    int max = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    // defining the key value
    int k = max; // same as the maximum element

    // defining an array count of size k
    vector<int> c;
    /*
        Unlike an array we don't need to define the size of the vector because the elements are dynamically allocated
    */

    // initializing the array count as all elements equal to 0
    for (int i = 0; i <= k; i++)
    {
        y = 0;
        c.push_back(y);
    }

    // finding the value of v[i] and then increment the count index equals to v[i] by 1
    for (int i = 0; i < n; i++)
    {
        c[v[i]]++;
    }

    // updating the array count
    for (int i = 1; i <= k; i++)
    {
        c[i] = c[i] + c[i - 1];
    }

    // now lets create one more array temp of size n
    vector<int> temp(n);

    // now lets put the elements in array v to their sorted position in the array temp
    for (int i = (n - 1); i >= 0; i--)
    {
        // temp[c[v[i]]--] = v[i]; // mistake I did which took an hour to debug this code 😅
        temp[--c[v[i]]] = v[i];
    }

    // now lets copy the elements of temp into the array v
    for (int i = 0; i < n; i++)
    {
        v[i] = temp[i];
    }
}

void countingSort::printArray(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

/*
    LOGIC

    v = [4, 1, 4, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 0, 1, 9] // array

    size = n = 16

    largest element is 9 => k = 9 // k = key value (largest element in the array)

    range is 0 - 9 (Assuming no negative numbers are there in the array)

    Now, lets perform the counting sort

    1) lets take one more array named count whose size is equal to k(9)

    2) initialize the array count with elements at all indices with 0

    3) now inside a for loop starting from i = 0 to i <= k find the value of v[i]

    4) now go to the array count with index = v[i] which means count[v[i]] and increment the value of with 1

    5) now update the array count by using a loop from i = 1 to i <= k and update the value of the element count[i] = count[i] + count[i - 1]

    6) now check the the value of the element of array v using loop from i = (n - 1) to i = 0 and go to the index in the array count and decrement by one and place that element in the new array temp of size n at that index

    7) now copy the elements of temp to array v

    8) and you will get a sorted array
*/

/*
    DRY RUN

    v = [4, 1, 4, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 0, 1, 9] => unsorted array

    v = [0, 0, 0, 1, 1, 2, 2, 4, 4, 4, 5, 7, 7, 8, 9, 9] => sorted array
*/

/*
    TIME COMPLEXITY

    since we used 4 for loops in our function sort() so, the time complexity can be calculated as approximately O(n + k) which is approximately O(n) for k = constant
*/

/*
    OUTPUT:-

    Enter element 1: 4
    Enter element 2: 1
    Enter element 3: 4
    Enter element 4: 0
    Enter element 5: 2
    Enter element 6: 5
    Enter element 7: 4
    Enter element 8: 0
    Enter element 9: 2
    Enter element 10: 8
    Enter element 11: 7
    Enter element 12: 7
    Enter element 13: 9
    Enter element 14: 0
    Enter element 15: 1
    Enter element 16: 9

    Before Sorting
    4
    1
    4
    0
    2
    5
    4
    0
    2
    8
    7
    7
    9
    0
    1
    9

    After Sorting
    0
    0
    0
    1
    1
    2
    2
    4
    4
    4
    5
    7
    7
    8
    9
    9

*/
