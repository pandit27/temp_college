// C++ program to implement quick sort
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    void partition(vector<int> &v);
    void sort(vector<int> &v);
};

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> v;
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n; i++)
    {
        int temp;
        v.push_back(temp);
    }

    Solution s;
    s.sort(v);

    cout << "After sorting \n";

    for (auto it : v)
    {
        cout << v[it] << " ";
    }

    return 0;
}