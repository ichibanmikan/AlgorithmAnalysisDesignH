#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int n,k,*a;

int select(int a[], int l, int r){
    while (true){
        if (l>=r)
            return a[l];    
        int i=l, j=l+rand() % (r-l+1);//随机选择划分基准
        swap(a[i], a[j]);
        j=r+1;
        int pivot=a[l];
        while(true){
            while (i<r&&a[++i] < pivot);
            while (j>l&&a[--j] > pivot);
            if (i>=j)
                break;
            swap(a[i], a[j]);
        }
        if(j-l+1==k)//如果最后基准元素在第k个元素的位置，则找到了第k小的元素
            return pivot;
        a[l]=a[j];
        a[j]=pivot;
        if (j-l+1 < k){
            k=k-(j-l+1);//基准元素右侧,求出相对位置 
            l=j+1;
        } else{    //基准元素左侧 
            r=j-1;
        }//对子数组重复划分过程
    }
}
 
void fileinput(){
    ifstream infile("in.txt");
    infile>>n>>k; 
    a=new int[n];
    for(int i=0;i<n;i++)
            infile>>a[i];
    infile.close();
}

int main(){
    srand(time(NULL));
    int r;
    fileinput();
    cout<<"n="<<n<<"\tk="<<k<<endl;
    LARGE_INTEGER litmp;
    LONGLONG Qpart1,Qpart2; 
    double dfMinus,dfFreq,dfTime;
    QueryPerformanceFrequency(&litmp);
    dfFreq=(double)litmp.QuadPart;
    QueryPerformanceCounter(&litmp);
    Qpart1=litmp.QuadPart;    
    //开始计时
    r=select(a,0,n-1);
    //结束计时
    QueryPerformanceCounter(&litmp);
    Qpart2=litmp.QuadPart;        
    dfMinus=(double)(Qpart2-Qpart1);        
    dfTime =dfMinus / dfFreq;
    cout<<"结果:"<<r<<endl;
    cout<<"Time:"<<setiosflags(ios::fixed)<<setprecision(8)<<dfTime<<"s\n"<<endl;
    return 0; 
}
