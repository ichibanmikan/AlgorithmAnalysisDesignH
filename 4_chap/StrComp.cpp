#include <iostream>
#include <cstring>
#include <algorithm>

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
}

int main(){
    string str1, str2;
    int k;
    cin >> str1 >> str2;
    cin >> k;
    int** result=new int* [str1.length()+1];
    for (int i=0; i<=str1.length(); i++){
        result[i]=new int [str2.length()+1];
    }
    getDistance(result, str1, str2, k);
    cout << result[str1.size()][str2.size()] << endl;
    for (int i=0; i<=str1.length(); i++){
        delete [] result[i];
    }
    delete [] result;
    return 0;
}