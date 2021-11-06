#ifndef NQUEENS
#define NQUEENS
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

class nQueens{
    private:
        int n;
        int* x;
        int** bestX;
        int bestn;
    public:

        long long getFac(int n){
            if(n==2){
                return 2;
            }
            return n*getFac(n-1);
        }

        nQueens(int num){
            n=num;
            x=new int [num];
            for(int i=0; i<n; i++){
                x[i]=i;
            }
            long long temp=getFac(num);
            bestX=new int* [temp];
            for(int i=0; i<temp; i++){
                bestX[i]=new int [num];
            }
            bestn=0;
        }

        bool isCut(int i){
            for(int j=0; j<i; j++){
                if((x[i]==x[j]||(abs(i-j)==abs(x[i]-x[j])))){
                    return true;
                }
            }
            return false;
        }

        void backtrace(int i){
            if(i==n){
                for(int j=0; j<n; j++){
                    bestX[bestn][j]=x[j];
                }
                bestn++;
                return ;
            }
            for(int j=0; j<n; j++){
                x[i]=j;
                if(!isCut(i)){
                    backtrace(i+1);
                }
            }
        }

        void printHelp(){
            ofstream outfile("out.txt");
            outfile << bestn << endl;
            for(int i=0; i<bestn; i++){
                for(int j=0; j<n; j++){
                    outfile << bestX[i][j] << ' ';
                }
                outfile << endl;
            }
        }
};

#endif