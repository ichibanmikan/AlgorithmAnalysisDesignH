#include <iostream>

using namespace std;

void merge(int *AL, int *AR, int n){

}

void mergeSort(int *array, int n){
    for (int i=0; i<n-1; i++){
        if(array[i]>array[i+1]){
            int temp=array[i];
            array[i]=array[i+1];
            array[i+1]=temp;
            i++;
            continue;
        }
    }
    int mid=n/2;
    int ju=0;
    int fir=4;
    while(ju<mid){
        int left=0, right=fir-1;
        while(right<=n){
            
        }
    }
}