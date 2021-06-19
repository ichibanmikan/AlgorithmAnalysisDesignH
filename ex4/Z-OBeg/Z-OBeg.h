#ifndef ZOBEG
#define ZOBEG
#include <iostream>
#include <algorithm>
#include "nodes.h"
#include <cmath>

using namespace std;

class Knap : public nodes{
    private:
        // int* bestx;
        int* w;
        int* v;
        int n;
        int c;
    public:
        // bool cmp(nodes n1,nodes n2){
        //     if(n1.bound!=n2.bound){
        //         return n1.bound>n2.bound;
        //     }
        //     return n1.t>n2.t;
        // }

        Knap(int* thew, int* thev, int thec, int num){
            c=thec;
            n=num;
            w=new int [n];
            v=new int [n];
            // bestx=new int [n];
            for(int i=0; i<n; i++){
                w[i]=thew[i];
                v[i]=thev[i];
            }
        }
        ~Knap(){}

        int maxKnapsack(){
            // int i=0;
            int* s0=new int [n];
            int* s1=new int [n];
            int* su=new int [n];
            for(int j=0; j<n; j++){
                su[j]=j;
            }
            nodes nd0(n, 0, c, 0, s1, s0, su, 0, 0, n);
            nd0.setBound(getBound(nd0));
            int size=(int)pow(2, n+1);
            nodes* arrayNds=new nodes [size];
            make_heap(arrayNds, arrayNds+size);
            arrayNds[0]=nd0;
            int num=0;
            while(true){
                nodes ndtop=arrayNds[0];
                // cout << ndtop.bound << endl;
                // printf("%lf\n", ndtop.bound);
                if(ndtop.no==n+1){
                    printf("不能放入背包的是：");
                    for(int i=0; i<ndtop.numx0; i++){
                        // cout << ndtop.x0[i] << ' ';
                        // (ndtop.x0[i]<n)?(printf("不能放入背包的是：%d ", ndtop.x0[i])):;
                        if(ndtop.x0[i]<n){
                            printf("%d ", ndtop.x0[i]);
                        }
                    }
                    printf("\n");
                    printf("允许放入背包的是：");
                    for(int i=0; i<ndtop.numx1; i++){
                        // cout << ndtop.x1[i] << ' '; 
                        // (ndtop.x1[i]<n)?(printf("允许放入背包的是：%d ", ndtop.x1[i])):;
                        if(ndtop.x1[i]<n){
                            printf("%d ", ndtop.x1[i]);
                        }
                    }
                    printf("\n");
                    return ndtop.cv;
                }
                if(ndtop.cw-w[ndtop.no]>=0){
                    num++;
                    int* temp1=new int [n];
                    int* tempu=new int [n];                   
                    for(int i=0; i<ndtop.numx1; i++){
                        temp1[i]=ndtop.x1[i];
                    }
                    temp1[ndtop.numx1]=ndtop.no;
                    for(int i=1; i<ndtop.numxu; i++){
                        tempu[i-1]=ndtop.xu[i];
                    }
                    nodes nd_1(n, ndtop.cv+v[ndtop.no], ndtop.cw-w[ndtop.no], ndtop.no+1, temp1, ndtop.x0, tempu, ndtop.numx1+1, ndtop.numx0, ndtop.numxu-1);
                    nd_1.setBound(getBound(nd_1));
                    arrayNds[num]=nd_1;
                }
                num++;
                int* temp0=new int [n];
                int* tempu_2=new int [n];                   
                for(int i=0; i<ndtop.numx0; i++){
                    temp0[i]=ndtop.x0[i];
                }
                temp0[ndtop.numx0]=ndtop.no;
                for(int i=1; i<ndtop.numxu; i++){
                    tempu_2[i-1]=ndtop.xu[i];
                }                
                nodes nd_0(n, ndtop.cv, ndtop.cw, ndtop.no+1, ndtop.x1, temp0, tempu_2, ndtop.numx1, ndtop.numx0+1, ndtop.numxu-1);
                nd_0.setBound(getBound(nd_0));
                arrayNds[num]=nd_0;
                pop_heap(arrayNds, arrayNds+size);
                nodes ndTemp;
                arrayNds[size-1]=ndTemp;
                make_heap(arrayNds, arrayNds+size);
            }
        }

        double getBound(nodes nd){
            double d=0.0;
            d+=nd.cv;
            int tempw=nd.cw;
            int tempi;
            for(int i=0; i<nd.numxu; i++){
                if(tempw-w[nd.xu[i]]>=0){
                    d+=v[nd.xu[i]];
                    tempw-=w[nd.xu[i]];
                } else {
                    tempi=nd.xu[i];
                    break;
                }
            }
            if(nd.numxu>0){
                d+=((double)tempw)*(((double)v[tempi])/((double)w[tempi]));
            }
            return d;
        }
};

#endif

//思想出来了，但是遇到了存储状态的数组难以尾插和去头的问题，可以换成vector，可惜换不得(懒得换)
//不过好像也不需要状态数组