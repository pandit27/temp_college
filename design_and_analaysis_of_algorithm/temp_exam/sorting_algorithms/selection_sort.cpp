// C++ program to implement insertion sort

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
            int min_index = i;
            for (int j = i + 1; j < n; j++)
            {
                if (v[j] < v[min_index])
                {
                    min_index = j;
                }
            }
            if (i != min_index)
            {
                swap(v[min_index], v[i]);
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> v;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    Solution s;
    s.sort(v);

    cout << "Sorted array \n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i];
    }

    return 0;
}