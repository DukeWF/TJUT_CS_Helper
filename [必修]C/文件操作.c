#include <stdio.h>
#include <stdlib.h>

int main()
	{
		int ch;
		FILE *fp, *fpw;
		char fname[50];
		char fnamew[50];
		
		printf("�������ļ�����");
		scanf("%s", fname);
		printf("���������ļ�����");
		scanf("%s", fnamew);
		
		fp=fopen(fname, "r");
		fpw=fopen(fnamew, "w");
		
		if(fp==NULL || fpw==NULL)
			{
				printf("ERROR!");
				exit(1);
			}	
			
		while((ch=getc(fp))!=EOF)
			{
				putchar(ch);
				putc(ch, fpw);
			}
			
		fclose(fp);
		fclose(fpw);
		return 0;	
	}
