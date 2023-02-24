// C++ program to implement dfs traversal
// Code written by Priyanshu Jha

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class solution
{
private:
    // this function performs dfs traversal
    void dfs(int i, vector<int> &vis, vector<int> &dfs_path)
    {
        vis[i] = 1;
        dfs_path.push_back(i);

        // Use Recursion for all the nodes adjacent to this node
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                dfs(it, vis, dfs_path);
            }
        }
    }

public:
    map<int, vector<int>> adj; // map to store adjacency list

    // function to add edges to the graph => (node, adjacent node)
    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a); // for undirected graph only
    }

    // function to get the dfs traversal path
    vector<int> dfs_traversal(int v)
    {
        vector<int> vis(v, 0);
        vector<int> dfs_path;

        // call dfs() function for all the nodes that are not visited
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, dfs_path);
            }
        }

        return dfs_path;
    }
};

int main()
{
    int v = 7;

    solution s;
    s.addEdge(1, 2);
    s.addEdge(2, 4);
    s.addEdge(2, 7);
    s.addEdge(4, 6);
    s.addEdge(6, 7);
    s.addEdge(3, 5);

    vector<int> vec = s.dfs_traversal(v);

    for (auto it : vec)
    {
        cout << it << endl;
    }

    return 0;
}