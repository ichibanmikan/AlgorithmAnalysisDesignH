#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

using namespace std;

int getMax(int *array, int leftSize, int rightSize){
    if(leftSize==rightSize){
        return array[leftSize];
    }
    if(leftSize==rightSize-1){
        return array[leftSize]>array[rightSize]?array[leftSize]:array[rightSize];
    }
    int mid=(leftSize+rightSize)/2;
    int temp1=getMax(array, leftSize, mid);
    int temp2=getMax(array, mid, rightSize);
    return temp1>temp2?temp1:temp2;
}

int getMin(int *array, int leftSize, int rightSize){
    if(leftSize==rightSize){
        return array[leftSize];
    }
    if(leftSize==rightSize-1){
        return array[leftSize]<array[rightSize]?array[leftSize]:array[rightSize];
    }
    int mid=(leftSize+rightSize)/2;
    int temp1=getMin(array, leftSize, mid);
    int temp2=getMin(array, mid, rightSize);
    return temp1<temp2?temp1:temp2;
}

int array_100[105];
int array_10000[10005];
int array_1000000[1000005];

ofstream outfile("report.txt", ios::out);
int main(){
    //***********************************************
    ifstream infile_100_max("data_100.txt", ios::in);
    for (int i=0; i<100; i++){
        infile_100_max >> array_100[i];
    }
    infile_100_max.close();
    LARGE_INTEGER LIB_100_max;
    LARGE_INTEGER LIE_100_max;
    LARGE_INTEGER FREQ_100_max;
    QueryPerformanceFrequency(&FREQ_100_max);
    QueryPerformanceCounter(&LIB_100_max);
    int temp_100=getMax(array_100, 0, 99);
    QueryPerformanceCounter(&LIE_100_max);
    double time_100_max=(double)(LIE_100_max.QuadPart-LIB_100_max.QuadPart)/((double)FREQ_100_max.QuadPart);
    outfile << "数据规模为100的取最大值结果: " ;
    outfile << temp_100;
    outfile << endl;
    cout << "数据规模为100的取最大值所需时间: ";
    cout  << fixed << setprecision(8) << time_100_max << endl;
    //***********************************************
    ifstream infile_10000_max("data_10k.txt", ios::in);
    for (int i=0; i<10000; i++){
        infile_10000_max >> array_10000[i];
    }
    infile_10000_max.close();
    LARGE_INTEGER LIB_10000_max;
    LARGE_INTEGER LIE_10000_max;
    LARGE_INTEGER FREQ_10000_max;
    QueryPerformanceFrequency(&FREQ_10000_max);
    QueryPerformanceCounter(&LIB_10000_max);
    int temp_10000=getMax(array_10000, 0, 9999);
    QueryPerformanceCounter(&LIE_10000_max);
    double time_10000_max=(double)(LIE_10000_max.QuadPart-LIB_10000_max.QuadPart)/((double)FREQ_10000_max.QuadPart);
    outfile << "数据规模为10000的取最大值结果: ";
    outfile << temp_10000;
    outfile << endl;
    cout << "数据规模为10000的取最大值所需时间: ";
    cout << fixed << setprecision(8) << time_10000_max << endl;
    //***********************************************
    ifstream infile_1000000_max("data_1M.txt", ios::in);
    for (int i=0; i<1000000; i++){
        infile_1000000_max >> array_1000000[i];
    }
    infile_1000000_max.close();
    LARGE_INTEGER LIB_1000000_max;
    LARGE_INTEGER LIE_1000000_max;
    LARGE_INTEGER FREQ_1000000_max;
    QueryPerformanceFrequency(&FREQ_1000000_max);
    QueryPerformanceCounter(&LIB_1000000_max);
    int temp_1M=getMax(array_1000000, 0, 999999);
    QueryPerformanceCounter(&LIE_1000000_max);
    double time_1000000_max=(double)(LIE_1000000_max.QuadPart-LIB_1000000_max.QuadPart)/((double)FREQ_1000000_max.QuadPart);
    outfile << "数据规模为1000000的取最大值结果: ";
    outfile << temp_1M;
    outfile << endl;
    cout << "数据规模为1000000的取最大值所需时间: ";
    cout << fixed << setprecision(8) << time_1000000_max << endl;
    //***********************************************
    outfile << endl;
    outfile << endl;
    //***********************************************
    LARGE_INTEGER LIB_100_min;
    LARGE_INTEGER LIE_100_min;
    LARGE_INTEGER FREQ_100_min;
    QueryPerformanceFrequency(&FREQ_100_min);
    QueryPerformanceCounter(&LIB_100_min);
    int temp_100_min=getMin(array_100, 0, 99);
    QueryPerformanceCounter(&LIE_100_min);
    double time_100_min=(double)(LIE_100_min.QuadPart-LIB_100_min.QuadPart)/((double)FREQ_100_min.QuadPart);
    outfile << "数据规模为100的取最小值结果: " ;
    outfile << temp_100_min;
    outfile << endl;
    cout << "数据规模为100的取最小值所需时间: ";
    cout  << fixed << setprecision(8) << time_100_min << endl;
    //***********************************************
    LARGE_INTEGER LIB_10000_min;
    LARGE_INTEGER LIE_10000_min;
    LARGE_INTEGER FREQ_10000_min;
    QueryPerformanceFrequency(&FREQ_10000_min);
    QueryPerformanceCounter(&LIB_10000_min);
    int temp_10000_min=getMin(array_10000, 0, 9999);
    QueryPerformanceCounter(&LIE_10000_min);
    double time_10000_min=(double)(LIE_10000_min.QuadPart-LIB_10000_min.QuadPart)/((double)FREQ_10000_min.QuadPart);
    outfile << "数据规模为10000的取最小值结果: ";
    outfile << temp_10000_min;
    outfile << endl;
    cout << "数据规模为10000的取最小值所需时间: ";
    cout << fixed << setprecision(8) << time_10000_min << endl;
    //***********************************************
    LARGE_INTEGER LIB_1000000_min;
    LARGE_INTEGER LIE_1000000_min;
    LARGE_INTEGER FREQ_1000000_min;
    QueryPerformanceFrequency(&FREQ_1000000_min);
    QueryPerformanceCounter(&LIB_1000000_min);
    int temp_1M_min=getMin(array_1000000, 0, 999999);
    QueryPerformanceCounter(&LIE_1000000_min);
    double time_1000000_min=(double)(LIE_1000000_min.QuadPart-LIB_1000000_min.QuadPart)/((double)FREQ_1000000_min.QuadPart);
    outfile << "数据规模为1000000的取最小值结果: ";
    outfile << temp_1M_min;
    outfile << endl;
    cout << "数据规模为1000000的取最小值所需时间: ";
    cout << fixed << setprecision(8) << time_1000000_min << endl;
    //***********************************************
    system("pause");
    return 0;
}