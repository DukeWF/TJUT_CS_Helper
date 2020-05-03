//结构体版ATM模拟程序
/*
＊	本程序能实现的功能为
＊	1.账户信息记录（文件中）
＊	2.利用结构体形成账户ID，密码，姓名，当前余额
＊	3.吞卡方式优化：比对ID和密码，三次错误提示吞卡+冻结该账户（账户可用状态改为0）
＊	4.实现功能：查询余额，取款，存款，修改密码，这些操作更新在文件数据中
＊	5.新功能：操作日志记录--包括查询余额，存取款，改密码，登录账户等操作，格式为：时间--操作
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
		printf("欢迎使用，请输入您的ID和密码，并以回车结束。\n");
		printf("ID:___________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%c", &p_id);
		printf("\npassword:______\b\b\b\b\b\b"); 
		scanf("%d", &p_pw);
		printf("请稍后，正在处理中......");
		system("pause"); 
	}
void menu(){
	system("cls");
	printf("\t\t**********欢迎使用中国银行*********\n");
	printf("\t\t输入a取款\t\t输入b存款.\n");
	printf("\t\t输入c转账\t\t输入d查询.\n");
	printf("\t\t输入t退出\t\t输入e改密码.\n");
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
	printf("输入你要转账的金额:");
	scanf("%d",&m);
	while(fread(&stud,sizeof(struct account),1,file)==1){
		if(stud.id==id){
			if(m>stud.money){
				puts("你的余额不足!");
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
	printf("输入你要存入的金额:");
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
	printf("输入你要取款的金额:");
	scanf("%d",&m);
	while(fread(&stud,sizeof(struct account),1,file)==1){
		if(stud.id==id){
			if(m>stud.money){
				puts("你的余额不足!");
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
			printf("你当前余额为:%d\n",stud.money);
			break;
		}
	}
	printf("\t\t**********欢迎使用中国银行*********\n");
	printf("\t\t输入a取款\t\t输入b存款.\n");
	printf("\t\t输入c转账\t\t输入d查询.\n");
	printf("\t\t输入t退出\t\t输入e改密码.\n");
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
	puts("输入你要改的密码:");
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
	printf("请输入你的id:");
	scanf("%d",&id);
	rewind(file);
	while(fread(&stud,sizeof(struct account),1,file)==1){
		if(stud.id==id){
			printf("\t\t**********欢迎使用中国银行*********\n");
			printf("\t\t\t请输入密码：");
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
		printf("你的账户被冻结了!\n");
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
	printf("欢迎使用!\n");
	return 0;
	}

