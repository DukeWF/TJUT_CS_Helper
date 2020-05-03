#include <stdio.h>

#define MAXN 10

int Sum ( int List[], int N );

int main ()
{
    int List[MAXN], N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%d", &List[i]);
    printf("%d\n", Sum(List, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
int Sum ( int List[], int N )
{
	int i;
	int sum=0;
	for(i=0;i<N;i++)
		sum+=List[i];
	return sum;
}
