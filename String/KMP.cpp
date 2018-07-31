//poj 3461
#include<cstdio>
#include<cstring>
using namespace std;
void kmp_pre(char x[],int xlen,int nxt[]){
    int i,j;
    j=nxt[0]=-1;
    i=0;
    while(i<xlen){
        while(j!=-1&&x[i]!=x[j])j=nxt[j];
        nxt[++i]=++j;
    }
}
int nxt[2000000];
int kmp_count(char x[],int xlen,char y[],int ylen){
    int i,j;
    int ans=0;
    kmp_pre(x,xlen,nxt);
    i=j=0;
    while(i<ylen){
        while(-1!=j&&y[i]!=x[j])j=nxt[j];
        i++;j++;
        if(j>=xlen){
            ans++;
            j=nxt[j]; 
        }
    }
    return ans;
}
char a[2000000];
char b[2000000];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",&a,&b);
        printf("%d\n",kmp_count(a,strlen(a),b,strlen(b)));
    }
    return 0;
}
