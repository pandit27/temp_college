// C++ code to implement Prim's Algorithm
// Code written by Priyanshu Jha

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <queue>
using namespace std;

class Solution
{
public:
    list<pair<int, int>> *adj; // adjacency list to store edges

    Solution(int v)
    {
        adj = new list<pair<int, int>>[v]; // initializing adj with v nodes
    }

    // function to add edges
    void addEdge(int u, int v, int w)
    {

        adj[u].push_back(make_pair(v, w)); // (source node, destination node, weight)
        adj[v].push_back(make_pair(u, w)); // only in an undirected graph
    }

    // function to find minimum spanning tree
    int ms_tree(int v, vector<pair<int, int>> &mst)
    {
        // Creating a priority queue to store edges with the lowest weights on top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(v, 0);

        // Pushing the starting node with weight 0 to the priority queue
        pq.push(make_pair(0, 0));
        int sum = 0; // to store the minimum spanning tree weight

        while (!pq.empty())
        {
            // Pop the edge with the lowest weight
            auto it = pq.top();
            pq.pop();

            // getting the node and weight from the popped edge
            int node = it.second;
            int wt = it.first;

            // If the node is already visited, continue to the next iteration
            if (vis[node] == 1)
            {
                continue;
            }

            // Mark the node as visited and add the weight to the sum
            vis[node] = 1;
            sum = sum + wt;

            // If the node is not the starting node, add the edge to the minimum spanning tree
            if (node != 0)
            {
                mst.push_back(make_pair(node, wt));
            }

            // Traverse all the adjacent edges of the popped node
            for (auto it : adj[node])
            {
                // getting the adjacent node and edge weight
                int adjNode = it.first;
                int edW = it.second;

                // If the adjacent node is not visited, add the edge to the priority queue
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

    vector<pair<int, int>> mst;
    int mst_weight = s.ms_tree(V, mst);

    cout << "Minimum Spanning Tree Path:" << endl;
    for (auto it : mst)
    {
        cout << it.first << " -- " << it.second << endl;
    }

    cout << "Weight of minimum spanning tree: " << mst_weight << endl;

    return 0;
}
