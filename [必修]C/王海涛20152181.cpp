# include<stdio.h>
int money=0;
int mi=123456;
char get_first();
char get_choice()
{
	int ch;
	printf("��ѡ������Ҫ�ķ���\na.��ѯ  b.���  \nc.ȡ��  d.����  \ne.ȡ��\n");
	ch=get_first();
	printf("%c",ch);
	while((ch<'a' || ch>'d') && ch !='e')
	{
		printf("����ȷѡ��ѡ�\n");
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
	printf("���������룺  ");
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
				
					printf("����˻����Ϊ%d��\n",money);
					break;
				case 'b':
					printf("������������Ľ��  ");
					scanf("%d",&m);
					money=money+m;
					printf("����˻����Ϊ%d��\n",money);
					break;
				case 'c':
					printf("������ȡ����  ");
					scanf("%d",&n);
					printf("����˻����Ϊ%d��\n");
					break; 
				case 'd':
					printf("�����������룡");
					scanf("%d",mi);
					break;
				case 'e':
					printf("��ȡ�����Ŀ�Ƭ��ByeBye!");
					break;
			}
		}
		}
		else
		{
			if(3-i>0)
			{printf("������󣬻���%d�����������\n���������룺   ",3-i);
			i++;
			scanf("%d",&a);
			}
			else
			{
				printf("������������������̿���"); 
				return 0;
			}
			
			
		}
	}
	return 0;
}


