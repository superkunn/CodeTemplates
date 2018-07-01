#include <bits/stdc++.h>
using namespace std;
const int MAXV=1e4+5;
const int MAXE=1e6+5;
const int INF=1e9;
struct edge{int to,cost;};
typedef pair<int,int> P;
int V;
vector<edge> G[MAXV];
int d[MAXV];
bool inque[MAXV];
queue<int> que;
void spfa(int s){
    fill(d,d+V,INF);
    fill(inque,inque+V,false);
    d[s]=0;
    while(!que.empty()) que.pop();
    que.push(s);
    inque[s]=true;
    while(!que.empty()){
        int u=que.front();
        inque[u]=false;
        que.pop();
        for(int i=0;i<G[u].size();i++){
            edge e=G[u][i];
            if(d[u]+e.cost<d[e.to]){
                d[e.to]=d[u]+e.cost;
                if(!inque[e.to]){
                    inque[e.to]=true;
                    que.push(e.to);
                }
            }
        }
    }
}
int main(){
    return 0;
}
