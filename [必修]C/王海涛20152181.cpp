# include<stdio.h>
int money=0;
int mi=123456;
char get_first();
char get_choice()
{
	int ch;
	printf("请选择你需要的服务：\na.查询  b.存款  \nc.取款  d.改密  \ne.取卡\n");
	ch=get_first();
	printf("%c",ch);
	while((ch<'a' || ch>'d') && ch !='e')
	{
		printf("请正确选择选项！\n");
		ch=get_first();
	}
	return ch;
}
char get_first()
{
	char ch;
	ch=getchar();
	while(getchar()!='\n')
	{
		continue;
	}
	return ch;
}
int main()
{
	int key=666666;
	int a,i,m,n;
	i=1;
	printf("请输入密码：  ");
	scanf("%d",&a);
	while(i<4)
	{
		if(a==key)
		{
		int choice;
		while ((choice=get_choice())!='e')
		{
			switch(choice)
			{
				case 'a':
				
					printf("你的账户余额为%d！\n",money);
					break;
				case 'b':
					printf("请输入您存入的金额  ");
					scanf("%d",&m);
					money=money+m;
					printf("你的账户余额为%d！\n",money);
					break;
				case 'c':
					printf("请输入取款金额  ");
					scanf("%d",&n);
					printf("你的账户余额为%d！\n");
					break; 
				case 'd':
					printf("请输入新密码！");
					scanf("%d",mi);
					break;
				case 'e':
					printf("请取走您的卡片！ByeBye!");
					break;
			}
		}
		}
		else
		{
			if(3-i>0)
			{printf("密码错误，还有%d次输入次数。\n请输入密码：   ",3-i);
			i++;
			scanf("%d",&a);
			}
			else
			{
				printf("三次密码输入错误，已吞卡！"); 
				return 0;
			}
			
			
		}
	}
	return 0;
}


