#ifndef NODES
#define NODES

class nodes{
    public:
        int row;
        int col;
        nodes(){
            row=0;
            col=0;
        }
        nodes(int a, int b){
            row=a;
            col=b;
        }
        ~nodes(){}
};

#endif