//cf 1009F
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
const int INF=1e9;
vector<int> G[MAXN];
int stamp,sz[MAXN],st[MAXN],ed[MAXN],rev[MAXN],cnt[MAXN];
int dep[MAXN],maxi[MAXN],save[MAXN],ans[MAXN];
void dfs_pre(int v,int p,int d){
    sz[v]=1;
    st[v]=++stamp;
    rev[stamp]=v;
    dep[v]=d;
    for(int i=0;i<(int)G[v].size();i++){
        if(G[v][i]==p)continue;
        dfs_pre(G[v][i],v,d+1);
        sz[v]+=sz[G[v][i]];
    }
    ed[v]=stamp;
}
void dsutree(int v,int p,bool keep){
    int mx=-1,wson=-1;
    int t=-INF,id=-1;
    for(int i=0;i<(int)G[v].size();i++){
        int to=G[v][i];
        if(to==p) continue;
        if(sz[to]>mx) {mx=sz[to]; wson=to;}
    }
    for(int i=0;i<(int)G[v].size();i++){
        int to=G[v][i];
        if(to==p||to==wson) continue;
        dsutree(to,v,0);
    }
    if(wson!=-1) {dsutree(wson,v,1);t=maxi[wson];id=save[wson];}
    for(int i=0;i<(int)G[v].size();i++){
        int to=G[v][i];
        if(to==p||to==wson) continue;
        for(int j=st[to];j<=ed[to];j++){
            //add sth here
            int q=dep[rev[j]];
            cnt[q]++;
            if(cnt[q]>t||(cnt[q]==t&&q<id)) {t=cnt[q]; id=q;}
        }
            
    }
    //cnt[c[v]]++;
    //answer queries here
    /**************************/
    int q=dep[v];
    cnt[q]++;
    if(cnt[q]>t||(cnt[q]==t&&q<id)) {t=cnt[q];id=q;}
    ans[v]=id-dep[v];
    maxi[v]=t;save[v]=id;
    /*************************/
    if(!keep) {
        for(int j=st[v];j<=ed[v];j++){
            //del sth here
            int q=dep[rev[j]];
            cnt[q]--;
        }
            
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs_pre(1,0,0);
    dsutree(1,0,1);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}
