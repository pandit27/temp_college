#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    vector<int> h_sort(vector<int> &v);
    void heapify(vector<int> &v, int size, int i);
};

int main()
{
    vector<int> v{4, 6, 17, 83, 29, 20, 16, 5, 14};

    solution s;
    vector<int> hp = s.h_sort(v);

    for (auto it : hp)
    {
        cout << it << endl;
    }

    return 0;
}

vector<int> solution::h_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(v, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(v[i], v[0]);

        heapify(v, i, 0);
    }

    return v;
}

void solution::heapify(vector<int> &v, int n, int i)
{
    int largest = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    if (l < n && v[l] > v[largest])
    {
        largest = l;
    }

    if (r < n && v[r] > v[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(v[i], v[largest]);

        heapify(v, n, largest);
    }
}