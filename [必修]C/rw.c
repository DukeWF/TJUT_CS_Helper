/*******************简单文件读写操作********************/ 
/**Copyright 1997-2016 Tony Wang. All Rights Reserved.**/ 
/*******************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
	{
		char ch;
		FILE *f_input,*f_output;
		
		int arr[20][30]={0};
		int i=0;
		
		if(argc<3)
			{
				printf("Usage: copyfile source destination.\n");
				exit(-1);
			}
//		
		f_input = fopen(argv[1], "r");
		if(f_input==NULL)
			{
				printf("Error: failed to open source file.\n");
				exit(-2);
			}
		f_output = fopen(argv[2], "w");
		if(f_output==NULL)
			{			
				printf("Error: failed to open destination file.\n");
				exit(-2);
			}
//		
	while((ch=getc(f_input))!=EOF)
	{
		switch(ch)
		{
			case '\n':putc('\n',f_output);
				break;	
			case '9':putc('#',f_output);
				break;		
			case '8':putc('%',f_output);
				break;						
			case '7':putc(';',f_output);
				break;	
			case '6':putc('=',f_output);
				break;
			case '5':putc('*',f_output);
				break;
			case '4':putc('~',f_output);
				break;
			case '3':putc(':',f_output);
				break;	
			case '2':putc('\'',f_output);
				break;
			case '1':putc('.',f_output);
				break;
			case '0':putc(' ',f_output);
				break;
			case ' ':
				break;
	    }
		arr[i/30][i%30]=ch-'0'+0;
		i++;
	}
//记得关闭程序！	
		fclose(f_input);
		fclose(f_output);
			
	}
