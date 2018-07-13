//poj 3169
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int MAXV=1e5+50;
const int INF=1e9;
struct edge{int to,cost;};
typedef pair<int,int> P;
int V;
vector<edge> G[MAXV];
int d[MAXV];
int cnt[MAXV];
bool inque[MAXV];
queue<int> que;
bool spfa(int s){
    fill(d,d+V+1,INF);
    fill(cnt,cnt+V+1,0);
    fill(inque,inque+V+1,false);
    while(!que.empty()) que.pop();
    que.push(s);
    inque[s]=true;
    d[s]=0;
    cnt[s]=1;
    while(!que.empty()){
        int u=que.front();
        inque[u]=false;
        que.pop();
        for(int i=0;i<G[u].size();i++){
            edge e=G[u][i];
            if(d[u]+e.cost<d[e.to]){
                d[e.to]=d[u]+e.cost;
                if(!inque[e.to]){
                    if(++cnt[e.to]>V)return false;
                    inque[e.to]=true;
                    que.push(e.to);
                }
            }
        }
    }
    return true;
}
int main(){
    int a1,a2,a3;
    scanf("%d%d%d",&a1,&a2,&a3);
    V=a1;
    for(int i=1;i<=V;i++){
        G[i].push_back(edge{i-1,0});
    }
    for(int i=1;i<=a2;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].push_back(edge{y,z});
    }
    for(int i=1;i<=a3;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[y].push_back(edge{x,-z});
    }
   if(!spfa(1)){printf("-1");return 0;}
    printf("%d",d[V]==INF?-2:d[V]);
    return 0;
}
