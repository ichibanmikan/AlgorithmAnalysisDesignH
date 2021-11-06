#include<iostream>
#include<cmath>

using namespace std;

double x,y,c;

double fun(double w){
    return 1-c/sqrt(y*y-w*w)-c/sqrt(x*x-w*w);
}

int main(){ 
    while(cin >> x >> y >> c){
        double l=0, m, r;
        r=x>y?y:x;
        while(r-l>10e-8){
            m=(l+r)/2;
            if(fun(m)>0){
                l=m;
            }
            else{
                r=m;
            } 
        }
        printf("%.3f\n", m);
    }
}
