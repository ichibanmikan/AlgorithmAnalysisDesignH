#include <iostream>
#include <fstream>

using namespace std;

int setn(int n){
    int sum=1;
    for (int i=1; i<=n/2; i++){
        sum+=setn(i);
    }
    return sum;
}

int main(){
    int n;
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    infile >> n;
    outfile << setn(n);
    // cin >> n;
    // cout << setn(n) << endl;
    return 0;
}//半数集问题