#include<stdio.h>
#include<time.h>
#include<windows.h>
#define clear system("cls")
#define p 3800000
#define N 19
int a,b,c,i,j,g,t;

void gotoxy(int x,int y) //�����λ�Ӻ���
{
     COORD c;
     c.X=x-1;
     c.Y=y-1;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void delay(int z)       //��ʱ�Ӻ�������ʱʱ��Ϊ1ms
{
     int m,n;
     for(m=z;m>0;m--)
      for(n=110;n>0;n--);
}

void over()     //����ģ��
{
     clear;
     gotoxy(28,13);
     printf("���ν��׽�������ȡ����");
     delay(p);
}

void progressbar()        //������ģ��
{
    clear;
    gotoxy(31,13);
    printf("���Ժ�");
    for(c=0;c<10;c+=2)
    {
         gotoxy(38+c,13);
         printf("*");
         delay(380000);
    }
}

void balance()
{
     clear;
     gotoxy(30,12);
     srand(time(0));
     t=rand()%100000000;
     printf("���������%dԪ��",t);
}

int homepage()        //��ҳ
{
    clear;
    gotoxy(30,10);
    printf("=========================");
    gotoxy(31,11);
    printf("1 ȡ��ҵ��   2 ����ѯ");
    gotoxy(31,13);
    printf("3 ת��ҵ��   4 �˳�ϵͳ");
    gotoxy(30,14);
    printf("=========================");
    gotoxy(30,15);
    printf("��������Ӧҵ��ѡ�");
    scanf("%d",&j);
    switch(j)
    {
        case 1:getmoney();break;
        case 2:
               {
                 clear;
                 printf("���ڲ�ѯ");
                 progressbar();
                 gotoxy(30,14);
                 balance();
                 gotoxy(30,14);
                 system("pause");
               };break;
        case 3:
               {
                 clear;
                 gotoxy(34,13);
                 printf("ҵ���ݲ�֧�֣�");
                 delay(p);
                 progressbar();
               };break;
        case 4:
             {
               progressbar();
               over();
               progressbar();
               main();
             };break;
        default:homepage();break;
    }
    homepage();
}

int getmoney()
{
    clear;
    gotoxy(30,12);
    progressbar();
    clear;
    gotoxy(30,9);
    printf("=====================");
    gotoxy(31,10);
    printf("1 100Ԫ     2 200Ԫ");
    gotoxy(31,12);
    printf("3 300Ԫ     4 400Ԫ");
    gotoxy(31,14);
    printf("5 �Զ���    6 ���� ");
    gotoxy(30,15);
    printf("=====================");
    gotoxy(30,16);
    printf("��������Ӧѡ�");
    scanf("%d",&a);
    clear;
    gotoxy(30,13);
    progressbar();
    clear;
    gotoxy(21,13);
    switch(a)
    {
        //����Ʊ��ʱ��֪��Ū��ʲôЧ��,������һ�仰�����ˣ�
        case 1:printf("���ĳ�Ʊ100Ԫ�Ѿ�����������塭��");break;
        case 2:printf("���ĳ�Ʊ200Ԫ�Ѿ�����������塭��");break;
        case 3:printf("���ĳ�Ʊ300Ԫ�Ѿ�����������塭��");break;
        case 4:printf("���ĳ�Ʊ400Ԫ�Ѿ�����������塭��");break;
        case 5:
            {
             printf("��������Ҫȡ������Ŀ��");
             scanf("%d",&b);
             clear;
             gotoxy(21,13);
             progressbar();
             clear;
             if(b%100==0&&b>99)
               {
                 if(b<=10000)
                   {
                      clear;
                      gotoxy(21,13);
                      printf("���ĳ�Ʊ%dԪ�Ѿ�����������塭��",b);
                   }
                   else
                   {
                       clear;
                       gotoxy(21,13);
                       printf("���ã���Ҫȡ���ֽ���̫������ǰ����̨����");
                   }
               }
             else
                 {
                  clear;
                  gotoxy(15,13);
                  printf("����������������Ǯ������Ϊ100�������������������룡");
                 }
            };break;
        case 6:homepage();break;
        default:
                {
                  clear;
                  gotoxy(35,13);
                  printf("���������");
                };break;
    }
     delay(p);
     delay(p);
     getmoney();
     getch();
}

int main()   //������
{
   while(1)
   {
       if(g<3)
       {
           clear;    //����
           gotoxy(20,12);
           printf("===========================================");
           gotoxy(21,13);
           printf("��������Ŀ������������룬��ɺ��밴ȷ�ϣ�");
           gotoxy(20,14);
           printf("===========================================");
           gotoxy(33,15);
           printf("���룺");
           scanf("%d",&i);
           clear;
           gotoxy(30,12);
           progressbar();
           switch(i)
           {
           case 3531627:homepage();break;
           default:
                   {
                     clear;
                     gotoxy(30,13);
                     printf("�����������������!");
                     clear;
                     gotoxy(30,13);
                     printf("������%d�λ��ᣡ",2-g);
                     ++g;
                     delay(p);
                   };break;
            }
       }
       else
       {
           clear;    //����
           gotoxy(20,13);
           printf("�Բ������Ѵ����������Σ����챻��ͣʹ�ã�");
           delay(p);
           delay(p);
       }
    }
}
