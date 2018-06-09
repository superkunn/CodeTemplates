//sgu 180 Inversions
#include <bits/stdc++.h>
using namespace std;
const int MAXN=100000;
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
//*******begin*************
int bit[MAXN],n;
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}
//*********end************
int main(){
    int N;
    scanf("%d",&N);
    n=N;
    for(int i=1;i<=N;i++){
        scanf("%d",&no[i].v);
        no[i].id=i;
    }
    stable_sort(no+1,no+1+N,cmp);
    for(int i=1;i<=N;i++){
        no[i].v=i;
    }
    sort(no+1,no+1+n,cmp2);
    long long ans=0;
    for(int i=1;i<=N;i++){
        ans+=i-1-sum(no[i].v);
        add(no[i].v,1);
    }
    printf("%lld",ans);
    return 0;
}
