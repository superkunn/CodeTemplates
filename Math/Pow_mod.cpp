#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll pow_mod(ll a,ll i){
    ll ret=1;
    while(i>0){
        if(i&1)ret=ret*a%MOD;
        a=a*a%MOD;
        i>>=1;
    }
    return ret;
}
int main(){
    cout<<pow_mod(2,4)<<endl;
    return 0;
}
