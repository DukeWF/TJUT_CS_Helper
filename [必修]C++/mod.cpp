#include<stdio.h>  
int Mod(int a, int b)  
{  
    return a % (b+1);  
}  
int main()  
{  
    int T, n;  
    scanf("%d", &T);  
    while(T--)  
    {  
        scanf("%d", &n);  
        int s = 0;  
        while(n--)  
        {  
            int a, b;  
            scanf("%d%d", &a, &b);  
            s ^= Mod(a, b);  
        }  
        if(s)  
            puts("MK");  
        else  
            puts("JYZ");  
    }  
    return 0;  
}  
