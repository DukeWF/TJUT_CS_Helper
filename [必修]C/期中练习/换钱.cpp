/*
	Name: 
	Description:
	1.
	2.
		2.1:
		2.2:
	3.
	Time Complexity£º O()-O()-O()
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;


int main(){
	char temp[100];
	scanf("%s",temp);
	char *a = new char(strlen(temp));
	for(int i=0;i<strlen(temp);i++){
		a[i]=temp[i];
	}
	printf("%s, %d",a,strlen(a));
	

}

