#include <iostream>
#include "resource.h"

using namespace std;

int main(){
    int* arrayw=new int [5];
    for(int i=0; i<3; i++){
        cin >> arrayw[i];
    }
    loading ld(3, arrayw, 20);
    ld.backtrace(0);
    cout << ld.getbestW() << endl;
    return 0;
}