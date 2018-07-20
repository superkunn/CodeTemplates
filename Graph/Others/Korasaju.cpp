//hdu 1269
#include<bits/stdc++.h>
using namespace std;
const int MAXV=1e4+5;
int V;
vector<int> G[MAXV];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV];
int Belong[MAXV];
void init(int x){
    V=x;
    for(int i=0;i<MAXV;i++){
        G[i].clear();
        rG[i].clear();
    }   
}
void add_edge(int u,int v){
    G[u].push_back(v);
    rG[v].push_back(u);
}
void dfs(int v){
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k){
    used[v]=true;
    Belong[v]=k;
    for(int i=0;i<rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=V;v++){//from 1 to V
        if(!used[v]) dfs(v);
    }
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--){
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        init(n);
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add_edge(x,y);
        }
        printf("%s\n",scc()==1?"Yes":"No");
    }
    return 0;
}
