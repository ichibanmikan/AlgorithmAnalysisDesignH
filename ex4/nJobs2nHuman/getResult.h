#ifndef GETRESULT
#define GETRESULT

class assign{
    private:
        int n;
        int minC;
        int** arrayC;
        int sum;
        bool* isAssigned;
    public:
        assign(int num, int** c){
            n=num;
            arrayC=new int* [n];
            sum=0;
            isAssigned=new bool [n];
            for(int i=0; i<n; i++){
                isAssigned[i]=0;
                arrayC[i]=new int [n];
                for(int j=0; j<n; j++){
                    arrayC[i][j]=c[i][j];
                }
            }
            minC=0x7FFFFFFF;
        }

        void backtrace(int i){
            if(i==n){
                if(minC>sum){
                    minC=sum;
                    return ;
                }
            }
            for(int j=0; j<n; j++){
                if(!isAssigned[j]){
                    isAssigned[j]=1;
                    sum+=arrayC[i][j];
                    if(sum<minC){
                       backtrace(i+1);
                    }
                    isAssigned[j]=0;
                    sum-=arrayC[i][j];
                }
            }
        }

        int getMinC(){
            return minC;
        }
};

#endif