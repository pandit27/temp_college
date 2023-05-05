// C++ program to implement prim's algorithm
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <utility>

using namespace std;

class Solution {
    list<pair<int, int>> *adj; // adj list to store edges

    public:
        Solution(int n) {
            adj = new list<pair<int, int>>[n];
        }

        void addEdge(int u, int v, int w) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int prims(int n, vector<pair<int, int>> &mst) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // priority queue to store (weight, node)

            vector<int> vis(n, 0);

            pq.push({0, 0});
            int sum = 0;

            while (!pq.empty()) {
                auto it = pq.top();
                pq.pop();

                int node = it.second;
                int wt = it.first;

                if(vis[node] == 1) {
                    continue;
                } 

                vis[node] = 1;
                sum += wt;

                // add edge to mst
                if(node != 0) {
                    mst.push_back(make_pair(node, wt));
                }
            }
            
        }
};

int main() {
    vector<pair<int, int>> mst; int n;
    cout<<"Enter the size of the array: ";cin>>n;
    Solution s(n);
    s.addEdge(0, 1, 4);
    s.addEdge(0, 2, 3);
    s.addEdge(1, 2, 1);
    s.addEdge(1, 3, 2);
    s.addEdge(2, 3, 4);
    s.addEdge(3, 4, 2);
    s.addEdge(4, 5, 6);
    s.prims(n, mst);

    return 0;
}