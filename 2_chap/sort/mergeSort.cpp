#include <iostream>
 
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
 
int main() {
	/* Code to test the MergeSort function. */
 
	int A[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers.
	int i,numberOfElements;
 
	// finding number of elements in array as size of complete array in bytes divided by size of integer in bytes.
	// This won't work if array is passed to the function because array
	// is always passed by reference through a pointer. So sizeOf function will give size of pointer and not the array.
	// Watch this video to understand this concept - http://www.youtube.com/watch?v=CpjVucvAc3g
	numberOfElements = sizeof(A)/sizeof(A[0]);
 
	// Calling merge sort to sort the array.
	MergeSort(A,numberOfElements);
 
	//printing all elements in the array once its sorted.
	for(i = 0;i < numberOfElements;i++)
	   cout << " " << A[i];
	return 0;
}