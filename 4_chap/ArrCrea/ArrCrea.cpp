#include <iostream>
#include <algorithm>
#include <windows.h>
#include <iomanip>
#include <fstream>

using namespace std;

void ArrCrea(int* result, int* ends, int* arr, int length){
    ends[0]=arr[0];
    result[0]=1;
    int right=0, l=0, r=0, m=0;
    for(int i=1;i<length;i++){
        l=0;
        r=right;
        while(l<=r){
            m=l+(r-l)/2;
            if(arr[i]>ends[m]) {
                l=m+1;
            }else{
                r=m-1;
            }
        }
        right=max(l, right);
        ends[l]=arr[i];
        result[i]=l+1;
    }
}

int main(){
    int n;
    ifstream infile("inputs.txt");
    ofstream outfile("outputs.txt");
    infile >> n;
    int* arr=new int [n];
    int* ends=new int [n];
    int* result=new int [n];
    for (int i=0; i<n; i++){
        infile >> arr[i];
    }
    LARGE_INTEGER LIB_ArrCrea;
    LARGE_INTEGER LIE_ArrCrea;
    LARGE_INTEGER FREQ_ArrCrea;
    QueryPerformanceFrequency(&FREQ_ArrCrea);
    QueryPerformanceCounter(&LIB_ArrCrea);
    ArrCrea(result, ends, arr, n);
    QueryPerformanceCounter(&LIE_ArrCrea);
    double useTime=(double)(LIE_ArrCrea.QuadPart-LIB_ArrCrea.QuadPart)/((double)FREQ_ArrCrea.QuadPart);
    outfile << "数据规模为" << n << "的最长递增子序列动态算法所需时间: ";
    outfile << fixed << setprecision(8) << useTime << endl;
    outfile << endl;
    for (int i=0; i<n; i++){
        if(ends[i]==0||ends[i]>100){
            break;
        }
        outfile << ends[i] << ' ';
    }
    outfile << endl;
    delete [] arr;
    delete [] result;
    delete [] ends;
    return 0;
}
