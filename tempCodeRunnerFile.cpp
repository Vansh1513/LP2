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
        cout<<"vertex"<<node<<"with cost"<<cost;
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