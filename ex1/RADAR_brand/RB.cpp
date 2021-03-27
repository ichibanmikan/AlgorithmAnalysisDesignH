#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int* array1;
int* array2;
 
bool isRadar(int n){
    int k=0;
    while(n){
        array1[k++]=n%10;
        n/=10;
    }
    for(int i=0; i<=k/2; i++){
        if(array1[i]!=array1[k-i-1]){
            return false;
        }
    }
    return true;
}//判断满不满足回文数

void getSum(int &num){
    int k=0;
    int temp=num;
    while(temp){
        array2[k++]=temp%10;
        temp/=10;
    }
    long long sum=0;
    for(int i=0; i<k; i++){
        sum=sum*10+array2[i];
    }
    num=num+sum;
}//数据处理
int main(){
    int n,Case;
    array1=new int [105];
    array2=new int [105];
    while(cin >> n){
        int ans=0;
        while(!isRadar(n)){
            ans++;
            getSum(n);
        }
        cout << ans << " " << n << endl;
    }
    return 0;
}