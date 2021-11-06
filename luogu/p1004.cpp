#include <iostream>

using namespace std;

struct str{
    int x;
    int y;
};

void getM(int n, int** arrayM, int** arrayNum , str** arrayS){
    for (int i=0; i<=n; i++){
        arrayM[0][i]=0;
    }
    for (int j=0; j<=n; j++){
        arrayM[j][0]=0;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            arrayM[i][j]=arrayNum[i][j]+(arrayM[i-1][j]>arrayM[i][j-1]?arrayM[i-1][j]:arrayM[i][j-1]);
            arrayS[i][j].x=(arrayM[i-1][j]>arrayM[i][j-1]?i-1:i);
            if(arrayS[i][j].x==i){
                arrayS[i][j].y=j-1;
                continue;
            }
            arrayS[i][j].y=j;
        }
    }
    int k=n, l=n;
    while(true){
        if(arrayS[k][l].x==0||arrayS[k][l].x==0){
            break;
        }
        arrayNum[arrayS[k][l].x][arrayS[k][l].y]=0;
        cout << k << ' ' << l << endl;
        cout << arrayS[k][l].x << ' ' << arrayS[k][l].y << endl;
        cout << endl;
        k=arrayS[k][l].x;
        l=arrayS[k][l].y;
    }
    cout << "******************" << endl;
    arrayNum[n][n]=0;
    for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++){
            cout << arrayNum[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "*********************" << endl;
}

int main(){
    int n;
    cin >> n;
    int** arrayM=new int* [n+1];
    for (int i=0; i<=n; i++){
        arrayM[i]=new int [n+1];
    }
    int** arrayNum=new int* [n+1];
    str** arrayS=new str* [n+1];
    for (int i=0; i<n+1; i++){
        arrayNum[i]=new int [n+1];
        arrayS[i]=new str [n+1];
        for (int j=0; j<n+1; j++){
            arrayNum[i][j]=0;
        }
    }
    int x, y, num;
    while(true){
        cin >> x >> y >> num;
        if(x==0&&y==0&&num==0){
            break;
        }
        arrayNum[x][y]=num;
    }
    getM(n, arrayM, arrayNum, arrayS);
    int temp1=arrayM[n][n];
    getM(n, arrayM, arrayNum, arrayS);
    cout << temp1+arrayM[n][n];
    return 0;
} //FDU CX