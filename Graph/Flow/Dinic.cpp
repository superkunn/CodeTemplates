#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int MAXV=5000+5;
const int MAXE=500000+5;
const int INF=0x3f3f3f3f;
namespace dinic{
int tot;
int head[MAXV];
int iter[MAXV];
int level[MAXV];
struct node{
    int to,cap,rev,next;
};
node edge[2*MAXE];// two times!!!
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int a,int b,int c){
    edge[tot].to=b;
    edge[tot].cap=c;
    edge[tot].rev=tot+1;
    edge[tot].next=head[a];
    head[a]=tot++;

    edge[tot].to=a;
    edge[tot].cap=0;
    edge[tot].rev=tot-1;
    edge[tot].next=head[b];
    head[b]=tot++;
}
void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v=que.front();que.pop();
        for(int i=head[v];i!=-1;i=edge[i].next){
            node &e=edge[i];
            if(e.cap>0&&level[e.to]<0){
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v,int t,int f){
    if(v==t)return f;
    for(int &i=iter[v];i!=-1;i=edge[i].next){
        node &e = edge[i];
        if(e.cap>0&&level[v]<level[e.to]){
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                edge[e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t){
    int flow=0;
    while(1){
        bfs(s);
        if(level[t]<0)return flow;
        for(int i=0;i<MAXV;i++){
            iter[i]=head[i];
        }
        int f;
        while((f=dfs(s,t,INF))>0){
            flow+=f;
        }
    }
}
};
int main(){
    int n;
    cin>>n;
    dinic::init();
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dinic::add_edge(a,b,c);
    }
    int x,y;
    cin>>x>>y;
    cout<<dinic::max_flow(x,y)<<endl;
    return 0;
}
/*
in:
7
0 1 10
1 2 6
0 2 2
1 3 6
3 8 8
2 8 5
3 2 3
0 8
out:
11
*/
