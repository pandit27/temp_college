#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class solution{
public:
    map<int, vector<int>> m; // map to store adjacency matrix => edges b/w two nodes

    void addEdge(int a, int b)
    {
        m[a].push_back(b);
        m[b].push_back(a);
    }

    vector<int> bfs_path(int v)
    {
        vector<int> bfs; // vector to store bfs path
        vector<int> vis(v, 0); // vector to find if a node is visited or not

        for(int i = 0; i < v; i++)
        {
            if(vis[i] == 0)
            {
                queue<int> q; // queue to add the nodes in the queue to perform pop() operation and find the bfs path

                q.push(i);
                vis[i] = 1;

                while(!q.empty())
                {
                    int top = q.front();
                    q.pop();

                    bfs.push_back(top);

                    for(auto it : m[top])
                    {
                        if(vis[it] == 0)
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

int main(){
    int v = 7;

    solution s;
    s.addEdge(1, 4);
    s.addEdge(2, 9);
    s.addEdge(6, 8);
    s.addEdge(4, 3);
    s.addEdge(2, 7);
    s.addEdge(8, 9);
    s.addEdge(1, 10);

    vector<int> vec = s.bfs_path(v);

    for(auto it : vec){
        cout<<it<<endl;
    }

    return 0;
}