#include <iostream>
#include <fstream>
#include "nQueens.h"

using namespace std;

int main(){
    nQueens nq(12);
    nq.backtrace(0);
    nq.printHelp();
    return 0;
}