// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

// class to implement depth first search algorithm
class depthFirstSearch
{
private:
    void dfs(int node, map<int, vector<int>> &m, int vis[], list<int> &ls)
    {
        vis[node] = 1;
        ls.push_back(node);

        // traverse its neighbours
        for (auto it : m[node])
        {
            if (vis[it] == 0)
            {
                dfs(it, m, vis, ls);
            }
        }
    }

public:
    list<int> dfs_traversal(int v, map<int, vector<int>> &m)
    {
        int vis[v] = {0};
        int start = 0;
        list<int> ls;

        dfs(start, m, vis, ls);

        return ls;
    }
};

int main()
{
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    return 0;
}
