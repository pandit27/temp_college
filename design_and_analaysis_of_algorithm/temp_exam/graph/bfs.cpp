// C++ program to implement bfs
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>

using namespace std;

class Solution {
    public:
        map<int, vector<int>> adj;

        void addEdge(int a, int b) {
            adj[a].push_back(b);
            adj[b].push_back(a); // only if the graph is undirected
        }

        vector<int> bfs_path(int n) {
            vector<int> bfs;
            vector<int> vis(n, 0);
            queue<int> q;

            for(int i = 0; i < n; i++) {
                if(vis[i] == 0) {
                    q.push(i);
                    vis[i] == 1;

                    while(!q.empty()) {
                        int top = q.front();
                        q.pop();

                        bfs.push_back(top);

                        for(auto it : adj[top]) {
                            q.push(it);
                            vis[it] == 1;
                        }
                    }
                }
            }
            return bfs;
        }
};

int main() {
    int n;
    cout<<"Enter the size of vector: ";cin>>n;;

    Solution s;
    vector<int> vec = s.bfs_path(n);
    for(auto it : vec) {
        cout << vec[it] << endl;
    }

    return 0;
}