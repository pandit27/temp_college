// C++ program to implement weighted interval scheduling problem
// Code written by Priyanshu Jha

#include <algorithm>
#include <iostream>
using namespace std;

class Interval {
   public:
    int start;
    int finish;
    int weights;
};

bool intervalComparison(Interval a, Interval b) {
    return a.finish < b.finish;
}

int findOptimalWeight(Interval interval[], int n) {
    sort(interval, interval + n, intervalComparison);

    int dp[n];
    dp[0] = interval[0].weights;

    for (int i = 1; i < n; i++) {
        int includeWeight = interval[i].weights;
        int j = -1;
        for (int k = i - 1; k >= 0; k--) {
            if (interval[k].finish <= interval[i].start) {
                j = k;
                break;
            }
        }
        if (j != -1) {
            includeWeight += dp[j];
        }
        dp[i] = max(includeWeight, dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    Interval interval[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the start time of job " << i + 1 << ": ";
        cin >> interval[i].start;
        cout << "Enter the finish time of job " << i + 1 << ": ";
        cin >> interval[i].finish;
        cout << "Enter the weight of job " << i + 1 << ": ";
        cin >> interval[i].weights;
    }
    int optimalWeight = findOptimalWeight(interval, n);
    cout << "Optimal weight: " << optimalWeight;

    return 0;
}
