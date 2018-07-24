#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int M;
int tree[100000];
void up(int i){tree[i]=tree[i<<1]+tree[i<<1|1];}
void build(int n){
    for(M=1;M<n;M<<=1);
    for(int i=M+1;i<=M+n;i++)scanf("%d",&tree[i]);
    for(int i=M-1;i;i--)up(i);
}
void update(int pos,int v){
    pos+=M;
    tree[pos]=v;
    for(pos>>=1;pos;pos>>=1)up(pos);
}
int sum(int l,int r){
    int ans=0;
    for(l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1){
        if(~l&1)ans+=tree[l^1];
        if(r&1)ans+=tree[r^1];
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    build(n);
    return 0;
}
