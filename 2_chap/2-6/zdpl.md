```c++
#include <iostream>
#include <fstream>

using namespace std;

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
} //将两个元素进行交换

int jc(int a){
    if(a==1){
        return 1;
    }
    return a*jc(a-1);
}//求阶乘的函数

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
}//获得这个序列的字典数，方法就是对于这个序列的每一位，假设该为为第m位，由内层循环找这一位后面有几个
 //比他小的数，假设有n个，序列长度为s。那第m位的字典数就是n*(s-m-1)!，整个序列的字典数就是每一位的和
 //以题目给定条件为例
 //        2 6 4 5 8 1 7 3
 //        比2小的个数有1个，所以tal+=1*7！
 //        比6小的个数有4个，所以tal+=4*6！
 //        比4小的个数有1个，所以tal+=2*6！
 //        比5小的个数有1个，所以tal+=2*4！
 //        比8小的个数有1个，所以tal+=3*3！
 //        比1小的个数有1个，所以tal+=0*2！
 //        比7小的个数有1个，所以tal+=1*1！
 //        比3小的个数没有

int* getNextSeq(int *array, int n){
    int temp1, temp2;
    for (int i=n-2; i>=0; i--){
        if(array[i]<array[i+1]){
            temp1=i;
            break;
        }
    }//第一个for循环找到满足a[i]<a[i+1]的数
    for (int i=n-1; i>=0; i--){
        if(array[i]>array[temp1]){
            temp2=i;
            break;
        }
    }//第二个for循环找到第一个大于a[temp1]的数
    swap(array[temp1], array[temp2]);
    int tempn=n;
    for (int i=temp1+1; i<n; i++){
        swap(array[i], array[--tempn]);
    }//第三个for循环将倒序排列转为顺序排列
    return array;
}/*该函数返回对应的下一个序列。以序列a[8]={1, 2, 3, 4, 5, 6, 7, 8}为例，枚举寻找规律如下
           1 2 3 4 5 6 7 8
           1 2 3 4 5 6 8 7
           1 2 3 4 5 7 6 8
           1 2 3 4 5 7 8 6
           1 2 3 4 5 8 6 7
           1 2 3 4 5 8 7 6
           1 2 3 4 6 5 7 8
    可以观察到，我们每次交换时，从序列的末尾到序列的开头最先找到的是符合以下规律的一个数: 
    满足a[i]<a[i+1]。记录下此时的i值使用temp1表示，该数是序列末尾开始第一个满足a[i]<a[i+1]
    的数，就意味着该数以后的数组成的子序列满足完全的倒序，子序列字典数达到最大，字典数再加一的序列
    只能从这里开始变化。)。
    接着从序列的末尾开始找第一个大于a[temp1]的数,，用temp2记录下此时该数对应的i值。此时可以证明
    temp2>temp1 (a[temp1]满足a[temp1]<a[temp1+1],所以temp2至少也应该是temp1+1),并且可以证明
    a[temp2]为子序列{a[temp1+1], ……, a[temp2]}中最小的(a[temp1+1]>a[temp1+2]>……>a[temp2])
    于是类比于加法进位。我们可以将这两个数交换。然后将交换完成后的子序列{a[temp1+1], ……, a[temp2]}
    重新按照升序排列，有以上分析知该子序列为完全倒序(字典数最大)，于是可以使用for循环交换最大和最小
    (即a[temp1+1](子序列中最大的)和a[n-1](子序列中最小的), a[temp1+2](子序列中第二大的)
    和a[n-2](子序列中第二小的)……)来将后面的元素顺序排列。因此得到了字典序的下一序列
    
    以题目中数据为例
           2 6 4 5 8 1 7 3
    1.先从尾部找到第一个a[i]<a[i+1]的位置
           2 6 4 5 8 1< 7 3,那么找到了1
      最终找到1是最小的位置，记录1所在的位置i为temp1
    2.从尾部开始往前找第一个大于1的数，
           2 6 4 5 8 1 <7 3,那么找到了3记录为temp2
      最终找到了3，则此时记录3所在的位置m
    3.交换1和3的位置--2 6 4 5 8 3 7 1
    4.此时倒序i位置以后的所有数据
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
```

