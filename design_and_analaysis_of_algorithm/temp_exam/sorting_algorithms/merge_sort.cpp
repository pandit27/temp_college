// C++ code to implement merge sort
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &v, int left, int mid, int right)
    {
        vector<int> temp;
        int i = left, j = mid + 1;

        while (i <= mid && j <= right)
        {
            if (v[i] <= v[j])
            {
                temp.push_back(v[i++]);
            }
            else
            {
                temp.push_back(v[j++]);
            }
        }

        while (i <= mid)
        {
            temp.push_back(v[i++]);
        }

        while (j <= right)
        {
            temp.push_back(v[j++]);
        }

        for (int k = 0; k < temp.size(); k++)
        {
            v[left + k] = temp[k];
        }
    }

    void merge_sort(vector<int> &v, int low, int high)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        merge_sort(v, low, mid);
        merge_sort(v, mid + 1, high);
        merge(v, low, mid, high);
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
    s.merge_sort(v, 0, n - 1);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}