//sgu 180 Inversions
#include <bits/stdc++.h>
using namespace std;
//*******begin*************
const int MAXN=100000;
struct BIT{
    int n,c[MAXN<<1];
    void init(int _n){n=_n;for(int i=0;i<=n;i++)c[i]=0;}
    void add(int i,int v){for(;i<=n;i+=i&-i)c[i]+=v;}
    int sum(int i){int s=0;for(;i>0;i-=i&-i)s+=c[i];return s;}
}bit;
//*********end************
struct node{
    int id;
    int v;
}no[MAXN];
bool cmp(node x,node y){
    return x.v<y.v;
}
bool cmp2(node x,node y){
    return x.id<y.id;
}
int main(){
    int N;
    scanf("%d",&N);
    bit.init(N);
    for(int i=1;i<=N;i++){
        scanf("%d",&no[i].v);
        no[i].id=i;
    }
    stable_sort(no+1,no+1+N,cmp);
    for(int i=1;i<=N;i++){
        no[i].v=i;
    }
    sort(no+1,no+1+N,cmp2);
    long long ans=0;
    for(int i=1;i<=N;i++){
        ans+=i-1-bit.sum(no[i].v);
        bit.add(no[i].v,1);
    }
    printf("%lld",ans);
    return 0;
}
