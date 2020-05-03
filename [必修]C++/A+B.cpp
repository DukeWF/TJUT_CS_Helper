#include <stdio.h>

int main(){
    int num,a,b,i;
    scanf("%d",&num);
    for(i=1;i<=num;i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",a+b); 
    }
    return 0;
}
