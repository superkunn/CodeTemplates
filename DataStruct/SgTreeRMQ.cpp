//hdu 1754
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN=2e5+5;
const int INF=2e9;
struct node{
    int l,r,v;
}tree[MAXN<<2];
int M;
void build(int n){
    for(M=1;M<n;M<<=1);
    for(int i=0;i<n;i++){
        scanf("%d",&tree[i+M].v);
        tree[i+M].l=tree[i+M].r=i+1;
    }
    for(int i=M+n;i<2*M;i++){
        tree[i].l=tree[i].r=i-M+1;
        tree[i].v=-INF;
    }
    for(int i=M-1;i>=1;i--){
        tree[i].l=tree[i<<1].l;
        tree[i].r=tree[i<<1|1].r;
        tree[i].v=max(tree[i<<1].v,tree[i<<1|1].v);
    }
}
void update(int pos,int x){
    pos=pos+M-1;
    tree[pos].v=x;
    for(pos>>=1;pos;pos>>=1){
        tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
    }
}
int query(int x,int l,int r){
    int L=tree[x].l;
    int R=tree[x].r;
    if(l<=L&&R<=r){
        return tree[x].v;
    }
    if(R<l||L>r){
        return -INF;
    }else{
        return max(query(x<<1,l,r),query(x<<1|1,l,r));   
    }
}
char op[5];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        build(n);
        while(m--){
            int x,y;
            scanf("%s %d%d",op,&x,&y);
            if(op[0]=='U'){
                update(x,y);
            }else{
                printf("%d\n",query(1,x,y));
            }
        }
    }
    return 0;
}
