#include <iostream>
#include <algorithm>

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
    cin >> n;
    int* arr=new int [n];
    int* ends=new int [n];
    int* result=new int [n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    ArrCrea(result, ends, arr, n);
    for (int i=0; i<n; i++){
        if(ends[i]==0){
            break;
        }
        cout << ends[i] << ' ';
    }
    cout << endl;
    delete [] arr;
    delete [] result;
    delete [] ends;
    return 0;
}
