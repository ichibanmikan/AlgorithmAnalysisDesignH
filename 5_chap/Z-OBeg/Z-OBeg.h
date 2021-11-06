#ifndef ZOBEG
#define ZOBEG
#include <algorithm>
#include <iostream>

using namespace std;

struct st{
    double arvg;
    int no;
};

bool cmp(st s1, st s2){
    return s1.arvg>s2.arvg;
}

class knap{
    private:
        int n;
        int c;
        int *w;
        int *v;
        int cw;
        int cv;
        int r;
        int bestv;
        int* result;
    public:
        knap(int num, int thec, int* arrayw, int* arrayv){
            n=num;
            c=thec;
            cw=0;
            cv=0;
            // w=arrayw;
            // v=arrayv;
            w=new int [num];
            v=new int [num];
            result=new int [num];
            bestv=0;
            st* arrayT=new st [num+5];
            for(int i=0; i<num; i++){
                arrayT[i].no=i;
                arrayT[i].arvg=((double)arrayv[i]/(double)arrayw[i]);
            }
            sort(arrayT, arrayT+num, cmp);
            for(int i=0; i<num; i++){
                w[i]=arrayw[arrayT[i].no];
                v[i]=arrayv[arrayT[i].no];
            }
        }

        double getBound(int i){
            double tempc=(double)(c-cw);
            double bound=0;
            int tempj=i;
            for(int j=i; j<n; j++){
                if(tempc-w[j]>=0){
                    tempc-=w[j];
                    bound+=v[j];
                    tempj=j;
                } else {
                    break;
                }
            }
            if(tempj+1<n){
                bound+=(tempc/(double)w[tempj+1])*v[tempj+1];
            }
            if(tempj+1==n){
                if(w[tempj]<tempc){
                    bound+=v[tempj];
                }
            }
            return bound;
        }

        void backtrace(int i){
            // cout << i << ' ' << getBound(i) << endl;
            if(i==n){
                for(int j=0; j<n; j++){
                    cout << result[j] << ' ';
                }
                cout << endl;
                cout << bestv << ' ' << cv << endl;
                bestv=cv;
                return ;
            }
            if(cw+w[i]<=c){
                // cout << bestv << ' ' << cv << endl;
                result[i]=1;
                cw+=w[i];
                cv+=v[i];
                backtrace(i+1);
                cw-=w[i];
                cv-=v[i];
                result[i]=-1;
            }
            if((double)cv+getBound(i+1)>(double)bestv){
                result[i]=0;
                backtrace(i+1);
            }
        }

        int getBestv(){
            return bestv;
        }

        void printHelp(){
            for(int i=0; i<n; i++){
                cout << w[i] << ' ';
            }
            cout << endl;
            for(int i=0; i<n; i++){
                cout << v[i] << ' ';
            }
            cout << endl;
        }
};

#endif