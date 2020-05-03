/*********************Copyright  1997-2017  Duke.Wang********************/
//实验2-05：迷宫问题解决 
//版本：1.5
//说明：解决OJ编译错误问题：end是关键字，不能使用 
/************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;
#define MaxSize 25

typedef struct PosType {	
	int x;
	int y;
}PosType;

typedef struct LNode{
	struct PosType data;
	struct LNode *next;
}LNode;
typedef LNode *LinkList;
typedef int MazeType[MaxSize][MaxSize];

PosType start, End;
MazeType Q;
int row, col;
int flag = 0;
LinkList L;

void Init_List() {
	L = (LinkList)malloc(sizeof(LNode));
	if(L) L->next = NULL;
	else exit(0);
}

void Insert_List(PosType cur){
	LinkList s = (LinkList)malloc(sizeof(LNode));
	if(s){
		s->data = cur;
		s->next = L->next;
		L->next = s;
	}
	else exit(0);
}

void Show_List(){
	LinkList s = L->next;
	int t = 1;
	while(s){
		if(t){
			cout<<"("<<s->data.x-1<<","<<s->data.y-1<<")";
			t = 0;
		}
		else cout<<"->("<<s->data.x-1<<","<<s->data.y-1<<")";
		s = s->next;
	}
}

void Show(){
	if(flag){
		cout<<"YES"<<endl;
		Show_List();
	}
	else cout<<"NO";
} 

void Try(PosType cur,int curstep){
	PosType next;
	PosType direc[4] = {{0,1},{1,0},{0,-1},{-1,0}};
	for(int i=0; i<4; i++){
		next.x = cur.x + direc[i].x;
		next.y = cur.y + direc[i].y;
		if(Q[next.x][next.y] == 1){
			Q[next.x][next.y] = ++curstep;
			if(!(next.x==End.x&&next.y==End.y)){
				Try(next,curstep);
				if(flag){
					Insert_List(cur);
				}
			} 
			else{
				Insert_List(next); 
				Insert_List(cur);		 
				flag = 1;
			}
			Q[next.x][next.y] = 1;
			curstep--;
		}
	}
}
int main(){
	Init_List();
	int i,j;
	cin>>row>>col;
	for(i=0;i==0||i==row+1;i+=row) {
		for(j=0; j<=col; j++){
			Q[i][j] = -1;
		}
	}
	for(j=0;j==!0||j==col+1;j+=col) {
		for(i=0; i<=row; i++){
			Q[i][j] = -1;
		}
	}
	for(i=1; i<=row; i++){
		for(j=1; j<=col; j++){
			cin>>Q[i][j];
			if(Q[i][j]==0){
				start.x = i;
				start.y = j;
			}
			if(Q[i][j]==2){
				End.x = i;
				End.x = i;
				End.x = i;
				End.y = j;
				Q[i][j] = 1;
			}
		}
	}
	Try(start,2);
 	Show();
	return 0;
}
