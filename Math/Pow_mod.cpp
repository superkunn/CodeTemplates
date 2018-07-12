#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow_mod(ll a,ll i,ll mod){
    ll res=1;
    while(i>0){
        if(i&1)res=res*a%mod;
        a=a*a%mod;
        i>>=1;
    }
    return res;
}
int main(){
    return 0;
}
