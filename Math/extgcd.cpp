#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll extgcd(ll a,ll b,ll &x,ll &y){
    ll d=a;
    if(b!=0){
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else{
        x=1;
        y=0;
    }
    return d;
}
ll a,b,x,y;
int main(){
    while(cin>>a>>b){
        if(extgcd(a,b,x,y)==1){
            while(x<0){
                x+=b;
                y-=a;
            }
            cout<<x<<" "<<y<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

