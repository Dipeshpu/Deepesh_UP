#include<stdio.h>
#include<string.h>
char str1[5000],str2[5000];
int c[5000][5000];
int main()
{
  int i,j,m,n;
  scanf("%s %s",str1+1,str2+1);
  m=strlen(str1+1);
  n=strlen(str2+1);
  for(i=0;i<=m;i++)
	c[i][0]=0;
  for(j=0;j<=n;j++)
	c[0][j]=0;
  for(i=1;i<=m;i++)
   for(j=1;j<=n;j++)
      {
	if(str1[i]==str2[j])
	  c[i][j]=c[i-1][j-1]+1;
	else if(c[i-1][j]>=c[i][j-1])
	  c[i][j]=c[i-1][j];
	else
	  c[i][j]=c[i][j-1];
      }
  printf("%d\n",c[m][n]);
  return 0;
}
