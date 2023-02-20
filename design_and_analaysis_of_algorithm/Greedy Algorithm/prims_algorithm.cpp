#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <utility>

using namespace std;

// class to implement prim's algorithm
class prims_algorithm
{
public:
    list<pair<int, int>> *adj; // list to store edges and weights of nodes

    // function to add edge to the graph
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // function to find minimum spanning path
    void prims_mst(int v)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int src = 0;

        vector<int> key(v, 9999);
        vector<int> parent(v, -1);
        vector<bool> mst_set(v, false);

        pq.push(make_pair(0, src));
        key[src] = 0;

        while (!pq.empty())
        {
            int top = pq.top().second;
            pq.pop();

            if (mst_set[top] == true)
            {
                continue;
            }

            mst_set[top] = true;

            for (auto i = adj[top].begin(); i != adj[top].end(); i++)
            {
                int node = (*i).first;
                int weight = (*i).second;

                if (mst_set[node] == false && key[node] > weight)
                {
                    key[node] = weight;
                    pq.push(make_pair(key[node], node));
                    parent[node] = top;
                }
            }
        }

        for (int i = 1; i < v; i++)
        {
            cout << parent[i] << i << endl;
        }
    }
};

// main function
int main()
{
    int v = 9;

    prims_algorithm p;

    p.addEdge(0, 1, 4);
    p.addEdge(0, 7, 8);
    p.addEdge(1, 2, 8);
    p.addEdge(1, 7, 11);
    p.addEdge(2, 3, 7);
    p.addEdge(2, 8, 2);
    p.addEdge(2, 5, 4);
    p.addEdge(3, 4, 9);
    p.addEdge(3, 5, 14);
    p.addEdge(4, 5, 10);
    p.addEdge(5, 6, 2);
    p.addEdge(6, 7, 1);
    p.addEdge(6, 8, 6);
    p.addEdge(7, 8, 7);

    p.prims_mst(v);

    return 0;
}

// Time Complexity is O(n + e)