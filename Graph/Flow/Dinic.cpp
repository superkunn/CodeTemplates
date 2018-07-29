#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAXV=5000+5;
const int MAXE=500000+5;
const int INF=0x3f3f3f3f;
int tot;
int head[MAXV],level[MAXV],iter[MAXV];
struct node{
    int to,cap,next;
}edge[MAXE<<1];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int c){
    edge[tot].to=v;
    edge[tot].cap=c;
    edge[tot].next=head[u];
    head[u]=tot++;
    
    edge[tot].to=u;
    edge[tot].cap=0;
    edge[tot].next=head[v];
    head[v]=tot++;
}
void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            int c=edge[i].cap;
            if(c>0&&level[v]<0){
                level[v]=level[u]+1;
                que.push(v);
            }
        }
    }
}
int dfs(int u,int t,int f){
    if(u==t)return f;
    for(int &i=iter[u];i!=-1;i=edge[i].next){
        int v=edge[i].to;
        int &c=edge[i].cap;
        if(c>0&&level[u]<level[v]){
            int d=dfs(v,t,min(f,c));
            if(d>0){
                c-=d;
                edge[i^1].cap+=d;
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
        copy(head,head+MAXV-1,iter);
        int f;
        while((f=dfs(s,t,INF))>0){
            flow+=f;
        }
    }
}
int main(){
    int n;
    cin>>n;
    init();
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add_edge(a,b,c);
    }
    int x,y;
    cin>>x>>y;
    cout<<max_flow(x,y)<<endl;
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
