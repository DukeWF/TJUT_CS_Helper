//Test`"if"
#include <stdio.h>
int main(){
	int a[2]={1,0};
	if(a[0]==a[1]){
		return 1;
	}
	else if(a[0]=a[1]){//¸³Öµ 
		printf("%d,%d",a[0],a[0]);
		return 2;
	}
	return 0;
} 
