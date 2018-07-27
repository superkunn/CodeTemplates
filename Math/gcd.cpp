//Aizu 0005
#include<cstdio>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}
int main(){
    long long a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF){
        printf("%lld %lld\n",gcd(a,b),a/gcd(a,b)*b);
    }
    return 0;
}
