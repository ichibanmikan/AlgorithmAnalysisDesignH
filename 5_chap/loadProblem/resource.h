#ifndef RESOURCE
#define RESOURCE
#include <iostream>

using namespace std;

class loading{
    private:
        int n;
        int* w;
        int c;
        int cw;
        int bestw;
        int r;
    public:
        loading(){}
        loading(int num, int* arrayw, int thec){
            n=num;
            w=arrayw;
            c=thec;
            cw=0;
            bestw=0;
            r=c;
        }
        void backtrace(int i){
            cout << bestw << ' ' << i  << endl;
            if(i>=n){
                bestw=cw;
                return ;
            }
            r-=w[i];
            if(cw+w[i]<=c){
                cw+=w[i];
                backtrace(i+1);
                cw-=w[i];
            }
            if(cw+r>bestw){
                backtrace(i+1);
            }
            r+=w[i];
        }
        int getbestW(){
            return bestw;
        }
};

#endif