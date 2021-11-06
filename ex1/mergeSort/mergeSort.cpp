#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

using namespace std;

void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i=0,j=0,k=0;
	while(i<leftCount && j< rightCount) {
		if(L[i]<R[j]){
			A[k++]=L[i++];
			continue;
		}
		A[k++]=R[j++];
	}
	while(i<leftCount){
		A[k++]=L[i++];
	}
	while(j<rightCount){
		A[k++]=R[j++];
	}
}
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n<2){
		return ;
	}
	mid = n/2;
	L=new int[mid];
	R=new int [n - mid];
	for(i = 0;i<mid;i++){
		L[i]=A[i];
	}
	for(i = mid;i<n;i++){
		R[i-mid]=A[i];
	}
	MergeSort(L,mid);
	MergeSort(R,n-mid);
	Merge(A,L,mid,R,n-mid);
	delete [] R;
	delete [] L;
}

int array_100[105];
int array_10000[10005];
int array_1000000[1000005];

ofstream outfile("report.txt", ios::out);
int main(){
    //***********************************************
    ifstream infile_100_merge("data_100.txt", ios::in);
    for (int i=0; i<100; i++){
        infile_100_merge >> array_100[i];
    }
    infile_100_merge.close();
    LARGE_INTEGER LIB_100_merge;
    LARGE_INTEGER LIE_100_merge;
    LARGE_INTEGER FREQ_100_merge;
    QueryPerformanceFrequency(&FREQ_100_merge);
    QueryPerformanceCounter(&LIB_100_merge);
    MergeSort(array_100, 100);
    QueryPerformanceCounter(&LIE_100_merge);
    double time_100_merge=(double)(LIE_100_merge.QuadPart-LIB_100_merge.QuadPart)/((double)FREQ_100_merge.QuadPart);
    outfile << "数据规模为100的归并排序结果: " << endl;
    for(int i=0; i<100; i++){
        outfile << array_100[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为100的归并排序所需时间: ";
    cout  << fixed << setprecision(8) << time_100_merge << endl;
    //***********************************************
    outfile << endl;
    outfile << endl;
    outfile << endl;
    ifstream infile_10000_merge("data_10k.txt", ios::in);
    for (int i=0; i<10000; i++){
        infile_10000_merge >> array_10000[i];
    }
    infile_10000_merge.close();
    LARGE_INTEGER LIB_10000_merge;
    LARGE_INTEGER LIE_10000_merge;
    LARGE_INTEGER FREQ_10000_merge;
    QueryPerformanceFrequency(&FREQ_10000_merge);
    QueryPerformanceCounter(&LIB_10000_merge);
    MergeSort(array_10000, 10000);
    QueryPerformanceCounter(&LIE_10000_merge);
    double time_10000_merge=(double)(LIE_10000_merge.QuadPart-LIB_10000_merge.QuadPart)/((double)FREQ_10000_merge.QuadPart);
    outfile << "数据规模为10000的归并排序结果: " << endl;
    for(int i=0; i<10000; i++){
        outfile << array_10000[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为10000的归并排序所需时间: ";
    cout << fixed << setprecision(8) << time_10000_merge << endl;
    //***********************************************
    outfile << endl;
    outfile << endl;
    outfile << endl;
    ifstream infile_1000000_merge("data_1M.txt", ios::in);
    for (int i=0; i<1000000; i++){
        infile_1000000_merge >> array_1000000[i];
    }
    infile_1000000_merge.close();
    LARGE_INTEGER LIB_1000000_merge;
    LARGE_INTEGER LIE_1000000_merge;
    LARGE_INTEGER FREQ_1000000_merge;
    QueryPerformanceFrequency(&FREQ_1000000_merge);
    QueryPerformanceCounter(&LIB_1000000_merge);
    MergeSort(array_1000000, 1000000);
    QueryPerformanceCounter(&LIE_1000000_merge);
    double time_1000000_merge=(double)(LIE_1000000_merge.QuadPart-LIB_1000000_merge.QuadPart)/((double)FREQ_1000000_merge.QuadPart);
    outfile << "数据规模为1000000的归并排序结果: " << endl;
    for(int i=0; i<1000000; i++){
        outfile << array_1000000[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为1000000的归并排序所需时间: ";
    cout << fixed << setprecision(8) << time_1000000_merge << endl;
    //***********************************************
    system("pause");
    return 0;
}