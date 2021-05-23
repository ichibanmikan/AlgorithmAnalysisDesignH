#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <iomanip>

using namespace std;

void getDistance(int** result, string str1, string str2, int k){
    result[0][0]=0;
    for (int i=0; i<=str1.length(); i++){
        for (int j=0; j<=str2.length(); j++){
            if(i+j==0){
                continue;
            }
            if(i==0){
                result[i][j]=result[i][j-1]+k;
            }
            if(j==0){
                result[i][j]=result[i-1][j]+k;
            }
            if(j>0&&i>0){
                int temp=(result[i][j-1]+k<result[i-1][j]+k)?result[i][j-1]+k:result[i-1][j]+k;
                result[i][j]=(temp<result[i-1][j-1]+abs((int)str1[i-1]-(int)str2[j-1]))?temp:result[i-1][j-1]+abs((int)str1[i-1]-(int)str2[j-1]);
            }
        }
    }
} //val(i,j)=min{val(i-1,j)+k,val(i,j-1)+k, val(i-1,j-1)+dist(ai,bj)}

int main(){
    string str1, str2;
    int k;
    ifstream infile("inputs.txt");
    ofstream outfile("outputs.txt");
    infile >> str1 >> str2;
    infile >> k;
    int** result=new int* [str1.length()+1];
    for (int i=0; i<=str1.length(); i++){
        result[i]=new int [str2.length()+1];
    }

    LARGE_INTEGER LIB_StrComp;
    LARGE_INTEGER LIE_StrComp;
    LARGE_INTEGER FREQ_StrComp;
    QueryPerformanceFrequency(&FREQ_StrComp);
    QueryPerformanceCounter(&LIB_StrComp);
    getDistance(result, str1, str2, k);
    QueryPerformanceCounter(&LIE_StrComp);
    double useTime=(double)(LIE_StrComp.QuadPart-LIB_StrComp.QuadPart)/((double)FREQ_StrComp.QuadPart);
    outfile << "数据规模为" << str1.length() << "的字符串扩展距离问题动态规划算法所需时间: ";
    outfile << fixed << setprecision(8) << useTime << endl;
    outfile << endl;

    outfile << result[str1.size()][str2.size()] << endl;
    for (int i=0; i<=str1.length(); i++){
        delete [] result[i];
    }
    delete [] result;
    return 0;
}