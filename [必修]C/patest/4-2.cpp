#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;
				
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

/* 你的代码将被嵌在这里 */
#include<math.h>
double f( int n, double a[], double x )
{
	int i;
	double sum=0;
	for(i=0;i<=n;i++)
		{
			sum+=(double)(a[i]*pow(x,i));
		}
	return sum;
}
