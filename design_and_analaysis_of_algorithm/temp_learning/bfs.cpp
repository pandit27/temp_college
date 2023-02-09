// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

// class to implement breadth first search algorithm
class breadhFirstSearch
{
public:
    map<int, vector<int>> m; // map to get the adjacency matrix => edges b/w two nodes

    // function to add edge b/w two nodes
    void addEdge(int a, int b)
    {
        m[a].push_back(b);
        m[b].push_back(a);
    }

    // function to implement bfs traversal algorithm
    void bfs_traversal(int v)
    {
        vector<int> bfs; // vector to store the bfs path
        vector<int> vis(v, 0); // vector to get if the node is visited or not
        for (int i = 0; i < v; i++)
        {
            if (vis[i] == 0)
            {
                queue<int> q; // queue to store the elements in a queue
                q.push(i);
                vis[i] = 1; // since first node is visited

                while (!q.empty())
                {
                    int top = q.front();
                    q.pop();

                    bfs.push_back(top);

                    for (auto it : m[top])
                    {
                        if (vis[it] == 0)
                        {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }

        // printing the elements of the vector
        for (auto it : bfs)
        {
            cout << it << endl;
        }
    }
};

int main()
{
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    breadhFirstSearch b;
    b.addEdge(1, 4);
    b.addEdge(2, 9);
    b.addEdge(6, 8);
    b.addEdge(4, 3);
    b.addEdge(2, 7);
    b.addEdge(8, 9);

    b.bfs_traversal(v);

    return 0;
}
