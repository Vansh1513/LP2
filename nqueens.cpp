#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<vector<int>>board;
vector<bool>columns,leftDiag,rigthDiag;

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==1){
                cout<<"Q";
            }
            else{
                cout<<".";
            }
        }
        cout<<endl;
    }
}
bool solve(int row){
    if(row==n){
        return true;
    }
    for(int col=0;col<n;col++){
        int leftIdx=row-col+n-1;
        int rightIdx=row+col;

        if(!columns[col] && !leftDiag[leftIdx] && !rigthDiag[rightIdx]){
            board[row][col]=1;

            columns[col]=true;
            leftDiag[leftIdx]=true;
            rigthDiag[rightIdx]=true;

            if(solve(row+1)){
                return true;
            }
            board[row][col]=0;

            columns[col]=false;
            leftDiag[leftIdx]=false;
            rigthDiag[rightIdx]=false;

        }
    }
    return false;
}
int main(){
    cout<<"Enter the number of queens"<<endl;
    cin>>n;
    board.resize(n,vector<int>(n,0));
    columns.resize(n,false);
    leftDiag.resize(2*n-1,false);
    rigthDiag.resize(2*n-1,false);

    if(solve(0)){
        print();
    }
    else{
        cout<<"No solution exists"<<endl;
    }
    return 0;

}