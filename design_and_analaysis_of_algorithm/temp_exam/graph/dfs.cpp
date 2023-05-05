// C++ program to implement dfs
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

class Solution
{
    map<int, vector<int>> adj;

private:
    void dfs(int i, vector<int> vis, vector<int> dfs_traversal) {
        vis[i] == 1;
        dfs_traversal.push_back(i);

        for(auto it : adj[i]) {
            if(vis[it] == 0) {
                dfs(it, vis, dfs_traversal);
            }
        }
    }
public:
    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a); // only if the graph is undirected
    }

    vector<int> dfs_path(int n)
    {
        vector<int> dfs_traversal;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, vis, dfs_traversal);
            }
        }
        return dfs_traversal;
    }
};

int main() {
    int n;
    cout<<"Enter the size of the array: ";cin>>n;
    Solution s;
    s.addEdge(1, 4); 
    s.addEdge(2, 6);
    s.addEdge(4, 5);
    s.addEdge(5, 6);
    vector<int> vec = s.dfs_path(n);
    for(auto it : vec) {
        cout << vec[it] << endl;
    }

    return 0;
}