//�ṹ���ATMģ�����
/*
��	��������ʵ�ֵĹ���Ϊ
��	1.�˻���Ϣ��¼���ļ��У�
��	2.���ýṹ���γ��˻�ID�����룬��������ǰ���
��	3.�̿���ʽ�Ż����ȶ�ID�����룬���δ�����ʾ�̿�+������˻����˻�����״̬��Ϊ0��
��	4.ʵ�ֹ��ܣ���ѯ��ȡ����޸����룬��Щ�����������ļ�������
��	5.�¹��ܣ�������־��¼--������ѯ����ȡ������룬��¼�˻��Ȳ�������ʽΪ��ʱ��--����
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define pw 6
#define nm 100
#define id 19
#define money_max 10000000000

struct account {
	char ID[id];
	char name[nm];
	int password[pw];
	int money;	
};

void welcome(char *p_id, int *p_pw)
	{
		printf("��ӭʹ�ã�����������ID�����룬���Իس�������\n");
		printf("ID:___________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%c", &p_id);
		printf("\npassword:______\b\b\b\b\b\b"); 
		scanf("%d", &p_pw);
		printf("���Ժ����ڴ�����......");
		system("pause"); 
	}
void menu(){
	system("cls");
	printf("\t\t**********��ӭʹ���й�����*********\n");
	printf("\t\t����aȡ��\t\t����b���.\n");
	printf("\t\t����cת��\t\t����d��ѯ.\n");
	printf("\t\t����t�˳�\t\t����e������.\n");
}	
void pass(int id){
	system("cls");
	FILE *file;
	struct account stud;
	file=fopen("a.txt","rb+");
	if(file==NULL){
		printf("cannot open the file!");
		exit(1);
	}
	rewind(file);
	int m;
	printf("������Ҫת�˵Ľ��:");
	scanf("%d",&m);
	while(fread(&stud,sizeof(struct account),1,file)==1){
		if(stud.id==id){
			if(m>stud.money){
				puts("�������!");
				exit(2);
			}
			stud.money=stud.money-m;
			fseek(file,-(long)sizeof(struct account),SEEK_CUR);
			fwrite(&stud,sizeof(struct account),1,file);
			break;
		}
	}
	fclose(file);
}
void money_in(int id){
	system("cls");
	FILE *file;
	struct account stud;
	file=fopen("a.txt","rb+");
	if(file==NULL){
		printf("cannot open the file!");
		exit(1);
	}
	rewind(file);
	int m;
	printf("������Ҫ����Ľ��:");
	scanf("%d",&m);
	while(fread(&stud,sizeof(struct account),1,file)==1){
		if(stud.id==id){
			stud.money=stud.money+m;
			fseek(file,-(long)sizeof(struct account),SEEK_CUR);
			fwrite(&stud,sizeof(struct account),1,file);
			break;
		}
	}
	fclose(file);
}
void money_out(int id){
	system("cls");
	FILE *file;
	struct account stud;
	file=fopen("a.txt","rb+");
	if(file==NULL){
		printf("cannot open the file!");
		exit(1);
	}
	rewind(file);
	int m;
	printf("������Ҫȡ��Ľ��:");
	scanf("%d",&m);
	while(fread(&stud,sizeof(struct account),1,file)==1){
		if(stud.id==id){
			if(m>stud.money){
				puts("�������!");
				exit(2);
			}
			stud.money=stud.money-m;
			fseek(file,-(long)sizeof(struct account),SEEK_CUR);
			fwrite(&stud,sizeof(struct account),1,file);
			break;
		}
	}
	fclose(file);
}
void get_money(int id) {
	system("cls");
	FILE *file;
	struct account stud;
	file=fopen("a.txt","rb+");
	if(file==NULL){
		printf("cannot open the file!");
		exit(1);
	}
	rewind(file);
	while(fread(&stud,sizeof(struct account),1,file)==1){
		if(stud.id==id){
			printf("�㵱ǰ���Ϊ:%d\n",stud.money);
			break;
		}
	}
	printf("\t\t**********��ӭʹ���й�����*********\n");
	printf("\t\t����aȡ��\t\t����b���.\n");
	printf("\t\t����cת��\t\t����d��ѯ.\n");
	printf("\t\t����t�˳�\t\t����e������.\n");
	fclose(file);
}
void change_password(int id){
	system("cls");
	FILE *file;
	struct account stud;
	file=fopen("a.txt","rb+");
	if(file==NULL){
		printf("cannot open the file!");
		exit(1);
	}
	rewind(file);
	int key;
	puts("������Ҫ�ĵ�����:");
	scanf("%d",&key);
	while(fread(&stud,sizeof(struct account),1,file)==1){
		if(stud.id==id){
			stud.pass=key;
			fseek(file,-(long)sizeof(struct account),SEEK_CUR);
			fwrite(&stud,sizeof(struct account),1,file);
			break;
		}
	}
	fclose(file);
}
int main()
	{
	FILE *file;
	if((file=fopen("a.txt","rb+"))==NULL){
		printf("cannot open the file!");
		exit(1);
	}
	struct account stud;
	
	int id;
	printf("���������id:");
	scanf("%d",&id);
	rewind(file);
	while(fread(&stud,sizeof(struct account),1,file)==1){
		if(stud.id==id){
			printf("\t\t**********��ӭʹ���й�����*********\n");
			printf("\t\t\t���������룺");
			break;
		}
	}
	
	int pass,flag=0;
	if(stud.id==id){	
		while(flag++<3){
			scanf("%d",&pass);
			if(pass==stud.pass)
			break;
		}
	}
	
	if(flag==4){
		printf("����˻���������!\n");
		exit(2);
	}
	char ch;
	if(stud.pass==pass){
		fclose(file);
		jiemian();
		while((ch=getchar())!='t'){
			switch(ch){
				case'a':qu(id);
						jiemian();break;
				case'b':cun(id);
						jiemian();break;
				case'c':zhuan(id);
						jiemian();break;
				case'd':cha(id);break;
				case'e':gai(id);
						jiemian();break;
			}
		}
	}
	fclose(file);
	printf("��ӭʹ��!\n");
	return 0;
	}

