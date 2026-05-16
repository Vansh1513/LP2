#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct Node{
    int x,y;
    int g,h,f;
    bool operator>(Node const &other) const{
        return f>other.f;
    }
};
int heuristic(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
bool isSafe(int  x,int y,vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    return (x>=0 && x<n && y>=0 && y<m && grid[x][y]==0);
}
void printGrid(vector<vector<int>>&grid,vector<pair<int,int>>&path,pair<int,int>start,pair<int,int>goal){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<char>>view(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                view[i][j]='.';
            }
            else{
                view[i][j]='X';
            }
        }
    }
    for(auto &p:path){
        if(p!=start && p!=goal){
            view[p.first][p.second]='*';
        }
    }
    view[start.first][start.second]='S';
    view[goal.first][goal.second]='G';

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<view[i][j]<<" ";
        }
        cout<<endl;
    }
}
void aStar(vector<vector<int>>&grid,pair<int,int>start,pair<int,int>goal){
    int n=grid.size();
    int m=grid[0].size();

    priority_queue<Node,vector<Node>,greater<Node>>pq;
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int h=heuristic(start.first,start.second,goal.first,goal.second);
    pq.push({start.first,start.second,0,h,h});
    while(!pq.empty()){
        Node curr=pq.top();
        pq.pop();

        int x=curr.x;
        int y=curr.y;
        if(vis[x][y]){
            continue;
        }
        vis[x][y]=true;
        if(x==goal.first && y==goal.second){
            vector<pair<int,int>>path;
            while(!(x==start.first && y==start.second)){
                path.push_back({x,y});
                pair<int,int>p=parent[x][y];

                x=p.first;
                y=p.second;
            }
            path.push_back(start);
            reverse(path.begin(),path.end());
            cout<<"Goal reached successfully"<<endl;
            cout<<"Total cost : "<<curr.g<<endl;
            printGrid(grid,path,start,goal);
            return;
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int newX=x+dx[i];
            int newY=y+dy[i];
            if(isSafe(newX,newY,grid) && !vis[newX][newY]){
                int newG=curr.g+1;
                int newH=heuristic(newX,newY,goal.first,goal.second);
                int newF=newG+newH;
                pq.push({newX,newY,newG,newH,newF});
                parent[newX][newY]={x,y};
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<"Enter rows and columns"<<endl;
    vector<vector<int>>grid(n,vector<int>(m,0));
    cout<<"ENter"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int sx,sy,gx,gy;
    cout<<"enter"<<endl;
    cin>>sx>>sy;
    cout<<"enter"<<endl;
    cin>>gx>>gy;
    if(!isSafe(sx,sy,grid) || !isSafe(gx,gy,grid)){
        cout<<"No soltuion exits"<<endl;
        return 0;
    }
    aStar(grid,{sx,sy},{gx,gy});
    return 0;
}


