#include <stdio.h>  
#include <string.h>  
void output(char *str)  
{  
  char* tail = strchr(str,' ');  
  if (tail == NULL)  
    printf("%s",str);  
  else  
    {  
//    printf("µØÖ·£º%d\n",tail);
      output(tail + 1);  
      *tail = '\0';  
      printf(" %s",str);  
    } 
}  

int main()  
{  
  char str[81];  
  gets(str);  
  output(str);  
  putchar('\n');  
  return 0;  
}  

