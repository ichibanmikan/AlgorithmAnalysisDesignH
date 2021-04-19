#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct goods{
	int no;//序号
	int value;//重量
	int weight;//价值
	double valPerWei;//单位价值
};

bool cmp(goods g1, goods g2){
	return g1.valPerWei>g2.valPerWei;
}

int main(){
	int n, m; //n表示有多少件物品, m表示背包最大承载量
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	infile >> n >> m;
	goods* gdArray=new goods [n];
	for (int i=0; i<n; i++){
		gdArray[i].no=i;
		infile >> gdArray[i].weight >> gdArray[i].value;
		gdArray[i].valPerWei=((double)(gdArray[i].value))/((double)(gdArray[i].weight));
	}//输入价值, 重量, 并计算出单位价值存储起来
	sort(gdArray, gdArray+n, cmp);
	int i=0;
	outfile << "no" << ' ' << "weight" << ' ' << "value" << ' ' << "ratio" << endl;
	while(true){
		m-=gdArray[i].weight;
		if(m<0){
			m+=gdArray[i].weight;
			outfile << gdArray[i].no << "    " << gdArray[i].weight << "      " << gdArray[i].value << "     " << double(m)/double(gdArray[i].weight) << endl;
			break;
		}
		outfile << gdArray[i].no << "    " << gdArray[i].weight << "      " << gdArray[i].value << "     " << 1 << endl;
		i++;
	}
	return 0;
}