//poj 3041
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int MAXV=1e3+5;//!!!
struct BM{
    int V;
    vector<int> G[MAXV];
    int match[MAXV];
    bool used[MAXV];
    void init(int x){
        V=x;
        for(int i=0;i<=MAXV;i++){
            G[i].clear();
        }
    }
    void add_edge(int u,int v){
        G[u].push_back(v);G[v].push_back(u);
    }
    bool dfs(int v){
        used[v]=true;
        for(int i=0;i<G[v].size();i++){
            int u=G[v][i],w=match[u];
            if(w<0||!used[w]&&dfs(w)){
                match[v]=u;match[u]=v;
                return true;
            }
        }
        return false;
    }
    int matching(){
        int res=0;
        memset(match,-1,sizeof(match));
        for(int i=1;i<=V;i++){
            if(match[i]<0){
                memset(used,0,sizeof(used));
                if(dfs(i))res++;
            }
        }
        return res;
    }
}bm;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    bm.init(2*n);
    while(k--){
        int x,y;
        scanf("%d%d",&x,&y);
        bm.add_edge(x,y+n);
    }
    printf("%d\n",bm.matching());
    return 0;
}
