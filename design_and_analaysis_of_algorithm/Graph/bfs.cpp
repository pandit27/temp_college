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
    map<int, vector<int>> m;

    void addEdge(int a, int b)
    {
        m[a].push_back(b);
        m[b].push_back(a);
    }

    vector<int> bfs_traversal(int v)
    {
        vector<int> bfs;
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (vis[i] == 0)
            {
                queue<int> q;
                q.push(i);
                vis[i] = 1;

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

        return bfs;
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

    vector<int> vec = b.bfs_traversal(v);

    for (auto it : vec)
    {
        cout << it << endl;
    }

    return 0;
}
