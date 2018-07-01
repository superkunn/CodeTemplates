#include<bits/stdc++.h>
using namespace std;
const int MAXV=1e5+5;
const int MAXE=1e5+5;
const int INF=1e9;
const int MAXN=1e5+5;
struct edge{int u,v,cost;};
bool cmp(const edge &e1,const edge &e2){
    return e1.cost<e2.cost;
}
edge es[MAXE];
int V,E;
int p[MAXN],r[MAXN];
void init(int n){
    for(int i=1;i<=n;i++){
        p[i]=i;
        r[i]=0;
    }
}
int findp(int x){
    if(x==p[x])return x;
    else return p[x]=findp(p[x]);
}
void unite(int x,int y){
    x=findp(x);
    y=findp(y);
    if(x==y)return;
    if(r[x]<r[y]){
        p[x]=y;
    }
    else{
        p[y]=x;
        if(r[x]==r[y])r[x]++;
    }
}
bool same(int x,int y){
    return findp(x)==findp(y);
}
int kruskal(){
    sort(es,es+E,cmp);
    init(V);
    int res=0;
    for(int i=0;i<E;i++){
        edge e=es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}
int main(){
    return 0;
}
