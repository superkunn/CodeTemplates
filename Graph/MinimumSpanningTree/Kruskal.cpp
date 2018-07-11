//poj 1258
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXE=1e5+5;
const int MAXN=1e5+5;
struct DSU{
    int p[MAXN],r[MAXN];
    void init(int x){
        for(int i=0;i<=x;i++){
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
}dsu;
struct edge{int u,v,cost;}es[MAXE];
bool cmp(const edge &e1,const edge &e2){
    return e1.cost<e2.cost;
}
int V,E;
int kruskal(){
    sort(es,es+E,cmp);
    dsu.init(V);
    int res=0;
    for(int i=0;i<E;i++){
        edge e=es[i];
        if(!dsu.same(e.u,e.v)){
            dsu.unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}
int main(){
    while(~scanf("%d",&V)){
        E=0;
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                int w;
                scanf("%d",&w);
                if(i==j)continue;
                es[E].u=i;
                es[E].v=j;
                es[E].cost=w;
                E++;
            }
        }
        printf("%d\n",kruskal());
    }
    return 0;
}
