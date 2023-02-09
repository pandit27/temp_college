#include <bits/stdc++.h>
using namespace std;

class bfs
{
  public:
    // function to return bfs of given graph
    vector<int> bfsOfGraph(int v, vector<int> adj[]){
        int vis[n] = {0};
        vis[0] = 1;
        
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return bfs;
    }
}

int main()
{
  int v;
  cin>>v;
  
  vector<int> adj[];
  for(int i = 0; i < v; i++){
    
  }
  
 bfs b;
  b.bfsOfGraph()
}
