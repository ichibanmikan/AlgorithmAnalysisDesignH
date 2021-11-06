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
}//��ת��

void exchRow(int **array, int m, int x, int y){
    if(x==y){
        return ;
    }
    for (int i=0; i<m; i++){
        int temp=array[i][x];
        array[i][x]=array[i][y];
        array[i][y]=temp;
    }
}//������

bool isSameRow(int **array1, int **array2, int m, int x, int y){
    for (int i=0; i<m; i++){
        if(array1[i][x]!=array2[i][y]){
            return false;
        }
    }
    return true;
}//�ж������Ƿ���ͬ

bool isSameLine(int **array1, int **array2, int n, int x, int y){
    for (int i=0; i<n; i++){
        if(array1[x][i]!=array2[y][i]){
            return false;
        }
    }
    return true;
}//�ж������Ƿ���ͬ

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
        for (int i=0; i<n; i++){   //��֪����ĳ��ԭʼ���з�����Ŀ�����Ļ�����ôԭʼ������һ������һ����ΪĿ�����еĵ�һ�С�
                                   //�������forö�ٳ���һ�е������ĸ�
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
            } //�趨һ����ԭʼ������ͬ��������Ϊ����������
            exchRow(tempArray, m, 0, i);
            if(i!=0){
                temp++;
            }
            for (int j=0; j<m; j++){
                if(tempArray[j][0]!=goal[j][0]){
                    turnLine(tempArray, j, n);
                    temp++;
                }
            } //����ȷ���Ѿ�ѡ�õ�һ�У���ô��Ȼԭʼ���е�һ�к�Ŀ�����е�һ��Ӧ������ͬ�ġ�
              //��ô��ͬ�ĵط���Ӧ���б任(��Ϊ�Ѿ�����ȷ����һ�йʲ��������б任)�����б任һ��ִ��ÿһ�е���һ�ж���仯��
              //���Ե�һ���б任�������ֻ���ٶԺ������ִ���б任�����൱�ڹ̶�ĳһ�п������С�
            int ju;
            for (int j=1; j<n; j++){ //�����Ѿ�����б任�������Ҫִ���б任ͬʱ�ж���ʱѡ�������Ƿ�ȷȷʵʵ���ǵ�һ�С�
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
                        exchRow(tempGoal, m, j, k); //ע���ǽ���goal���������˺ð��죬�������tempArray�����������ˡ�                          << "***" << endl;
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
        cout << "���ݹ�ģΪ" << m << 'X' << n << "�ľ��󣬸��㷨��ʱΪ��" << endl;
        cout  << fixed << setprecision(8) << time_100_merge << endl;
        cout << endl;
    }
    return 0;
}