#include <cmath>
#include <iostream>

using namespace std;

bool isConed(int targetx, int targety, int x, int y){
    if((abs(targetx-x)==2&&abs(targety-y)==1)||(abs(targety-y)==2&&abs(targetx-x)==1)){
        return true;
    }
    return false;
}

void getM(int m, int n, int x, int y, long long** arrayM){
    int tempi=0;
    for (int i=0; i<m; i++){
        if(isConed(0, i, x, y)||(y==i&&x==0)){
            tempi=i;
            arrayM[0][i]=-1;
            break;
        }
        tempi=i;
        arrayM[0][i]=1;
    }
    for (int i=tempi+1; i<m; i++){
        arrayM[0][i]=-1;
    }
    int tempj=0;
    for (int j=0; j<n; j++){
        if(isConed(j, 0, x, y)||(j==x&&y==0)){
            tempj=j;
            arrayM[j][0]=-1;
            break;
        }
        tempj=j;
        arrayM[j][0]=1;
    }
    for (int j=tempj+1; j<n; j++){
        arrayM[j][0]=-1;
    }
    for (int i=1; i<n; i++){
        for (int j=1; j<m; j++){
            if(isConed(i, j, x, y)||(arrayM[i-1][j]==-1&&arrayM[i][j-1]==-1)||(i==x&&j==y)){
                arrayM[i][j]=-1;
                continue;
            }
            if(arrayM[i][j-1]==-1){
                arrayM[i][j]=arrayM[i-1][j];
                continue;
            }
            if(arrayM[i-1][j]==-1){
                arrayM[i][j]=arrayM[i][j-1];
                continue;
            }
            arrayM[i][j]=(arrayM[i-1][j]+arrayM[i][j-1]);
        }
    }
}

int main(){
    int m, n, x, y;
    cin >> n >> m >> x >> y;
    long long** arrayM=new long long* [n+1];
    for (int i=0; i<=n; i++){
        arrayM[i]=new long long [m+1];
    }
    getM(m+1, n+1, x, y, arrayM);
    if(arrayM[n][m]!=-1){
        cout << arrayM[n][m] << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}