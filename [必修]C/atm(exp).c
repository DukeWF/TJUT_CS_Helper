#include<stdio.h>
#include<time.h>
#include<windows.h>
#define clear system("cls")
#define p 3800000
#define N 19
int a,b,c,i,j,g,t;

void gotoxy(int x,int y) //输出定位子函数
{
     COORD c;
     c.X=x-1;
     c.Y=y-1;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void delay(int z)       //延时子函数，延时时间为1ms
{
     int m,n;
     for(m=z;m>0;m--)
      for(n=110;n>0;n--);
}

void over()     //结束模块
{
     clear;
     gotoxy(28,13);
     printf("本次交易结束，请取卡！");
     delay(p);
}

void progressbar()        //进度条模块
{
    clear;
    gotoxy(31,13);
    printf("请稍候");
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
     printf("您的余额是%d元！",t);
}

int homepage()        //主页
{
    clear;
    gotoxy(30,10);
    printf("=========================");
    gotoxy(31,11);
    printf("1 取款业务   2 余额查询");
    gotoxy(31,13);
    printf("3 转账业务   4 退出系统");
    gotoxy(30,14);
    printf("=========================");
    gotoxy(30,15);
    printf("请输入相应业务选项：");
    scanf("%d",&j);
    switch(j)
    {
        case 1:getmoney();break;
        case 2:
               {
                 clear;
                 printf("正在查询");
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
                 printf("业务暂不支持！");
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
    printf("1 100元     2 200元");
    gotoxy(31,12);
    printf("3 300元     4 400元");
    gotoxy(31,14);
    printf("5 自定义    6 返回 ");
    gotoxy(30,15);
    printf("=====================");
    gotoxy(30,16);
    printf("请输入相应选项：");
    scanf("%d",&a);
    clear;
    gotoxy(30,13);
    progressbar();
    clear;
    gotoxy(21,13);
    switch(a)
    {
        //出钞票的时候不知道弄成什么效果,所以以一句话代替了！
        case 1:printf("您的钞票100元已经出来，请点清……");break;
        case 2:printf("您的钞票200元已经出来，请点清……");break;
        case 3:printf("您的钞票300元已经出来，请点清……");break;
        case 4:printf("您的钞票400元已经出来，请点清……");break;
        case 5:
            {
             printf("请输入您要取出的数目：");
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
                      printf("您的钞票%d元已经出来，请点清……",b);
                   }
                   else
                   {
                       clear;
                       gotoxy(21,13);
                       printf("您好，您要取的现金数太大，请您前往柜台办理！");
                   }
               }
             else
                 {
                  clear;
                  gotoxy(15,13);
                  printf("您输入错误，所输入的钱数必须为100的整数倍，请重新输入！");
                 }
            };break;
        case 6:homepage();break;
        default:
                {
                  clear;
                  gotoxy(35,13);
                  printf("您输入错误！");
                };break;
    }
     delay(p);
     delay(p);
     getmoney();
     getch();
}

int main()   //主程序
{
   while(1)
   {
       if(g<3)
       {
           clear;    //清屏
           gotoxy(20,12);
           printf("===========================================");
           gotoxy(21,13);
           printf("请插入您的卡，并输入密码，完成后请按确认！");
           gotoxy(20,14);
           printf("===========================================");
           gotoxy(33,15);
           printf("密码：");
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
                     printf("密码错误，请重新输入!");
                     clear;
                     gotoxy(30,13);
                     printf("您还有%d次机会！",2-g);
                     ++g;
                     delay(p);
                   };break;
            }
       }
       else
       {
           clear;    //清屏
           gotoxy(20,13);
           printf("对不起，您已错误输入三次，今天被暂停使用！");
           delay(p);
           delay(p);
       }
    }
}
