#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int calc(unsigned int n);
int length(int n);//计算位数 
int main(void)
{
	int a[500];
	int i=0;
	//输入 
	while(0<=i<=499){
	    scanf("%d",&a[i]);
        if(a[i]==-1)
	    break;
	    i++;
	}
	i=0;
	//输出 
	while(0<=i<=499){
		if(a[i]==-1)
        break;
		calc(a[i]);//最大可以求5000的阶乘
		i++;
	}
	return 0;
}
int calc(unsigned int n)
{
	const int max = 10000;/*数组中每个元素存储的数据不超过max*/
	int array[5000];/*用该个数组存储数据*/
	int arrayNow = 0;/*标记数组用到了第几位*/
	unsigned int num=1;/*计算阶乘用*/
	int i,j,temp;
	int left;/*进位相加数*/
	
	
	memset(array,0,5000*sizeof(int));/*初始化数组*/
	if(n<3)/*小于3就不计算了*/
	{
		return n;	
	}
	if(n>5000)
	{
		return -1;	
	}
	
	array[0] = 1;
	while(num<=n)//写入阶乘到数组
	{
		left = 0;/*第0位没有上一位进位*/
		for(i=0;i<=arrayNow;i++)/*有记录的数组位置都需要乘num*/
		{
			temp = array[i]*(int)num;/*当前数组元素与num相乘*/
			temp+=left;              /*加上上一个元素的进位*/ 
			array[i] = temp%max;/*记录当前元素*/
			left = temp/max;/*记录进位*/
		}	
		if(left>0)/*填充新位*/
		{
			array[++arrayNow] = left;
		}
		num++;
	}
    int length1=0;
	for(i=arrayNow;i>=0;i--)
	{
		if(array[i]>=max)
		{
			printf("出错\n");
			return -1;	
		}	
		if(i==arrayNow)
		{
			printf("%d",array[i]);
			length1+=length(array[i]);
			
		}	
		else
		{
			printf("%d",array[i]/1000);
			printf("%d",array[i]/100 - (array[i]/1000)*10);
			printf("%d",(array[i]%100)/10);
			printf("%d",array[i]%10);
			length1+=length(array[i]/1000);
			length1+=length(array[i]/100 - (array[i]/1000)*10);
			length1+=length((array[i]%100)/10);
			length1+=length(array[i]%10);
		}
	}
	printf("\n");
	printf("%d",length1);
    return 0;
}
int length(int n){
	int count = 1;
    while (n /= 10)
    count++;
    return count;
}