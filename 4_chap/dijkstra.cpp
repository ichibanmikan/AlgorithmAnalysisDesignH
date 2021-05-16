#include <iostream>
#include <algorithm>
#define n 105
#define inf 999

using namespace std;

void Dijstra(int** G, int size, int source, int* S, int* dist){
    bool isUsed[size]={false};
    for (int i=0; i<size; i++){
        dist[i]=G[source][i];
    }
    for(int i=0; i<size; i++){
        int E=inf, temp;
        for (int j=0; j<size; j++){
            if(dist[j]<E && isUsed[j]==false){
                E=dist[j];
                temp=j;
            }
        }
        if(E==inf){
            return ;
        }
        S[i]=temp;
        isUsed[temp]=true;
        for (int j=0; j<size; j++){
            if(dist[j]>dist[temp]+G[temp][j]){
                dist[j]=dist[temp]+G[temp][j];
            }
        }
    }
}

int main(){
    int** Graph=new int* [n];
    for (int i=0; i<n; i++){
        Graph[i]=new int [n];
    }
    int size;
    cin >> size;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cin >> Graph[i][j];
        }
    }
    int* dist=new int [n];
    int* S=new int [n];
    Dijstra(Graph, size, 0, S, dist);
    for (int i=0; i<size; i++){
        cout << S[i] << ' ';
    }
    cout << endl;
    for (int i=0; i<size; i++){
        cout << dist[i] << ' ';
    }
    cout << endl;    
    for (int i=0; i<n; i++){
        delete  [] Graph[i];
    }
    delete [] Graph;
    return 0;
}