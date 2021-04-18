#include <iostream>
#define inf 9999999

using namespace std;

void getMinWays(int *arrayMat, int** reB, int** reS, int k){
    for (int i=0; i<k; i++){
        reS[i][i]=0;
        reB[i][i]=-1;
    }
    for (int i=1; i<k; i++){
        for (int j=0; j<k-i; j++){
            //array[j][j+i] 0 1
            int temps=inf;
            int tempb;
            for (int l=j; l<j+i; l++){
                if(reS[j][l]+reS[l+1][j+i]+arrayMat[j]*arrayMat[l+1]*arrayMat[j+i+1]<temps){
                    temps=reS[j][l]+reS[l+1][j+i]+arrayMat[j]*arrayMat[l+1]*arrayMat[j+i+1];
                    tempb=l;
                }
            }
            reS[j][j+i]=temps;
            reB[j][j+i]=tempb;
        }
    }
}

void printHelp(int i, int j, int** reB){
    if(i==j){
        return ;
    }
    printHelp(i, reB[i][j], reB);
    printHelp(reB[i][j]+1, j, reB);
    cout << i << ' ' << reB[i][j] << endl;
    cout << reB[i][j]+1 << ' ' << j << endl;
}

int main(){
    int k;
    cin >> k;
    int *arrayMat=new int [k+1];
    for (int i=0; i<k+1; i++){
        cin >> arrayMat[i];
    }
    int** reS;
    int** reB;
    reS=new int* [k];
    reB=new int* [k];
    for (int i=0; i<k; i++){
        reS[i]=new int [k];
        reB[i]=new int [k];
    }
    getMinWays(arrayMat, reB, reS, k);
    printHelp(0, k-1, reB);
    return 0;
}