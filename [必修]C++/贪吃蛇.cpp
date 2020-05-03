#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include <windows.h>
using namespace std;
int eat_food = 0;
float score = 0;
short int grade = 0;
short int timeout = 700;
int step = 0;
short int derect=77;//////////上下左右 asc
 
class SNAKE
{
        short int x;
        short int y;
        SNAKE* Qian;
        SNAKE* Hou;
public:
        SNAKE(){x = 0; y = 0; Qian = NULL; Hou = NULL;}
        SNAKE(int a, int b){x = a; y =b; Qian = NULL; Hou = NULL;}
        void change(int a ,int b){if(a!=-1)x = a; if(b!=-1)y = b;}
        short int getx(){return x;}
        short int gety(){return y;}
        SNAKE* qian(){return Qian;}
        SNAKE* qian(SNAKE* a){Qian=a;return Qian;}
        SNAKE* hou(){return Hou;}
        SNAKE* hou(SNAKE* a){Hou=a;return Hou;}
};
  
class FOOD
{
public:
        short int x;
        short int y;
};
FOOD food;
 
SNAKE* end;//尾巴地址
SNAKE* head;///头地址
 
bool move(int,int,short int **);
bool randfood(int, int , short int &,short int &,short int **);
int main()
{
        cout << "\n\t贪吃蛇\n\n\n\t\t"<<endl;
        short int i,j, a, b;
        cout<<"请输入行数：";
        cin>>a; cin.sync(); cin.clear();
        cout<<"请输入列数：";
        cin>>b; cin.sync(); cin.clear();
        a+=2;b+=2;
        short int **point;
        point = new short int* [a]; //////-1 墙     0 空     1 身子        2 食物       3头
        for(i=0; i<a ;++i)
                point[i]=new short int[b];
 
        for(i = 1; i < a-1; ++i)
                for(j = 1; j < b-1; ++j)
                        point[i][j] = 0;
 
        for(i = 0; i < a; ++i)
                point[i][b-1]=point[i][0]=-1;
        for(i = 0; i < b; ++i)
                point[0][i]=point[a-1][i]=-1;
 
        cout << " 游戏马上开始，请按任意键继续\n PS:可随时以cmd选择模式暂停\n\n";
        system("pause"); 
 
        end = new SNAKE;
        SNAKE* save_end = end;
        for(i = 1; i < (a-2)*(b-2); ++i)
        {
                head = new SNAKE;        
                end -> qian(head);
                head -> hou(end);
                end = head;
        }
 
        head -> qian(save_end);
        save_end -> hou(head);
        head=head->qian();/////////////形成a*b的环状双向链表，已验证
 
        end->change(a/2, b/2-1);
        head->change(a/2, b/2);
        point[a/2][b/2-1]=1;
        point[a/2][b/2]=3;
 
        randfood(a, b, food.x,food.y,point);
        while(move(a,b,point));///传值边界含外框
 
        for(i=0;i<a;++i)
                delete[] point[i];
        delete[] point;
        SNAKE* temp = head;
        for(i = 0; i < (a-2)*(b-2); ++i)
        {
                temp = head -> qian();
                delete head;
                head = temp;
        }////////////delete
 
        system("pause");
}
 
 
bool randfood(int M, int N, short int &x,short int &y,short int **point)///////false时为全满，赢
{
        int i,j;
        srand(unsigned(time(0)));
        x=rand()%(M-2)+1;
        y=rand()%(N-2)+1;
        i=x;
        j=y;
        for(++x;;++x)
        {
                if(x==M-1)
                        x-=M-2;
                for(++y;;++y)
                {
                        if(y==N-1)
                                y-=N-2;
                        if(point[x][y]==0)
                        {
                                point[x][y]=2;
                                return true;
                        }
                        if(j==y)        break;                
                }
                if(i==x)        return false;
        }
}
 
 
bool move(int M, int N, short int **point)
{
        score=eat_food*10+step*0.1;
        grade=score/100+1;
        switch(grade)
        {
                case 2 : if(timeout==700){timeout=550;system("cls");cout<<"\n\n\n\n\t\t恭喜升级!!\n\n";system("pause");}break;
                case 4 : if(timeout==550){timeout=400;system("cls");cout<<"\n\n\n\n\t\t恭喜升级!!\n\n";system("pause");}break;
                case 7 : if(timeout==400){timeout=300;system("cls");cout<<"\n\n\n\n\t\t恭喜升级!!\n\n";system("pause");}break;
                case 11: if(timeout==300){timeout=200;system("cls");cout<<"\n\n\n\n\t\t恭喜升级!!\n\n";system("pause");}break;
        }
         
        system("cls");
        cout<<" 步数:"<<++step<<"   吃了:"<<eat_food<<"   分数:"<<(int)score<<"   等级:"<<grade<<"   时间间隔"<<timeout<<"ms"<<endl;
        int i,j,time_1;
        for(i=0;i<M;++i)
        {
                cout<<'\t';
                for(j=0;j<N;++j)
                {
                        if(point[i][j]==0)
                                cout<<"  ";
                        if(point[i][j]==1)
                                cout<<"▉";
                        if(point[i][j]==-1)
                                cout<<"▓";
                        if(point[i][j]==3)
                                cout<<"◆";
                        if(point[i][j]==2)
                                cout<<"●";
                }
                cout<<endl;
        }
 
        int temp,key;
        time_1=clock();
        while(clock()-time_1<=timeout)
        {
                key=kbhit();/////////////////键盘输入时返回1
                Sleep(50);
                if(key!=0 && getch()==224)
                {
                         
                        temp=getch();
                        if((temp==80&&head->getx()+1!=head->hou()->getx())||(temp==72&&head->getx()-1!=head->hou()->getx())||(temp==75&&head->gety()-1!=head->hou()->gety())||(temp==77&&head->gety()+1!=head->hou()->gety()))
                        {        derect=temp;        break;}
                }
        }
        switch(derect)
        {
                case 80 : head->qian()->change(head->getx()+1, head->gety()); break;//xia
                case 75 : head->qian()->change(head->getx(), head->gety()-1); break;//zuo
                case 77 : head->qian()->change(head->getx(), head->gety()+1); break;//you
                case 72 : head->qian()->change(head->getx()-1, head->gety()); break;//shang
        }
        head = head ->qian();
        if(point[(int)head->getx()][(int)head->gety()]!=2)
        {
                point[end->getx()][end->gety()]=0;
                end = end ->qian();
        }
        else
        {
                ++eat_food;
                if(randfood(M, N, food.x,food.y,point)==0)
                {
                        cout<<"\n\n\t\tYou Win!!!\n\n";//////////////赢了
                        system("color 1e");
                        return false;
                }
        }
 
        if(point[head->getx()][head->gety()]==1||point[head->getx()][head->gety()]==-1)
        {
                cout<<"\n\n\t\tGame Over!\n\n";/////////////////输了
                system("color 1C");
                return false;        
        }
        else
        {
                point[head->getx()][head->gety()]=3;
                point[head->hou()->getx()][head->hou()->gety()]=1;
                return true;
        }
}
