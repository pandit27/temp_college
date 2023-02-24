// Code written by Priyanshu Jha
// C++ code to find the minimum spanning tree weight

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <queue>
using namespace std;

class solution
{
public:
    int ms_tree(int v, list<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // (weight, node)

        vector<int> vis(v, 0);

        pq.push(make_pair(0, 0));
        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
            {
                continue;
            }

            vis[node] = 1;
            sum = sum + wt;

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];

                if (!vis[adjNode])
                {
                    pq.push(make_pair(edW, adjNode));
                }
            }
        }

        return sum;
    }
};

int main()
{
    int V = 6;

    list<vector<int>> adj[V];

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 3});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 2});
    adj[2].push_back({3, 4});
    adj[3].push_back({4, 2});
    adj[4].push_back({5, 6});

    solution s;

    int mst_weight = s.ms_tree(V, adj);
    cout << "Weight of minimum spanning tree: " << mst_weight << endl;

    return 0;
}
