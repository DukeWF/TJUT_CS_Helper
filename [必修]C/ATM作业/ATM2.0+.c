//�ṹ���ATMģ�����
/*
��	��������ʵ�ֵĹ���Ϊ
��	1.�˻���Ϣ��¼���ļ��У�
��	2.���ýṹ���γ��˻�ID�����룬��������ǰ���˻�״̬ 
��	3.�̿���ʽ�Ż����ȶ�ID�����룬���δ�����ʾ�̿�+������˻����˻�����״̬��Ϊ0��
��	4.ʵ�ֹ��ܣ���ѯ��ȡ����޸����룬��Щ�����������ļ�������
��	5.�¹��ܣ�������־��¼--������ѯ����ȡ������룬��¼�˻��Ȳ�������ʽΪ��ʱ��--����(��ʱ�޷�ʵ��)
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h> 
//#include <time.h>
#include <math.h>

#define NAME 20 
#define PW 7
//#define system("pause") pause
//#define system("cls") cls
//�ṹ�� 
struct user_list
	{
		int id;
		char name[NAME];
		int password; 
		float money;
		int condition; //���Ʋ���ֵ��0==���ã�1==���� 
	}det[100];
//ԭ������	
void delay();

int welcome();
void menu(int len,struct user_list det[],int i);

int get_id();
int check_id(int id,struct user_list det[]);
int get_point(int id,struct user_list det[]);
int get_password();
int check_password(int len,int pw,struct user_list det[],int temp);

int dm(int len,struct user_list det[],int i);
int lm(int len,struct user_list det[],int i);
int wm(int len,struct user_list det[],int i);

void change(int len,struct user_list det[],int i);
void write_SQL(int len,struct user_list det[]);

void delay()
    {
     	int z;
		printf("���Ժ����ڴ�����");
		for(z=0;z<3;z++)
		{
			sleep(1);
			printf(".");
			fflush(stdout); 
		}
    }

int get_ID()
	{
		int ID;
		printf("ID:");
		scanf("%d",&ID);
		return ID;
	}

int check_ID(int ID, struct user_list det[])
	{
		FILE * fp = fopen("SQL.txt","r");
		FILE * log = fopen("log.txt","a+");
		int temp = -1;
		int count = 0;
		while(fscanf(fp,"%d %s %d %f %d",&det[count].id,&det[count].name,&det[count].password,&det[count].money,&det[count].condition)>0)
			{
				if(ID == det[count].id)
					{
						temp = count;
					}
				count++;
			}
		if(temp == -1)
			{
				printf("\nδ�ҵ��˻�!������\n");
				system("pause");
				exit(-1);
			}
		else
			{
				fprintf(log,"%d try to sign in the system.\r\n",det[temp].id);
				if(det[temp].condition == 0)
					{
						printf("\n�˻��ѱ����ᣬ����ϵ����Ա��\n");
						fprintf(log,"%d was stopped to sign in the system.\r\n",det[temp].id);
						exit(-2);
					}
				return count;
			}	
	}
	
int get_point(int ID,struct user_list det[])
	{
		int temp;
		int count = 0;
		while(1)
		{
			if(ID == det[count].id)
			{
				temp = count;
				return temp;
			}
			count++;
		}
	}	
	
int get_password()
	{
		char pw[PW];
		int i,t=0;
		printf("\nPassword:");
		for(i=0;i<6;i++)
		{
			pw[i] = getch();
			t += (pw[i]-'0')*pow(10,5-i);
			printf("*");
		}
		getch();
		return t;
	}
	
int check_password(int len,int pw,struct user_list det[],int temp)
	{

		FILE * data = fopen("log.txt","a+");//append+ 
		int count_Error = 0;
		while(1)
		{
			if(pw != det[temp].password)
			{
				printf("\n�������\n");
				count_Error++;
				fprintf(data,"%d password error in %d times.\r\n",det[temp].id,count_Error);
				if(count_Error>2)
				{
					printf("\n�˻��ѱ����ᣡ����ϵ����Ա\n");
					fprintf(data,"%d The count has been frazed!\r\n",det[temp].id);
					det[temp].condition = 0;
					write_SQL(len,det);
					exit(-2);
				}
				pw = get_password();
			}
			if(pw == det[temp].password)
			{
				printf("\n������ȷ��\n");
				fprintf(data,"%d sign in the system succeed.\r\n",det[temp].id);
				break;
			}
		}	
	}
	
int welcome()
	{
		int ID,len,pw,point;
		
		printf("��ӭʹ�ã�����������ID�����룬���Իس�������\n");
		ID = get_ID();
		delay();
		len = check_ID(ID, det);
		
		point = get_point(ID,det);
		
		pw = get_password();
		check_password(len,pw,det,point);
		delay();
		
		system("pause");
		system("cls");
	}

void menu(int len,struct user_list det[],int i)
	{
		printf("��ӭʹ��ATM�����������Ӧ��ĸ���ж�Ӧ����\n");
		printf("a.���\nb.ȡ��\nc.��ѯ���\nd.�����޸�\nq.�˳�ȡ��\n"); 
		char ch;
		scanf("%c",&ch);
		while((ch=getchar())!='q')
			{
				switch(ch)
					{
						case'a':dm(len, det, i);
						case'b':wm(len, det, i);
						case'c':lm(len, det, i);
						case'd':change(len, det, i);
						default:if((ch=getchar())=='q') 
									exit(0);
								else
									{								
										printf("ѡ����������\n"); 
										system("pause");
										system("cls");
										menu(len,det,i);
									}
					}
			}
		
	}
	
int dm(int len,struct user_list det[],int i)
	{
		FILE * log = fopen("log.txt","a+");
		int temp;
		printf("\n����������.\n");
		scanf("%d",&temp);
		delay();
		if(temp%100==0) 
			{
				det[i].money += temp;
				write_SQL(len,det);
				printf("\n���ɹ�����ǰ�˻����Ϊ %.2f\n",det[i].money);				
				fprintf(log,"%d deposit money %d succeed.\r\n",det[i].id,temp);	
		    }
		else 
			{
				printf("�����Ƿ���");
			    fprintf(log,"%d deposit money %d error.\r\n",det[i].id,temp);
			}    
		system("pause");
		system("cls");
		menu(len,det,i);
	}

int wm(int len,struct user_list det[],int i)
	{
		FILE * log = fopen("log.txt","a+");
		int temp;
		printf("\n������ȡ���\n");
		scanf("%d",&temp);
		delay();
		if(temp>det[i].money)
			{
				printf("\n��������\n");
				fprintf(log,"%d draw money %d error.\r\n",det[i].id,temp);
			}
		else
			{
				det[i].money -= temp;
				printf("\nȡ��ɹ�����ǰ�˻����Ϊ %.2f\n",det[i].money);
				write_SQL(len,det);
				fprintf(log,"%d draw money %d succeed.\r\n",det[i].id,temp);	
			}
		system("pause");
		system("cls");
		menu(len,det,i);
	}
	
int lm(int len,struct user_list det[],int i)
	{
		FILE * log = fopen("log.txt","a+");
		delay();
		printf("\n��ǰ�˻����Ϊ %.2f\n",det[i].money);
		fprintf(log,"%d check the money.\r\n",det[i].id);
		system("pause");
		system("cls");
		menu(len,det,i);

	}

void change(int len,struct user_list det[],int t)
	{
		FILE * log = fopen("log.txt","a+");
		char pin_1[10];
		char pin_2[10];
		int x1 = 0, x2 = 0;
		int i;
		printf("\n�����������룬�Իس����� \n");
		for(i=0;i<6;i++)
		{
			pin_1[i] = getch();
			x1 += (pin_1[i]-'0')*pow(10,5-i);
			printf("*");
		}
		getch();
		
		printf("\n���ٴ����������룬�Իس����� \n");
		for(i=0;i<6;i++)
		{
			pin_2[i] = getch();
			x2 += (pin_2[i]-'0')*pow(10,5-i);
			printf("*");
		}
		getch();
		if(x1 == x2)
		{
			det[t].password = x1;
			write_SQL(len,det);
			printf("\n�����޸ĳɹ���\n");
			fprintf(log,"%d change password succeed.\r\n",det[t].id);	
		}
		else		
			{
				printf("\n�����޸�ʧ�ܣ�\n");
				fprintf(log,"%d change password error.\r\n",det[t].id);
			}
		system("pause");
		system("cls"); 
		menu(len,det,t);	
	}

//
void write_SQL(int len,struct user_list det[])
	{
		int i;
		FILE * fp = fopen("SQL.txt","w");
		for(i =0;i<len;i++)
			{
				fprintf(fp,"%d %s %d %.2f %d\r\n",det[i].id, det[i].name, det[i].password, det[i].money, det[i].condition);
			}
		fclose(fp);
			
	}

int main()
	{
		FILE *fp;
		int ID;
		int len;
		int pw;
		int point; 
		
		welcome();

		menu(len,det,point);
		fclose(fp);
		printf("�뱣�ܺ��������п�����ӭ�´�ʹ�ã�");	
		exit(0); 
	} 

