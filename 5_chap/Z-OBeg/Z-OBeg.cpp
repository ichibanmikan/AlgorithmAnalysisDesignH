#include "Z-OBeg.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream infile("in.txt");
    int c, num;
    infile >> num;
    infile >> c;
    int* arrayw=new int [num];
    int* arrayv=new int [num];
    for(int i=0; i<num; i++){
        infile >> arrayw[i];
    }
    for(int i=0; i<num; i++){
        infile >> arrayv[i];
    }
    knap k(num, c, arrayw, arrayv);
    // k.printHelp();
    k.backtrace(0);
    cout << k.getBestv() << endl;
    return 0;
}