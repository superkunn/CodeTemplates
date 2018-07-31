//poj 3461
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=2e6;
void kmp_pre(char p[],int plen,int nxt[]){
    int i=0;
    int j=nxt[0]=-1;
    while(i<plen){
        while(j!=-1&&p[i]!=p[j])j=nxt[j];
        if(p[++i]==p[++j])nxt[i]=nxt[j];
        else nxt[i]=j;
    }
}
int nxt[MAXN];
int kmp_count(char p[],int plen,char t[],int tlen){
    int i=0,j=0,ans=0;
    kmp_pre(p,plen,nxt);
    while(i<tlen){
        while(j!=-1&&t[i]!=p[j])j=nxt[j];
        i++;j++;
        if(j>=plen){
            ans++;
            j=nxt[j];
        }
    }
    return ans;
}
char a[MAXN];
char b[MAXN];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",&a,&b);
        printf("%d\n",kmp_count(a,strlen(a),b,strlen(b)));
    }
    return 0;
}
