#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
struct DSU{
    int p[MAXN];
    void init(int n){for(int i=0;i<=n;i++)p[i]=i;}
    int findp(int x){return x==p[x]?x:p[x]=findp(p[x]);}
    void unite(int x,int y){x=findp(x);y=findp(y);if(x==y)return;p[y]=x;}
    bool same(int x,int y){return findp(x)==findp(y);}
}dsu;
int main(){
    int n;
    cin>>n;
    dsu.init(n);
    int m;
    cin>>m;
    while(m--){
        int o,x,y;
        cin>>o>>x>>y;
        if(o==1){
            dsu.unite(x,y);
        }
        else{
            cout<<(int)dsu.same(x,y)<<endl;
        }
    }
    return 0;
}
