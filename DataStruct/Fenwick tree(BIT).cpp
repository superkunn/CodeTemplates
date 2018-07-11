//sgu 180 Inversions
#include <bits/stdc++.h>
using namespace std;
//*******begin*************
const int MAXN=100000;
struct BIT{
    int c[MAXN<<1],n;
    void init(int _n){
        n=_n;
        for(int i=1;i<=n;i++)c[i]=0;
    }
    void add(int i,int x){
        while(i<=n){
            c[i]+=x;
            i+=i&-i;
        }
    }
    int sum(int i){
        int s=0;
        while(i>0){
            s+=c[i];
            i-=i&-i;
        }
        return s;
    }
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
