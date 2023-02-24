#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <queue>
using namespace std;

class Solution
{
public:
    list<pair<int, int>> *adj;

    Solution(int v)
    {
        adj = new list<pair<int, int>>[v];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int ms_tree(int v)
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
                int adjNode = it.first;
                int edW = it.second;

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

    Solution s(V);
    s.addEdge(0, 1, 4);
    s.addEdge(0, 2, 3);
    s.addEdge(1, 2, 1);
    s.addEdge(1, 3, 2);
    s.addEdge(2, 3, 4);
    s.addEdge(3, 4, 2);
    s.addEdge(4, 5, 6);

    int mst_weight = s.ms_tree(V);
    cout << "Weight of minimum spanning tree: " << mst_weight << endl;

    return 0;
}
