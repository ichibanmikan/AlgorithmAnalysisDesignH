#include<iostream>

#define loop(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

const int MAXN = 50012;
const int Inf  = 0x7ff;
int n,a[MAXN],cnt[MAXN];

int findPos(int val,int x,int y){
    if(x>=y) return x;
    else{
        for(int m;m=(x+y)/2,x<y;){
            if(val>cnt[m]) x=m+1;
            else y=m;
        }
        return x;
    }
}
bool scanf(int & val){
    char cin=getchar();
    if(cin==EOF) return false;
    else{
        val=0;
        while('0'>cin||cin>'9') cin=getchar();
        while('0'<=cin&&cin<='9') val*=10,val+=(cin-'0'),cin=getchar();
        return true;
    }
}
int main(){
    while(scanf(n)){
        cnt[0]=1; cnt[1]=-Inf;
        loop(i,1,n) scanf(a[i]);
        loop(i,1,n){
            if(a[i]>cnt[cnt[0]]) cnt[++cnt[0]]=a[i];
            else{
                int j=findPos(a[i],2,cnt[0]);
                if(a[i]<cnt[j]) cnt[j]=a[i];
            }
        }
        printf("%d\n",cnt[0]-1);
    }
    return 0;
}