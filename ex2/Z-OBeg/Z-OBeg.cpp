#include <iostream>
#include <fstream>

using namespace std;

ifstream infile("input.txt");
ofstream outfile("output.txt");
void zoBeg(int n, int c, int* w, int* v, int** m){
    for (int i=0; i<=c; i++){
        if(w[0]>i){
            m[0][i]=0;
            continue;
        }
        m[0][i]=v[0];
    }
    for (int j=0; j<n; j++){
        m[j][0]=0;
    }
    for (int j=1; j<=c; j++){
        for (int i=1; i<n; i++){
            if(w[i]>j){
                m[i][j]=m[i-1][j];
            }
            if(w[i]<=j){
                m[i][j]=m[i-1][j]>m[i-1][j-w[i]]+v[i]?m[i-1][j]:m[i-1][j-w[i]]+v[i];
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<=c; j++){
            outfile << m[i][j] << ' ';
        }
        outfile << endl;
    }
    outfile << m[n-1][c] << endl;
}

int main(){
    int n, c;
    infile >> n >> c;
    int* arrayW=new int [n];
    int* arrayV=new int [n];
    for (int i=0; i<n; i++){
        infile >> arrayW[i] >> arrayV[i];
    }
    int** arrayM=new int* [n];
    for (int i=0; i<n; i++){
        arrayM[i]=new int [c+1];
    }
    zoBeg(n, c, arrayW, arrayV, arrayM);
    return 0;
}//0-1背包问题