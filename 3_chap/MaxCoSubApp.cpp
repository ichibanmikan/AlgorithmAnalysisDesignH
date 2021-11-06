#include <iostream>

using namespace std;

void getLeWays(char* arrayB, char* arrayA, int** reB, int** reS,  int n, int m){
    for (int j=0; j<m+1; j++){
        reS[0][j]=0;
    }
    for (int j=0; j<n+1; j++){
        reS[j][0]=0;
    }
    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            if(arrayA[i]!=arrayB[j]){
                if(reS[i-1][j]>=reS[i][j-1]){
                    reS[i][j]=reS[i-1][j];
                    reB[i][j]=1;
                }
                else{
                    reS[i][j]=reS[i][j-1];
                    reB[i][j]=2;
                }
            }//1 2
            if(arrayA[i]==arrayB[j]){
                reS[i][j]=reS[i-1][j-1]+1;
                reB[i][j]=3;
            }//3
        }
    }
}

void printHelp(int** reB, int x, int y, char* arrayA){
    if(x==0||y==0){
        return ;
    }
    if(reB[x][y]==3){
        printHelp(reB, x-1, y-1, arrayA);
        cout << arrayA[x] << ' ';
    }
    if(reB[x][y]==1){
        printHelp(reB, x-1, y, arrayA);
    }
    if(reB[x][y]==2){
        printHelp(reB, x, y-1, arrayA);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    char* arrayA=new char [n+1];
    char* arrayB=new char [m+1];
    int** reS;
    int** reB;
    reS=new int* [n+1];
    reB=new int* [n+1];
    for (int i=0; i<n+1; i++){
        reS[i]=new int [m+1];
        reB[i]=new int [m+1];
    }
    for (int i=1; i<n+1; i++){
        cin >> arrayA[i];
    }
    for (int j=1; j<m+1; j++){
        cin >> arrayB[j];
    }
    getLeWays(arrayB, arrayA, reB, reS, n, m);
    printHelp(reB, m, n, arrayA);
    return 0;
}