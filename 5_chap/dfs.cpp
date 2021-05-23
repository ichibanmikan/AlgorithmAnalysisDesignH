#include <iostream>

using namespace std;

class edge{
    public:
        int weight;
        int noNext;
        edge* nextEdge;
        edge(){}
};

class node : public edge{
    public:
        int no;
        edge* next;
        node(){}
        setEdge(int n, int w){
            
        }
};

class Graph : public node{
    public:
        node* Graph;
        Graph(int n, int** G){
            Graph=new node [n];
            for (int i=0; i<n; i++){
                Graph[i].no=i;
                for (int j=0; j<n; j++){
                    if(G[i][j]!=0){
                        edge e
                    }
                }
            }
        }  
};

int main(){

    return 0;
}