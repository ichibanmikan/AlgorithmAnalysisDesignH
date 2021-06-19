#include<bits/stdc++.h>
#include <fstream>
#define INF 60000
#define n 4

using namespace std;

ifstream infile("in.txt");
int** a;
int  bestc=INF;
int* bestx;
int* minout;
int sum_minout;
class Node{
    public:
        int t_;
        int ccost_;
        int least_cost_;
        int* x_;
        void Init_Node(Node node ,int i);
        void swap(int t_,int i){
            int y =x_[t_];
            x_[t_]=x_[i];
            x_[i]=y;       
        }
        bool Judge();
        bool operator < (const Node &a) const{
            return least_cost_ > a.least_cost_;
        }
        friend void Branch_bound();
};
void Node::Init_Node(Node node ,int i){
    t_=node.t_+ 1;
    x_=new int [n];
    for(int i=0;i<n;i++)
        x_[i]=node.x_[i];
    swap(t_, i);
    ccost_=node.ccost_ + a[x_[t_]][x_[t_- 1]];
    least_cost_=ccost_;
    for(int i=t_;i<n;i++){
        least_cost_ += minout[i];
    }
}
bool Node::Judge(){   
    if(t_==n-1){   
        if(a[x_[t_- 1]][x_[t_]]!=INF &&a[x_[t_]][x_[0]]!=INF
        &&ccost_ + a[x_[t_]][x_[0]]< bestc){
              ccost_ += a[x_[t_]][x_[0]];
              return true;
        }
    } else {         
        if(a[x_[t_]][x_[t_- 1]]!=INF)
            if(least_cost_ < bestc)
             return true;
    }
    return false;
}
void Init(){
    a=new int*[n+1];
    for(int i=1;i<=n;i++){
       a[i]=new int [n+1];
    }
    //初始化邻接矩阵
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=INF;
        }
    }
    //输入边和相应的权重
    int edgenum;
    infile >> edgenum;
    for(int i=0;i<edgenum;i++){
        int s,e,w;
        infile >> s >> e >> w;
        a[s][e]=w;
        a[e][s]=w;
    }

    minout=new int[n];
    for(int i=1;i<=n;i++){
            int min_=INF;
        for(int j=1;j<=n;j++){
            if(a[i][j]<min_)
              min_=a[i][j];
      }
      minout[i-1]=min_;
      sum_minout += min_;
    }
}
priority_queue<Node> que;
void Branch_bound(){
    Node* a;
    a=new Node;
    a->t_=0;
    a->ccost_=0;
    a->least_cost_=sum_minout;
    a->x_=new int [n];
    for(int i=0;i<n;i++)
        a->x_[i]=i + 1;
    que.push(*a);
    //
    while(!que.empty()){           //队列不为空的话
        Node* node;
        for(int i=que.top().t_+ 1;i<n;i++){
           node=new Node;
           node->Init_Node(que.top(),i);
           if(node->Judge())
             que.push(*node);
           else
            delete node->x_;
        }
        if(que.top().t_==n-1){       //根节点位于优先队列头则直接更新最优值，结束循环
            bestc=que.top().ccost_;
            bestx=que.top().x_;
            break;
        }
        que.pop();
    }
}
void print(){
    cout << "最小距离为: "<< bestc <<endl;
    cout << "对应路径为: " ;
    for(int i=0;i<n;i++){
        cout << bestx[i] << " ";
    }
    cout << 1;
}

int main(){
     Init();
     Branch_bound();
     print();
     return 0;
}
// 6
// 1 2 30
// 1 3 6
// 1 4 4
// 2 3 5
// 2 4 10
// 3 4 20
