#include "getResult.h"

using namespace std;

int main(){
    findPath F(5, 5, 1, 1, 2, 5);
    bool re=F.getPath();
    F.printHelp(re);
    return 0;
}