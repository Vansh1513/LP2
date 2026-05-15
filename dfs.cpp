#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Graph{
    int V;
    vector<vector<int>>adj;
public:
   Graph(int vertices){
    V=vertices;
    adj.resize(V);
   }
   void addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   void DFSR(int node,vector<bool>&vis){
    vis[node]=true;
    cout<<node<<" ";
    for(int neigh:adj[node]){
        if(!vis[neigh]){
            DFSR(neigh,vis);
        }
    }
   }
   void DFS(int start){
    vector<bool>vis(V,false);
    cout<<"DFS Trvaersal: "<<endl;
    DFSR(start,vis);
    cout<<endl;
   }
   void BFS(int start){
    queue<int>q;
    vector<bool>vis(V,false);
    vis[start]=true;
    q.push(start);
    cout<<"BFS Traversal: "<<endl;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int neigh:adj[node]){
            if(!vis[neigh]){
                vis[neigh]=true;
                q.push(neigh);
            }
        }
        cout<<endl;
    }
   }
};
int main(){
    int V,E;
    cout<<"Enter the number of vertices and edges"<<endl;
    cin>>V>>E;
    Graph g(V);
    cout<<"Enter the edges (u v)"<<endl;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    int start;
    cout<<"Enter the starting node"<<endl;
    cin>>start;

    g.BFS(start);
    g.DFS(start);
    return 0;
}
