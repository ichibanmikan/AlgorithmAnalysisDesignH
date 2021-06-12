#include <iostream>
#include "flowShop.h"
#include <fstream>

using namespace std;

int main(){
    ifstream infile("in.txt");
    int num;
    infile >> num;
    int** T=new int* [num];
    for(int i=0; i<num; i++){
        T[i]=new int [2];
        infile >> T[i][0] >> T[i][1];
    }
    flowShop f(T, num);
    f.backtrace(0);
    f.printHelp();
    return 0;
}