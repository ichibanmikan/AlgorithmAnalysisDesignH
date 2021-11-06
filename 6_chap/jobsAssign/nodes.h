#ifndef NODES
#define NODES

class node{
    public:
        int no;
        int bound;
        int numk;
        int isFirst;
        int k;
        int* mct;

        node(){
            no=0;
            bound=0;
            numk=0;
            isFirst=0;
            k=0;
        }

        node(int thek){
            no=0;
            bound=0;
            numk=0;
            isFirst=0;
            k=thek;
            mct=new int [k];
        }

        node(int n, int thisk, int thek, int* themct){
            isFirst=1;
            no=n;
            numk=thisk;
            // bound=b;
            k=thek;
            mct=new int [k];
            for(int i=0; i<k; i++){
                mct[i]=themct[i];
            }
            bound=getBound();
        }

        int getBound(){
            int temp=0;
            for(int i=0; i<k; i++){
                if(mct[i]>temp){
                    temp=mct[i];
                }
            }
            return temp;            
        }

        bool operator <(node ndOther){
            if(isFirst!=ndOther.isFirst){
                return isFirst<ndOther.isFirst;
            }
            if(bound!=ndOther.bound){
                return bound>ndOther.bound;
            }
            return numk>ndOther.numk;
        }
};

#endif