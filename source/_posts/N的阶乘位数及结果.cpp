#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int calc(unsigned int n);
int length(int n);//����λ�� 
int main(void)
{
	int a[500];
	int i=0;
	//���� 
	while(0<=i<=499){
	    scanf("%d",&a[i]);
        if(a[i]==-1)
	    break;
	    i++;
	}
	i=0;
	//��� 
	while(0<=i<=499){
		if(a[i]==-1)
        break;
		calc(a[i]);//��������5000�Ľ׳�
		i++;
	}
	return 0;
}
int calc(unsigned int n)
{
	const int max = 10000;/*������ÿ��Ԫ�ش洢�����ݲ�����max*/
	int array[5000];/*�øø�����洢����*/
	int arrayNow = 0;/*��������õ��˵ڼ�λ*/
	unsigned int num=1;/*����׳���*/
	int i,j,temp;
	int left;/*��λ�����*/
	
	
	memset(array,0,5000*sizeof(int));/*��ʼ������*/
	if(n<3)/*С��3�Ͳ�������*/
	{
		return n;	
	}
	if(n>5000)
	{
		return -1;	
	}
	
	array[0] = 1;
	while(num<=n)//д��׳˵�����
	{
		left = 0;/*��0λû����һλ��λ*/
		for(i=0;i<=arrayNow;i++)/*�м�¼������λ�ö���Ҫ��num*/
		{
			temp = array[i]*(int)num;/*��ǰ����Ԫ����num���*/
			temp+=left;              /*������һ��Ԫ�صĽ�λ*/ 
			array[i] = temp%max;/*��¼��ǰԪ��*/
			left = temp/max;/*��¼��λ*/
		}	
		if(left>0)/*�����λ*/
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
			printf("����\n");
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