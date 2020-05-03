#include <stdio.h>
int main ()
	{
		while(1)
			{
				printf("Enter the operation of your choice:\n");
				printf("a.add      s.subtract\n");
				printf("m.multiply d.divede\n");
				printf("q.quit\n");
				float x,y,z;
				char choice;
				scanf("%c",&choice);
				switch(choice)
					{
						case 'a':printf("Enter first number:");
						if(scanf("%f",&x))
							{
								printf("Enter second number:");
								if(scanf("%f",&y))
									{
										z=x+y;
										printf("%f\n",z);
									}
								else
									{
										getchar();
										printf("Input is not a number\n");
										printf("Please enter a number,such as 2.5 -1.78E8,or 3:");
										scanf("%f",&y);
									}	
							}
						break;	
						case 's':printf("Enter first number:");
						if(scanf("%f",&x))
							{
								printf("Enter second number:");
								if(scanf("%f",&y))
									{
										z=x-y;
										printf("%f\n",z);
									}
								else
									{
										getchar();
										printf("Input is not a number\n");
										printf("Please enter a number,such as 2.5 -1.78E8,or 3:");
										scanf("%f",&y);
									}
							}	
						break;
						case 'm':printf("Enter first number:");
						if(scanf("%f",&x))
							{
								printf("Enter second number:");
								if(scanf("%f",&y))
									{
										z=x*y;
										printf("%f\n",z);
									}
								else
									{
										getchar();
										printf("Input is not a number");
										printf("Please enter a number such as 2.5 -1.78E8.or 3:");
										scanf("%f",&y);
									}	
							}
						break;
						case 'd':printf("Enter first number:");
						if(scanf("%f",&x))
							{
								printf("Enter second number:");
								if(scanf("%f",&y))
									{
										while(y==0)
											{
												printf("Enter a number other than 0:");
												scanf("%f",&y);
											}
										//else
										//	{
												z=x/y;
												printf("%f\n",z);
									}
										break;
							}
								else
									{
										printf("Input is not a number");
										printf("Please enter a number such as 2.5 -1.78E8,or 3");
										scanf("%f",&y);
									}				
									
						break;	
						case 'q':return 0;	
					}
			}
	}
