// C++ program to implement DFS Traversal
// code written by Priyanshu Jha

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <utility>
using namespace std;

// class to implement dfs traversal
class depth_first_search
{
private:
    // function to get the dfs path
    void dfs(int i, vector<bool> &visited, vector<int> &dfs_path)
    {
        visited[i] = true;
        dfs_path.push_back(i);

        for (auto it : adj[i])
        {
            if (!visited[it])
            {
                dfs(it, visited, dfs_path);
            }
        }
    }

public:
    map<int, vector<int>> adj;

    // function to add edge
    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a); // for undirected graph only
    }

    // function to make a recursive call and return the final bfs path
    vector<int> dfs_tranversal(int v)
    {
        vector<bool> visited(v, false);
        vector<int> dfs_path;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, dfs_path);
            }
        }

        return dfs_path;
    }
};

int main()
{
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    depth_first_search d;

    d.addEdge(1, 2);
    d.addEdge(2, 4);
    d.addEdge(2, 7);
    d.addEdge(4, 6);
    d.addEdge(6, 7);
    d.addEdge(3, 5);

    vector<int> vec = d.dfs_tranversal(v);

    // printing the dfs path
    for (auto it : vec)
    {
        cout << vec[it] << endl;
    }

    return 0;
}

// Time complexity => O(n) -- overall
