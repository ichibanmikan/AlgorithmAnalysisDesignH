#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

using namespace std;

long long aggDiv(int n, int m){
    if(m==1||n==m){
        return 1;
    }
    return aggDiv(n-1, m-1)+m*aggDiv(n-1, m);
}

int main(){
    int n, m;
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    infile >> n;
    // cin >> n;
    long long result=0;

    LARGE_INTEGER LIB_aggDiv;
    LARGE_INTEGER LIE_aggDiv;
    LARGE_INTEGER FREQ_ZOBeg;
    QueryPerformanceFrequency(&FREQ_ZOBeg);
    QueryPerformanceCounter(&LIB_aggDiv);
    for (int i=1; i<=n; i++){
        result+=aggDiv(n, i);
    }
    QueryPerformanceCounter(&LIE_aggDiv);
    double useTime=(double)(LIE_aggDiv.QuadPart-LIB_aggDiv.QuadPart)/((double)FREQ_ZOBeg.QuadPart);
    outfile << "数据规模为" << n << "的集合划分问题分治算法所需时间: ";
    outfile << fixed << setprecision(8) << useTime << endl;

    outfile << result;
    // cout << result;
    return 0;
}//集合划分问题