#ifndef ASSIGN
#define ASSIGN
#include <algorithm>
#include "nodes.h"
#include <fstream>
#define inf 0x99999

using namespace std;

class getResult : public node{
    private:
        int* t;
        int n;
        int k;
        node* arrayN;
    public:
        getResult(int then, int thek, int* arrayT){
            n=then;
            k=thek;
            t=new int [n+5];
            for(int i=0; i<n; i++){
                t[i]=arrayT[i];
            }
            arrayN=new node [inf];
        }

        void printHelp(){
            node* nt=new node [5];
            for(int i=0; i<5; i++){
                cout << nt[i].no << ' ' << nt[i].bound << ' ' << nt[i].numk << endl;
            }
        }

        int minTime(){
            int num=0;
            int* thek=new int [k];
            for(int i=0; i<k; i++){
                thek[i]=0;
            }
            node n0(0, 0, k, thek);
            arrayN[num]=n0;
            make_heap(arrayN, arrayN+1);
            int tm=1;
            while(true){
                node nd_top=arrayN[0];
                // pop_heap(arrayN, arrayN+inf, cmp);
                if(nd_top.no==n){
                    return nd_top.bound;
                }
                num++;
                for(int i=0; i<k; i++){
                    // node nd_temp(k);
                    tm++;
                    int* mctTemp=new int [k];
                    for(int j=0; j<k; j++){
                        mctTemp[j]=nd_top.mct[j];
                    }
                    mctTemp[i]+=t[nd_top.no];
                    node nd_temp(nd_top.no+1, i, k, mctTemp);
                    arrayN[num+i]=nd_temp;
                    // mct[i]-=t[nd_top.no];
                }
                num+=k-1;
                node ndUnused;
                pop_heap(arrayN, arrayN+tm);
                arrayN[tm-1]=ndUnused;
                make_heap(arrayN, arrayN+tm);
                tm++;
            }
        }
};

# endif