#include <iostream>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <iomanip>
#define n 1005
#define inf 999

using namespace std;

void Dijstra(int** G, int size, int source, int* S, int* dist){
    bool isUsed[size]={false};
    for (int i=0; i<size; i++){
        dist[i]=G[source][i];
    }//将每个结点的最短路径值如果和源结点有直接的边相连就对相应的元素赋边权值，否则赋给正无穷(inf)
    for(int i=0; i<size; i++){
        int E=inf, temp;
        for (int j=0; j<size; j++){
            if(dist[j]<E && isUsed[j]==false){
                E=dist[j];
                temp=j;
            }
        }//先找出此时权值最小的边用E表示，对应节点用temp表示0
        if(E==inf){
            return ;
        }
        S[i]=temp;
        isUsed[temp]=true;
        for (int j=0; j<size; j++){
            if(dist[j]>dist[temp]+G[temp][j]){
                dist[j]=dist[temp]+G[temp][j];
            }
        }//E不是inf则将temp加入S,然后松弛一步,对temp能到达的所有顶点单源最短路径值进行判断并相应的改变dist值。
    }
}

int main(){
    int** Graph=new int* [n];
    ifstream infile("data_100.txt");
    ofstream outfile("result_100.txt");
    for (int i=0; i<n; i++){
        Graph[i]=new int [n];
    }
    int size;
    infile >> size;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            infile >> Graph[i][j];
        }
    }
    int* dist=new int [n];
    int* S=new int [n];
    LARGE_INTEGER LIB_dijkstra;
    LARGE_INTEGER LIE_dijkstra;
    LARGE_INTEGER FREQ_dijkstra;
    QueryPerformanceFrequency(&FREQ_dijkstra);
    QueryPerformanceCounter(&LIB_dijkstra);
    Dijstra(Graph, size, 0, S, dist);
    QueryPerformanceCounter(&LIE_dijkstra);
    double useTime=(double)(LIE_dijkstra.QuadPart-LIB_dijkstra.QuadPart)/((double)FREQ_dijkstra.QuadPart);
    outfile << "数据规模为" << size << "的dijkstra贪心算法所需时间: ";
    outfile << fixed << setprecision(8) << useTime << endl;
    outfile << endl;

    for (int i=0; i<size; i++){
        outfile << S[i] << ' ';
    }
    outfile<< endl;
    for (int i=0; i<size; i++){
        outfile << dist[i] << ' ';
    }
    outfile << endl;    
    for (int i=0; i<n; i++){
        delete  [] Graph[i];
    }
    delete [] Graph;
    delete [] dist;
    delete [] S;
    return 0;
}