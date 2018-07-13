#include<bits/stdc++.h>
using namespace std;
int fac[10]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int cantor(string s,int n){
    int x=1;
    for(int i=0;i<n;i++){
        int smaller=0; // 在当前位之后小于其的个数
        for(int j=i+1;j<n;j++){
            if(s[j]<s[i])smaller++;// 康托展开累加
        }
        x+=fac[n-i-1]*smaller;
    }
    return x;// 康托展开值
}
string decantor(int k,int n){
    string s="";
    k--;
    int i,j,t,vis[10]={0};
    for(i=0;i<n;i++){
        t=k/fac[n-i-1];
        for(j=1;j<=n;j++){
            if(!vis[j]){
                if(t==0)break;
                t--;
            }
        }
        s+=char('0'+j);
        vis[j]=1;
        k%=fac[n-i-1];
    }
    return s;
}
int main(){
    cout<<decantor(88,7)<<endl;
    cout<<cantor("1265473",7)<<endl;
    return 0; 
}
