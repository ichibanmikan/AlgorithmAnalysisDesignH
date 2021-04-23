#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

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

    LARGE_INTEGER LIB_aggDiv;
    LARGE_INTEGER LIE_aggDiv;
    LARGE_INTEGER FREQ_ZOBeg;
    QueryPerformanceFrequency(&FREQ_ZOBeg);
    QueryPerformanceCounter(&LIB_aggDiv);
    outfile << setn(n) << endl;
    QueryPerformanceCounter(&LIE_aggDiv);
    double useTime=(double)(LIE_aggDiv.QuadPart-LIB_aggDiv.QuadPart)/((double)FREQ_ZOBeg.QuadPart);
    outfile << "数据规模为" << n << "的集合划分问题分治算法所需时间: ";
    outfile << fixed << setprecision(8) << useTime << endl;
    // cin >> n;
    // cout << setn(n) << endl;
    return 0;
}//半数集问题