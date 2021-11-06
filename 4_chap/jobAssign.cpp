#include <iostream>

using namespace std;

int n;
int c[100][100]; //c[i][j]用以表示i号工人完成j号工作所需的费用。
int a[100]; //存储是否被分配，是就是1否就是0
int minprice=99999;
int price=0;
 
bool isAssign(int t){
	for(int i=0; i<t; i++){
        if(a[i]==a[t]){
            return false;
        }
    }
    return true;
}//查看是否被分配

void setAssign(int t){
	if(t==n){//为第t个人找工作
		if(price<minprice){
            minprice=price;
        }
		return;
	}
	for(int i=0; i<n; i++){
		a[t]=i;//给第t个人分配第i个工作
		price+=c[t][i];
		if(isAssign(t)){
            setAssign(t+1);
        }//循环检查每个工作是否已被分配，没有则分配给i号工人，否则检查下一个工作。
		price-=c[t][i];
	}//给定一个循环，从第1个工人开始循环分配工作，直到所有工人都分配到。
     //在工人循环结束后回到上一工人，取消此次分配的工作，而去分配下一工作直到可以分配为止。
}
 
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> c[i][j];
		}
	} 
	setAssign(0);
	cout << minprice << endl;
	return 0;
 } 