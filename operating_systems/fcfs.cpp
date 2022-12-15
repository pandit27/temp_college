/*
    Write program to implement FCFS scheduling algorithm
*/

#define N 5 // no. of processes
#include <bits/stdc++.h>
using namespace std;

class fcfs
{
public:
    int ct[N], tat[N], wt[N];
    /*
        ct = completion time
        tat = turn around time
        wt = waiting time
    */

    // default constructor
    fcfs()
    {
        ct[0] = 0;
        tat[0] = 0;
        wt[0] = 0;
    }

    void completionTime(int *, int *);
    /*
        ct[i] = ct[i - 1] + bt[i]
    */

    void waitingTime(int *);
    /*
        wt[i] = tat[i] - bt[i]
    */

    void turnAroundTime(int *);
    /*
        tat[i] = ct[i] - at[i]
    */

    void print();
};

int main()
{
    fcfs obj;
    int at[N], bt[N];

    // input arrival time
    for (int i = 0; i < N; i++)
    {
        cout << "Enter the arrival time of " << (i + 1) << " process: ";
        cin >> at[i];
    }
    cout << endl;

    // input burst time
    for (int i = 0; i < N; i++)
    {
        cout << "Enter the burst time of " << (i + 1) << " process: ";
        cin >> bt[i];
    }
    cout << endl;

    obj.completionTime(at, bt);

    obj.turnAroundTime(at);

    obj.waitingTime(bt);

    return 0;
}

// calculate completion time
void fcfs::completionTime(int at[], int bt[])
{
    ct[0] = at[0] + bt[0];

    // to find completion time
    for (int i = 1; i < N; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }
}

// calculate turn around time
void fcfs::turnAroundTime(int at[])
{
    for (int i = 0; i < N; i++)
    {
        tat[i] = ct[i] - at[i];
    }

    int sum = 0, avgtat;

    // to calculate average turn around time
    for (int i = 0; i < N; i++)
    {
        sum = sum + tat[i];
    }

    avgtat = sum / N;
    cout << "Average turn around time is " << avgtat << endl;
}

// calculate waiting time
void fcfs::waitingTime(int bt[])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            wt[i] = tat[i] - bt[i];
        }
    }

    int sum = 0, avgwt;

    // to calculate average waiting time
    for (int i = 0; i < N; i++)
    {
        sum = sum + wt[i];
    }

    avgwt = sum / N;
    cout << "Average waititng time is " << avgwt << endl;
}

/*
    at  bt  ct  tat wt
    0   2   2   2   0
    1   6   8   7   1
    2   4   12  10  6
    3   9   21  18  9
    6   12  33  29  17
*/
