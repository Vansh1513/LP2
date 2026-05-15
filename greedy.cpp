#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

void selectionSort(){
    int n;
    cout<<"Enter the number of book"<<endl;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void primsMST(){
    int V,E;
    cout<<"Enetrt eh number or cities"<<endl;
    cin>>V;
    cout<<"Enter the number of roads"<<endl;
    cin>>E;
    vector<vector<pair<int,int>>>adj(V);
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<bool>vis(V,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0}); //cost,city
    int totalCost=0;
    while(!pq.empty()){
        int cost=pq.top().first;
        int node=pq.top().second;

        pq.pop();
        if(vis[node]){
            continue;
        }
        vis[node]=true;
        totalCost+=cost;
        cout << "Vertex " << node << " with cost " << cost << endl;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int rcost=it.second;
            if(!vis[adjNode]){
                pq.push({rcost,adjNode});
            }
        }
    }
    cout<<"Minimum cost to connect all cities is "<<totalCost<<endl;
}
void cheapestFlight(){
    int V,E;
    cout<<"Enter the number of airports"<<endl;
    cin>>V;
    cout<<"Entert the number of airports"<<endl;
    cin>>E;
    vector<vector<pair<int,int>>>adj(V);
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w}); //directed
    }
    queue<pair<int,pair<int,int>>>q;
    vector<int>dist(V,INT_MAX);
    int src,dst,k;
    cout<<"Enter source"<<endl;
    cin>>src;
    cout<<"Enter destination"<<endl;
    cin>>dst;
    cout<<"Enter the number of stops"<<endl;
    cin>>k;
    q.push({0,{src,0}});  //stops,src,cost
    dist[src]=0;
    while(!q.empty()){
        int stops=q.front().first;
        int node=q.front().second.first;
        int cost=q.front().second.second;
        q.pop();

        if(stops>k){
            continue;
        }
        for(auto it:adj[node]){
            int adjNode=it.first;
            int edgCost=it.second;
            if(cost+edgCost<dist[adjNode]){
                dist[adjNode]=cost+edgCost;
                q.push({stops+1,{adjNode,dist[adjNode]}});
            }
        }
    }
    if(dist[dst]==INT_MAX){
        cout<<"No flight availabel"<<E;
    }
    else{
        cout<<"Cheaspest flight cost from "<<src<<"to "<<dst<<"within k stops is "<<dist[dst]<<endl;
    }
}
int main(){
    int ch;
    do{
        cout<<"GREEDY ALGO"<<endl;
        cout<<"1.selection sort"<<endl;
        cout<<"2.Prims MST"<<endl;
        cout<<"3.Cheapest flight"<<endl;
        cout<<"4.Exit"<<endl;

        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            selectionSort();
            break;
            case 2:
            primsMST();
            break;
            case 3:
            cheapestFlight();
            break;
            case 4:
            cout<<"Exiting..."<<endl;
            default:
            cout<<"Invalid choice"<<endl;
        }
    }while(ch!=4);
}