#include<stdio.h>
#include<stdlib.h>
struct account{
	int id;
	char name[20];
	int pass;
	int money;
};

void jiemian();
void zhuan(int id);
void cun(int id);
void qu(int id);
void cha(int id);
void gai(int id);

int main(){
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

void jiemian(){
	system("cls");
	printf("\t\t**********��ӭʹ���й�����*********\n");
	printf("\t\t����aȡ��\t\t����b���.\n");
	printf("\t\t����cת��\t\t����d��ѯ.\n");
	printf("\t\t����t�˳�\t\t����e������.\n");
}

void zhuan(int id){
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

void cun(int id){
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

void qu(int id){
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

void cha(int id) {
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

void gai(int id){
	system("cls");
	FILE *file;
	struct account stud;
	file=fopen("a.txt","rb+");
	if(file==NULL){
		printf("ERROR: Cannot open the file!");
		exit(1);
	}
	rewind(file);
	int key;
	puts("������������:");
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
