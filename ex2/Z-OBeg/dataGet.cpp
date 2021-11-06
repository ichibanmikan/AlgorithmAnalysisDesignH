#include <iostream>
#include <fstream>
#include <cstdlib>

#define b 100
#define a 0

using namespace std;

int main(){
    ofstream outfile("data.txt");
    for (int i=0; i<10000; i++){
        outfile << (rand()%(b-a+1))+a << ' ' << (rand()%(b-a+1))+a << endl;
    }
    return 0;
}