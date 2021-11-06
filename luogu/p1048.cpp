#include <iostream>

using namespace std;

void getM(int m, int n, int** arrayM, int* time, int* value){
	for (int i=0; i<=m; i++){
		arrayM[i][0]=0;
	}
	for (int j=0; j<=n; j++){
		arrayM[0][j]=0;
	}
	for (int j=1; j<=n; j++){
		for (int i=1; i<=m; i++){
			if(time[j]>i){
				arrayM[i][j]=arrayM[i][j-1];
				continue;
			}
			arrayM[i][j]=arrayM[i][j-1]>(arrayM[i-time[j]][j-1]+value[j])?arrayM[i][j-1]:(arrayM[i-time[j]][j-1]+value[j]);
		}
	}
//	for (int i=0; i<=m; i++){
//		for (int j=0; j<=n; j++){
//			cout << arrayM[i][j] << ' ';
//		}
//		cout << endl;
//	}
}

int main(){
	int allTime, n;
	cin >> allTime >> n;
	int* time=new int [n+1];
	int* value=new int [n+1];
	for (int i=1; i<=n; i++){
		cin >> time[i] >> value[i];
	}
	int** arrayM=new int* [allTime+1];
	for (int i=0; i<=allTime; i++){
		arrayM[i]=new int [n+1];
	}
	getM(allTime, n, arrayM, time, value);
	cout << arrayM[allTime][n];
	return 0;
} 
