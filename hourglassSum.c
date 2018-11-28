#include<stdio.h>
#include<stdlib.h>

int main()
{
 int arr[6][6]={{-9,-9,-9,1,1,1},
		{0,-9,0,4,3,2},
		{-9,-9,-9,1,2,3},
		{0,0,8,6,6,0},
		{0,0,0,-2,0,0},
		{0,0,1,2,4,0}};
/*take any 6x6 matrix give the correct output
  but if max is less than -200 tnen dec the max size*/

int i,j,k,g=0,max=-200;
int kk,m,p,c,sum=0,sum1=0,sum2=0;
m=1;
c=1;
kk=0;
p=0;
for(int mm=0;mm<4;mm++)
{
	for(i=p;i<4;i++)
	{	
		if(4>i)
		{
			for(j=m;j<5;j++)
			{
				for(k=p;k<5;k++)
				{
					sum=sum+arr[kk][i]+arr[kk][i+1]+arr[kk][i+2];
					kk++;
					//printf("%d ",sum);
					sum1=sum1+arr[kk][j];
					kk++;
					//printf(" %d ",sum1);
					sum2=sum2+arr[kk][i]+arr[kk][i+1]+arr[kk][i+2];
					//printf(" %d\n",sum2);
					sum=sum+sum1+sum2;
					if(max<sum)
						max=sum;
					if(c==1)
						break;
				}
				if(c==1)
					break;
			}
			kk=kk-2;
			m++;
			p++;
			sum=0;
			sum1=0;
			sum2=0;
		}
	}
	kk++;
	p=0;
	m=1;
}

printf("%d\n",max);
return 0;
}
