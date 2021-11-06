#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

#define inf 99999

using namespace std;

void turnLine(int **array, int x, int n){
    for (int i=0; i<n; i++){
        if(array[x][i]==0){
            array[x][i]=1;
            continue;
        }
        array[x][i]=0;
    }
}//翻转行

void exchRow(int **array, int m, int x, int y){
    if(x==y){
        return ;
    }
    for (int i=0; i<m; i++){
        int temp=array[i][x];
        array[i][x]=array[i][y];
        array[i][y]=temp;
    }
}//交换列

bool isSameRow(int **array1, int **array2, int m, int x, int y){
    for (int i=0; i<m; i++){
        if(array1[i][x]!=array2[i][y]){
            return false;
        }
    }
    return true;
}//判断两列是否相同

bool isSameLine(int **array1, int **array2, int n, int x, int y){
    for (int i=0; i<n; i++){
        if(array1[x][i]!=array2[y][i]){
            return false;
        }
    }
    return true;
}//判断两行是否相同

int main(){
    int** arrayS;
    int** goal;
    ifstream infile("datain.txt");
    ofstream outfile("dataout.txt");
    int time;
    infile >> time;
    while(time>0){
        LARGE_INTEGER LIB_100_merge;
        LARGE_INTEGER LIE_100_merge;
        LARGE_INTEGER FREQ_100_merge;
        QueryPerformanceFrequency(&FREQ_100_merge);
        QueryPerformanceCounter(&LIB_100_merge);
        int m, n;
        infile >> m >> n;
        arrayS=new int* [m];
        goal=new int* [m];
        for (int i=0; i<m; i++){
            arrayS[i]=new int [n];
            goal[i]=new int [n];
            for (int j=0; j<n; j++){
                infile >> arrayS[i][j];
            }
        }
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                infile >> goal[i][j];
            }
        }
        int result=inf;
        for (int i=0; i<n; i++){   //已知加入某个原始序列符合题目条件的话，那么原始序列中一定会有一列作为目标序列的第一列。
                                   //先用这个for枚举出第一列到底是哪个
            int temp=0;
            int **tempArray=new int* [m];
            int **tempGoal=new int* [m];
            for (int j=0; j<m; j++){
                tempArray[j]=new int [n];
                tempGoal[j]=new int [n];
                for(int k=0; k<n; k++){
                    tempArray[j][k]=arrayS[j][k];
                    tempGoal[j][k]=goal[j][k];
                }
            } //设定一个和原始序列相同的序列作为待处理序列
            exchRow(tempArray, m, 0, i);
            if(i!=0){
                temp++;
            }
            for (int j=0; j<m; j++){
                if(tempArray[j][0]!=goal[j][0]){
                    turnLine(tempArray, j, n);
                    temp++;
                }
            } //假设确定已经选好第一列，那么显然原始序列第一列和目标序列第一列应该是相同的。
              //那么不同的地方就应该行变换(因为已经假设确定第一列故不可能再列变换)，且行变换一旦执行每一列的这一行都会变化，
              //所以第一列行变换处理完后只能再对后面的列执行列变换，就相当于固定某一列看其他列。
            int ju;
            for (int j=1; j<n; j++){ //现在已经完成行变换，下面就要执行列变换同时判定此时选定的列是否确确实实就是第一列。
                ju=0;
                if(isSameRow(tempArray, goal, m, j, j)){
                    ju=1;
                    continue;
                }
                for (int k=j+1; k<n; k++){
                    if(isSameRow(tempArray, goal, m, j, k)){
                        if(isSameRow(tempArray, goal, m, k, k)){
                            continue;
                        }
                        exchRow(tempGoal, m, j, k); //注意是交换goal，这里想了好半天，如果交换tempArray样例都过不了。                          << "***" << endl;
                        ju=1;
                        break;
                    }
                }
                if(ju==0){
                    break;
                }
            }
            if(ju==1&&temp<result){
                result=temp;
            }
        }
        if(result!=inf){
            outfile << result << endl;
        }
        if(result==inf){
            outfile << -1 << endl;
        }
        time--;
        QueryPerformanceCounter(&LIE_100_merge);
        double time_100_merge=(double)(LIE_100_merge.QuadPart-LIB_100_merge.QuadPart)/((double)FREQ_100_merge.QuadPart);
        cout << "数据规模为" << m << 'X' << n << "的矩阵，该算法用时为：" << endl;
        cout  << fixed << setprecision(8) << time_100_merge << endl;
        cout << endl;
    }
    return 0;
}