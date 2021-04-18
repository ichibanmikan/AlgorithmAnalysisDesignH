#include <iostream>
#include <fstream>

using namespace std;

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
} //������Ԫ�ؽ��н���

int jc(int a){
    if(a==1){
        return 1;
    }
    return a*jc(a-1);
}//��׳˵ĺ���

int getDnum(int *array, int n){
    int result=0;
    for (int i=0; i<n; i++){
        int pc=0;
        for (int j=i+1; j<n; j++){
            if(array[j]<array[i]){
                pc++;
            }
        }
        if(pc!=0&&i!=n-1){
            result+=pc*jc(n-i-1);
        }
    }
    return result;
}//���������е��ֵ������������Ƕ���������е�ÿһλ�������ΪΪ��mλ�����ڲ�ѭ������һλ�����м���
 //����С������������n�������г���Ϊs���ǵ�mλ���ֵ�������n*(s-m-1)!���������е��ֵ�������ÿһλ�ĺ�
 //����Ŀ��������Ϊ��
 //        2 6 4 5 8 1 7 3
 //        ��2С�ĸ�����1��������tal+=1*7��
 //        ��6С�ĸ�����4��������tal+=4*6��
 //        ��4С�ĸ�����1��������tal+=2*6��
 //        ��5С�ĸ�����1��������tal+=2*4��
 //        ��8С�ĸ�����1��������tal+=3*3��
 //        ��1С�ĸ�����1��������tal+=0*2��
 //        ��7С�ĸ�����1��������tal+=1*1��
 //        ��3С�ĸ���û��

int* getNextSeq(int *array, int n){
    int temp1, temp2;
    for (int i=n-2; i>=0; i--){
        if(array[i]<array[i+1]){
            temp1=i;
            break;
        }
    }//��һ��forѭ���ҵ�����a[i]<a[i+1]����
    for (int i=n-1; i>=0; i--){
        if(array[i]>array[temp1]){
            temp2=i;
            break;
        }
    }//�ڶ���forѭ���ҵ���һ������a[temp1]����
    swap(array[temp1], array[temp2]);
    int tempn=n;
    for (int i=temp1+1; i<n; i++){
        swap(array[i], array[--tempn]);
    }//������forѭ������������תΪ˳������
    return array;
}/*�ú������ض�Ӧ����һ�����С�������a[8]={1, 2, 3, 4, 5, 6, 7, 8}Ϊ����ö��Ѱ�ҹ�������
           1 2 3 4 5 6 7 8
           1 2 3 4 5 6 8 7
           1 2 3 4 5 7 6 8
           1 2 3 4 5 7 8 6
           1 2 3 4 5 8 6 7
           1 2 3 4 5 8 7 6
           1 2 3 4 6 5 7 8
    ���Թ۲쵽������ÿ�ν���ʱ�������е�ĩβ�����еĿ�ͷ�����ҵ����Ƿ������¹��ɵ�һ����: 
    ����a[i]<a[i+1]����¼�´�ʱ��iֵʹ��temp1��ʾ������������ĩβ��ʼ��һ������a[i]<a[i+1]
    ����������ζ�Ÿ����Ժ������ɵ�������{a[temp1+1], ����, a[n-1]}������ȫ�ĵ���������
    �ֵ����ﵽ����ֵ����ټ�һ������ֻ�ܴ����￪ʼ�仯��)��
    ���Ŵ����е�ĩβ��ʼ�ҵ�һ������a[temp1]����,����temp2��¼�´�ʱ������Ӧ��iֵ����ʱ����֤��
    temp2>temp1 (a[temp1]����a[temp1]<a[temp1+1],����temp2����ҲӦ����temp1+1),���ҿ���֤��
    a[temp2]Ϊ������{a[temp1+1], ����, a[temp2]}����С��(a[temp1+1]>a[temp1+2]>����>a[temp2])
    ��������ڼӷ���λ�����ǿ��Խ���������������Ȼ�󽫽�����ɺ��������{a[temp1+1], ����, a[temp2]}
    ���°����������У������Ϸ���֪��������Ϊ��ȫ����(�ֵ������)�����ǿ���ʹ��forѭ������������С
    (��a[temp1+1](������������)��a[n-1](����������С��), a[temp1+2](�������еڶ����)
    ��a[n-2](�������еڶ�С��)����)���������Ԫ��˳�����С���˵õ����ֵ������һ����
    
    ����Ŀ������Ϊ��
           2 6 4 5 8 1 7 3
    1.�ȴ�β���ҵ���һ��a[i]<a[i+1]��λ��
           2 6 4 5 8 1< 7 3,��ô�ҵ���1
      �����ҵ�1����С��λ�ã���¼1���ڵ�λ��iΪtemp1
    2.��β����ʼ��ǰ�ҵ�һ������1������
           2 6 4 5 8 1 <7 3,��ô�ҵ���3��¼Ϊtemp2
      �����ҵ���3�����ʱ��¼3���ڵ�λ��m
    3.����1��3��λ��--2 6 4 5 8 3 7 1
    4.��ʱ����iλ���Ժ����������
           2 6 4 5 8 3 1 7*/
           
int main(){
    ifstream infile("input.txt");
    int n;
    infile >> n;
    int *arrayN=new int [n];
    for (int i=0; i<n; i++){
        infile >> arrayN[i];
    }
    ofstream outfile("output.txt", ios::out);
    outfile << getDnum(arrayN, n) << endl;
    int *arrayT=new int [n];
    arrayT=getNextSeq(arrayN, n);
    for (int i=0; i<n; i++){
        outfile << arrayT[i] << ' ';
    }
    return 0;
}