#include <bits/stdc++.h>
using namespace std;
const int MAXV=1e4+5;
const int MAXE=1e6+5;
const int INF=1e9;
struct edge{int from,to,cost;};
edge es[MAXE];
int d[MAXV];
int V,E;
void bellman_ford(int s)
{
    for(int i=1;i<=V;i++) d[i]=INF;
    d[s]=0;
    while(true)
    {
        bool update=false;
        for(int i=1;i<=E;i++)
        {
            edge e=es[i];
            if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost)
            {
                d[e.to]=d[e.from]+e.cost;
                update=true;
            }
        }
        if(!update) break;
    }
}

int main(){
    return 0;
}