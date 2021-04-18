#include <iostream>
#include <fstream>

using namespace std;

int aggDiv(int n, int m){
    if(m==1||n==m){
        return 1;
    }
    return aggDiv(n-1, m-1)+m*aggDiv(n-1, m);
}

int main(){
    int n;
    ifstream infile("input.txt");
    ofstream outfile("outfile.txt");
    infile >> n;
    // cin >> n;
    int result=0;
    for (int i=0; i<n; i++){
        result+=aggDiv(n, i+1);
    }
    outfile << result;
    // cout << result;
    return 0;
}//集合划分问题