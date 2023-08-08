// C++ program to implement knapsack problem
// Code written by Priyanshu Jha

#include <iostream>
#include <vector>
using namespace std;

int knapsack(const vector<int> &values, const vector<int> &weights, int capacity)
{
    int n = values.size();
    vector<int> dp(capacity + 1);

    for (int i = 0; i < n; i++)
    {
        for (int w = capacity; w >= weights[i]; w--)
        {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[capacity];
}

int main()
{
    vector<int> values = {20, 5, 10, 40, 15, 25};
    vector<int> weights = {1, 2, 3, 8, 7, 4};
    int capacity = 10;

    cout << "Knapsack value: " << knapsack(values, weights, capacity) << endl;
    return 0;
}
