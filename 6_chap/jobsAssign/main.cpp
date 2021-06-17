#include <iostream>
#include "Assign.h"
#include <fstream>

using namespace std;

int main(){
    ifstream infile("in.txt");
    int n, k;
    infile >> n >> k;
    int* arrayT=new int [n];
    for(int i=0; i<n; i++){
        infile >> arrayT[i];
    }
    getResult g1(n, k, arrayT);
    cout << g1.minTime() << endl;
    // g1.printHelp();
}