#include <stdio.h>

#define N 10
void main()
{
	FILE *fp;
	fp=fopen("f.txt", "rwb"); 
 int i,j,a[N][N];
 for(i=0;i<N;i++)
  {
   a[i][0]=1;
   a[i][i]=1;
  }
 for(i=2;i<N;i++)  /*�δ˴��±��2��ʼ*/
   for(j=1;j<i;j++) /*�˴��±��1��ʼ*/
     a[i][j]=a[i-1][j-1]+a[i-1][j];
 for(i=0;i<N;i++)
  {
    for(j=0;j<=i;j++)  
       printf("%d ",a[i][j]);  /*��֪������©�����л�����ô������֮��ӡ����ʱ�����*/
    printf("\n");
  }
  	fwrite(a,sizeof(int),100,fp);
  	fclose(fp);
  	
}
