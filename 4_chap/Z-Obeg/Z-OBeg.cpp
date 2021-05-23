#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

#define maxn 10005

using namespace std;

int n;//物品数量 
int c;//背包容量 
int cw;//当前重量
int cv;//当前价值
int bestv;//最优价值
int x[maxn];//记录当前物品是否装入背包 
int order[maxn];//物品编号1~n
int best_x[maxn];//用于记录回溯过程的最优情况 
double w[maxn];//存放物品重量的数组 
double v[maxn];//存放物品价值的数组 
double vw[maxn];//物品单位重量价值 

void setOrder(){
	for(int i=1;i<=n;++i){
        vw[i]=v[i]/w[i];//单位重量价值
    }
 	for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(vw[i]<vw[j]){
                double temp;
                temp = vw[i];  //冒泡对vw[]排序
                vw[i]=vw[i];
                vw[j]=temp;

                temp=order[i];//冒泡对order[]排序
                order[i]=order[j];
                order[j]=temp;
    
                temp = v[i];//冒泡对v[]排序
                v[i]=v[j];
                v[j]=temp;
    
                temp=w[i];//冒泡对w[]排序
                w[i]=w[j];
                w[j]=temp;
            }
        }//冒泡排序vw[],order[],v[],w[]	
    }
}
int isVisit(int i){
	int cleft=c-cw;//剩余容量
	int value=cv;
	while(i<=n&&w[i]<=cleft){
		cleft-=w[i];
		value+=v[i];
		++i; 
	 } 
	if(i<=n){
        value+=v[i]*cleft/w[i];
    }
	return value; 
}//限界函数:该函数返回装入所有剩余物品后(不能超过c的前提下)的价值

void Backtrack(int i){
	if(i>n){	
        for(int i = 1; i <= n; i++){
            best_x[i] = x[i];   //记录回溯的最优情况
        }
        bestv=cv;//更新最优的价值 
        return;
	}//到达根节点且根节点处理完毕
	if(i<=n){
		if(cw+w[i]<=c){
			x[i]=1;//用来构造最优解，将物品放入时x[i]=1 
			cw+=w[i];
			cv+=v[i];
			Backtrack(i+1);
			cw-=w[i];
			cv-=v[i];
		}//如果满足约束条件，进入左子树(约束条件：不超过容量c)
		if(isVisit(i+1)>bestv){
			x[i]=0;//右子树意味着物品不装入，x[i]=0 
			Backtrack(i+1); 
		}//满足限界函数进入右子树
	}//处理中间过程的节点 
}
int main(){
	bestv=0;
    cv=0;
    cw=0;
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
	infile >> n;//物品数量
	infile >> c;//背包容量
	for(int i=1;i<=n;++i){
        infile>>w[i];
        infile>>v[i];
    }
	for(int i=1;i<=n;++i){
        order[i]=i;
    }
	setOrder();
    LARGE_INTEGER LIB_ZOBeg;
    LARGE_INTEGER LIE_ZOBeg;
    LARGE_INTEGER FREQ_ZOBeg;
    QueryPerformanceFrequency(&FREQ_ZOBeg);
    QueryPerformanceCounter(&LIB_ZOBeg);
    Backtrack(1);
    QueryPerformanceCounter(&LIE_ZOBeg);
    double useTime=(double)(LIE_ZOBeg.QuadPart-LIB_ZOBeg.QuadPart)/((double)FREQ_ZOBeg.QuadPart);
    outfile << "数据规模为" << n << "的回溯算法0-1背包问题所需时间: ";
    outfile << fixed << setprecision(8) << useTime << endl;
    outfile << endl;
	outfile << bestv << endl;
	for(int i=1;i<=n;++i){
        if(best_x[i]==1){
            outfile<<order[i]<<" ";
        }
    }
	return 0;
 } 
