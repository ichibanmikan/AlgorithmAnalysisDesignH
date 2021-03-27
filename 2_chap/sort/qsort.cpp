#include <iostream>
#include <fstream>

using namespace std;

void swap(int* &array, int &t1, int &t2){
    int temp=array[t1];
    array[t1]=array[t2];
    array[t2]=temp;
}

void qsort(int *array, int leftSize, int rightSize){
    if(leftSize>=rightSize){
        return ;
    }
    int pivot=array[(leftSize+rightSize)/2];
    int start=leftSize;
    int end=rightSize;
    while(end>start){
        while(start<=end&&pivot>array[start]){
            start++;
        }
        while(end>=start&&pivot<array[end]){
            end--;
        }
        if(end>=start){
            swap(array, start, end);
            end--;
            start++;
        }
    }
    qsort(array, leftSize, end);
    qsort(array, start, rightSize);
}

int main(){
    ifstream infile("t1.txt", ios::in);
    int n;
    infile >> n;
    int* intArray=new int [n];
    for (int i=0; i<n; i++){
        infile >> intArray[i];
    }
    qsort(intArray, 0, n-1);
    ofstream outfile("resu1.txt", ios::out);
    for (int i=0; i<n; i++){
        outfile << intArray[i] << ' ';
    } 
    return 0;
}