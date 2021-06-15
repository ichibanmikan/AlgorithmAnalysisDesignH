#ifndef ZOBEG
#define ZOBEG
#include <iostream>
#include <algorithm>
#include "nodes.h"

using namespace std;

class Knap : public Z-Obeg{
    private:
        int* bestx;
        nodes* X;
        int cv;
        int cw;
        int c;
        int n;
    public:
        bool cmp(nodes n1,nodes n2){
            return n1.d>n2.d;
        }

        Z-OBeg(int* w, int* v, int thec, int num){
            c=thec;
            n=num;
            cw=c;
            cv=0;
            X=new nodes [n];
            best=new int [n];
            for(int i=0; i<n; i++){
                X[i].w=w[i];
                X[i].v=v[i];
                X[i].no=i;
                X[i].setD(w[i], v[i]);
            }
            sort(X, X+n, cmp);
        }
        ~Z-OBeg(){}

        int maxKnapsack(){
             make_heap()
        }

        
};

#endif