#ifndef NODEH
#define NODEH

class nodes{
    public:
        int w;
        int v;
        int no;
        double d;
        nodes(){
            w=0;
            v=0;
            d=0.0;
        }
        nodes(int a, int b){
            w=a;
            v=b;
            d=((double)b/(double)a);
        }
        ~nodes(){}
        void setD(int a, int b){
            d=((double)b/(double)a);
        }
};

#endif