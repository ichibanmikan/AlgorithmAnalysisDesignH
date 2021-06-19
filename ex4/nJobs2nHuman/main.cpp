#include "getResult.h"
#include <fstream>

using namespace std;

int main(){
    int n;
    ifstream infile("in.txt");
    infile >> n;
    int** c=new int* [n];
    for(int i=0; i<n; i++){
        c[i]=new int [n];
        for(int j=0; j<n; j++){
            infile >> c[i][j];
        }
    }
    assign as(n, c);
    as.backtrace(0);
    printf("%d\n", as.getMinC());
    return 0;
}