//P281 T9
#include <stdio.h>
#define WID 4
void show_arr(int arr[], int length)
	{
		int i;
		for(i=0;i<length;i++)
			printf("%d, ", arr[i]);
	}
int sum_arr(int *arr1, int *arr2, int *arr3, int length)
	{
		int i;
		for(i=0;i<length;i++)
			arr3[i]=arr1[i]+arr2[i];
	}
int main()
	{
		int a[WID]={2,4,5,8};
		int b[WID]={1,0,4,6};
		int c[WID];
		sum_arr(a,b,c,WID);

		show_arr(c,WID);
		
		return 0;
	}
 
