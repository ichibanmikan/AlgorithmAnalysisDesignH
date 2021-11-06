#include <cstdio>

using namespace std;

int main(){
	long long m,n;
	scanf("%I64d%I64d",&m,&n);
	while(m!=0||n!=0){   
		int num=0;
		long long z=m^n;
		while(z){
			z&=(z-1);    
			num++;	
		}
		printf("%d\n",num);
		scanf("%I64d%I64d",&m,&n);
	}
	return 0;
}