#include <stdio.h>
#include <math.h>
//斯特林(Stirling)公式求解阶乘的位数
#define PI 3.141592654
#define E 2.71828182846
int length(int n)
{
    int s=1;
    if(n>3)
        s=log10(2*PI*n)/2+n*log10(n/E)+1;
    return s;
}
//斯特林(Stirling)公式求解阶乘的位数
int main(void){
	int a[500]={0};
	int i=0;
	//input 
	while(0<=i<=499){
		scanf("%d",&a[i]);
		if(a[i]==-1)
		break;
		i++;
		
	}
	i=0;
	//output
	while(0<=i<=499){
		if(a[i]==-1)
		break;
		printf("%d\n",length(a[i]));
		i++;
	}
	return 0;
}