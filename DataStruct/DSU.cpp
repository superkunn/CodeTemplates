#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
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
int main(){
    int n;
    cin>>n;
    init(n);
    int m;
    cin>>m;
    while(m--){
        int o,x,y;
        cin>>o>>x>>y;
        if(o==1){
            unite(x,y);
        }
        else{
            cout<<(int)same(x,y)<<endl;
        }
    }
    return 0;
}
