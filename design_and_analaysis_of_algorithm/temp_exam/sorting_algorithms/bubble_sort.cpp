// C++ program to implement bubble sort
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    void sort(vector<int> &v)
    {
        int n = v.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (v[j] > v[j + 1])
                {
                    swap(v[j], v[j + 1]);
                }
            }
        }
    }
};

int main()
{
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    vector<int> v;
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    Solution s;
    s.sort(v);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}