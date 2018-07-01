//sgu 217
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double r1, r2; 
double f(double x){
    return sqrt((r1*r1-x*x)*(r2*r2-x*x));//写要求辛普森积分的函数
} 
double simpson(double L, double R){//三点辛普森积分法，要求f(x)是全局函数
    double mid = (L + R) / 2.0;
    return (f(L) + 4.0 * f(mid) + f(R)) * (R - L) / 6.0;
}
double integral(double L, double R, double Eps){//自适应辛普森积分递归过程
    double mid = (L + R) / 2.0;
    double ST = simpson(L, R), SL = simpson(L, mid), SR = simpson(mid, R);
    if(fabs(SL + SR - ST) <= 15.0 * Eps)  return SL + SR + (SL + SR - ST) / 15.0;//直接返回结果
    return integral(L, mid, Eps/2.0) + integral(mid, R, Eps/2.0);//对半划分区间
}
int main(){
    cin>>r1>>r2;
    printf("%lf",integral(0,min(r1,r2),1e-4)*8);//精度
    return 0;
}
