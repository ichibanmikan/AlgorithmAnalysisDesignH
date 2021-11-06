#ifndef GETRESULT
#define FETRESULT
#include <queue>

using namespace std;

class nQueens{
    private:
        int* x;
        // int* bestX;
        // int numRe;
        int n;
    public:
        nQueens(int num){
            n=num;
            x=new int [n];
            for(int i=0; i<n; i++){
                x[i]=i;
            }
        }

        void getResult(){
            queue liveNode<int>;
            int t=0;
            for(int i=0; i<n; i++){
                for(int j=t; j++; j<n){
                    
                }
                t++;
            }
        }
};

#endif