#include "Z-OBeg.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream infile("in.txt");
    int n, c;
    int* w=new int [n];
    int* v=new int [n];
    infile >> n >> c;
    for(int i=0; i<n; i++){
        infile >> w[i];
        infile >> v[i];
    }
    // for(int i=0; i<n; i++){
    //     infile >> v[i];
    // }
    Knap k(w, v, c, n);
    // cout << k.maxKnapsack() << endl;
    printf("      最大价值为：%d", k.maxKnapsack());
    return 0;
}