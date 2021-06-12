#ifndef FLOWSHOP
#define FLOWSHOP
#define inf 0x7FFFFFFF;
#include <iostream>

using namespace std;

class flowShop{
    private:
        int** T;
        int* x;
        int* bestx;
        int* t2;
        int t1;
        int t;
        int bestt;
        int n;
    public:
        flowShop(int** arrayT, int num){
            n=num;
            T=new int* [n];
            for(int i=0; i<n; i++){
                T[i]=new int [2];
                T[i][0]=arrayT[i][0];
                T[i][1]=arrayT[i][1];
            }
            t2=new int [n];
            for(int i=0; i<n; i++){
                t2[i]=0;
            }
            t1=0;
            t=0;
            bestt=inf;
            x=new int [n];
            for(int i=0; i<n; i++){
                x[i]=i;
            }
            bestx=new int [n];
        }

        void backtrace(int i){
            if(i==n){
                for(int j=0; j<n; j++){
                    bestx[j]=x[j];
                }
                bestt=t;
                return ;
            }
            for(int j=i; j<n; j++){
                t1+=T[x[j]][0];
                t2[i]=(i>0?(t2[i-1]>t1?t2[i-1]:t1):t1)+T[x[j]][1];
                t+=t2[i];
                if(t<bestt){
                    Swap(x[j], x[i]);
                    backtrace(i+1);
                    Swap(x[j], x[i]);
                }
                t1-=T[x[j]][0];
                t-=t2[i];
            }
        }

        void Swap(int &a, int &b){
            int temp=a;
            a=b;
            b=temp;
        }

        void printHelp(){
            cout << bestt << endl;
            for(int i=0; i<n; i++){
                cout << bestx[i] << ' ';
            }
            cout << endl;
        }
};

#endif