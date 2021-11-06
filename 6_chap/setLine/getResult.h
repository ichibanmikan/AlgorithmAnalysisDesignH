#ifndef RESULT
#define RESULT
#include "nodes.h"
#include <iostream>
#include <fstream>
#include <queue>
#define inf 9999

using namespace std;

class findPath : public nodes{
    private:
        nodes start;
        nodes finish;
        nodes* path;
        int** grid;
        int m;
        int n;
        int pathLen;
    public:
        findPath(int rowm, int coln, int rows, int cols, int rowf, int colf){
            m=rowm;
            n=coln;
            grid=new int* [rowm+5];
            for(int i=0; i<m+2; i++){
                grid[i]=new int [n+5];
                for(int j=0; j<n+2; j++){
                    grid[i][j]=0;
                }
            }
            path=new nodes [m*n];
            start.row=rows;
            start.col=cols;
            finish.row=rowf;
            finish.col=colf;
            pathLen=inf;
        }

        bool getPath(){
            if((start.row==finish.row)&&(start.col==finish.col)){
                pathLen=0;
                path[0]=start;
                return true;
            }
            for(int i=0; i<m+2; i++){
                grid[i][0]=1;
                grid[i][n+1]=1;
            }
            for(int i=0; i<n+2; i++){
                grid[0][i]=1;
                grid[m+1][i]=1;
            }
            nodes offset[4];
            offset[0].row=1;
            offset[0].col=0; //down
            offset[1].row=-1;
            offset[1].col=0; //up
            offset[2].row=0;
            offset[2].col=1; //right
            offset[3].row=0;
            offset[3].col=-1; //left
            int nbrNum=4;
            nodes here, nbr;
            here=start;
            grid[start.row][start.col]=2;
            queue<nodes> nodesQ;
            while(true){
                for(int i=0; i<nbrNum; i++){
                    nbr.row=here.row+offset[i].row;
                    nbr.col=here.col+offset[i].col;
                    cout << nbr.row << ' ' << nbr.col << endl;
                    if(grid[nbr.row][nbr.col]==0){
                        grid[nbr.row][nbr.col]=grid[here.row][here.col]+1;
                        if((nbr.row==finish.row)&&(nbr.col==finish.col)){
                            break;
                        }
                        nodesQ.push(nbr);
                    }
                }
                if((nbr.row==finish.row)&&(nbr.col==finish.col)){
                    break;
                }
                nodesQ.pop();
                if(nodesQ.empty()){
                    return false;
                }
                here=nodesQ.front();
            }
            // for(int i=0; i<m+2; i++){
            //     for(int j=0; j<n+2; j++){
            //         cout << grid[i][j] << ' ';
            //     }
            //     cout << endl;
            // }
            pathLen=grid[finish.row][finish.col]-2;
            here=finish;
            for(int i=pathLen-1; i>=0; i--){
                path[i]=here;
                for(int j=0; j<nbrNum; j++){
                    nbr.row=here.row+offset[j].row;
                    nbr.col=here.col+offset[j].col;
                    if(grid[nbr.row][nbr.col]==i+2){
                        break;
                    }
                }
                here=nbr;
            }
            return true;
        }

        void printHelp(bool re){
            ofstream outfile("out.txt");;
            if(re==true){
                for(int i=0; i<pathLen; i++){
                    outfile << path[i].row << ' ' << path[i].col << endl;
                }
            } else {
                outfile << "no path!" << endl;
            }
        }
};

#endif