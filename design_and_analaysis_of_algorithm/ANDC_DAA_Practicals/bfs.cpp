// C++ code to implement bfs traverasal in a graph
// Code written by Priyanshu Jha

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class solution
{
public:
    map<int, vector<int>> m; // map to store adjacency matrix => edges b/w two nodes

    void addEdge(int a, int b)
    {
        m[a].push_back(b); // add edge from a to b
        m[b].push_back(a); // add edge from b to a (only if it is an undirected graph)
    }

    vector<int> bfs_path(int v)
    {
        vector<int> bfs;       // vector to store bfs path
        vector<int> vis(v, 0); // vector to find if a node is visited or not

        for (int i = 0; i < v; i++) // for loop to traverse over all nodes
        {
            if (vis[i] == 0) // if the node is unvisited
            {
                queue<int> q; // queue to add the nodes in the queue to perform pop() operation and find the bfs path

                q.push(i);  // add the starting node to the queue
                vis[i] = 1; // mark the starting node as visited

                while (!q.empty()) // while there are still nodes in the queue
                {
                    int top = q.front(); // take the first node in the queue
                    q.pop();             // remove the first node from the queue

                    bfs.push_back(top); // add the node to the bfs vector to keep track of the order in which nodes are visited

                    for (auto it : m[top]) // for loop to traverse over all the neighbors of the current node
                    {
                        if (vis[it] == 0) // if the neighbor has not been visited yet
                        {
                            q.push(it);  // add the neighbor to the queue
                            vis[it] = 1; // mark the neighbor as visited
                        }
                    }
                }
            }
        }

        return bfs; // return the bfs vector containing the bfs path
    }
};

int main()
{
    int v = 10; // number of nodes in the graph

    solution s;
    // add edges to the graph
    s.addEdge(0, 3);
    s.addEdge(1, 8);
    s.addEdge(5, 7);
    s.addEdge(3, 2);
    s.addEdge(1, 6);
    s.addEdge(7, 8);
    s.addEdge(0, 9);

    vector<int> vec = s.bfs_path(v); // perform BFS traversal starting from node 0

    for (auto it : vec) // print out the order in which nodes were visited during the traversal
    {
        cout << it << endl;
    }

    return 0;
}
