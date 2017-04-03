//判断有向图中是否存在回路
#include <iostream>
#include "cstring"
#define N 100
using namespace std;

int Graph[N][N],path[N],visited[N],n,cycle;

int dfs(int u,int start);
void DisPath(int u);

int main(){
    cin>>n;//顶点个数
     memset(Graph,0,sizeof(Graph));
    /*
     4
     0 1 1 0
     0 0 1 1
     0 0 0 0
     1 0 0 0
     */
    for(int i=0;i<n;i++)            //读入邻接矩阵
        for(int j=0;j<n;j++)
            cin>>Graph[i][j];
    cycle=-1;
    for(int i=0;i<n;i++)
        if(!visited[i] && dfs(i,-1))
            break;
    if(cycle<0)
        cout<<"No found ring"<<endl;
    else{
        cout<<"exit ring"<<endl;
        DisPath(cycle);
        cout<<endl;
    }
    
    return 0;
    
}


int dfs(int u,int start){
    int i;
    visited[u]=-1;
    path[u]=start;
    for(i=0;i<n;i++){
        if(Graph[u][i] && i!=start){  //u到i存在弧，且i不等于start
            if(visited[i]<0){
                cycle=u;
                return 0;
            }
            if(!dfs(i,u))//如果存在路径，则继续深度搜索
                return 0;
        }
    }
    visited[u]=1;
    return 1;
}

void DisPath(int u){
    if(u<0)
        return;
    DisPath(path[u]);
    cout<<" "<<u;
}







