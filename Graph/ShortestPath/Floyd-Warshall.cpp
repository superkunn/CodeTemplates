#include <bits/stdc++.h>
using namespace std;
const int MAXV=1e4+5;
const int MAXE=1e6+5;
const int INF=1e9;
int d[MAXV][MAXV];
int v;
void floyd_warshall(){
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main(){
    return 0;
}
