#ifndef NODEH
#define NODEH

class nodes{
    public:
        // double d;
        int cv;
        int cw;
        int no;
        double bound;
        int* x1, x0, xu;
        int t;

        nodes(){
            d=0.0;
            cv=0;
            cw=0;
            bound=0.0;
            t=0;
            no=0;
        } 

        nodes(int n, int v, int w, int fl, int* s1, int* s2, int* s3){
            x1=new int [n];
            x0=new int [n];
            xu=new int [n];
            for(int i=0; i<n; i++){
                x1[i]=s1[i];
                x0[i]=s2[i];
                xu[i]=s3[i];
            }
            cv=v;
            cw=w;
            no=fl;
            bound=0.0;
            t=1;
        }
        void setBound(double d){
            bound=d;
        }
};

#endif