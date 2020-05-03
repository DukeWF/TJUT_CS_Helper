/*********************Copyright  1997-2017  Duke.Wang********************/
//实验2-04：停车场管理 
//版本：1.0
//说明：测试
/************************************************************************/
#include <iostream>
#include <cstdlib>
#define MaxSize 100
using namespace std;
typedef struct SNode{
	int time[MaxSize];
	int length;
	int top;
}SNode;

typedef struct QNode{
	int time[MaxSize];
	int front;
	int rear;
}QNode;

typedef SNode *SeqStack;
typedef QNode *SeqQueue;

SeqStack _S;
SeqQueue _Q;
//1.初始化顺序栈
SeqStack Ini_Stack(int num){
	SeqStack S = (SeqStack)malloc(sizeof(SNode));
	if(S){
		S->length = num;
		S->top = -1;
	}
	else exit(0);
	return S;
}
//2.初始化顺序队列
SeqQueue Ini_Queue(){
	SeqQueue Q = (SeqQueue)malloc(sizeof(QNode));
	if(Q){
		Q->front = 0;
		Q->rear = -1;
	}
	else exit(0);
	return Q; 
}
//3.判断栈是否空/满 
int Is_Stack_Full(SeqStack S){
	return S->top>=S->length-1?1:0;
}

int Is_Stack_Empty(SeqStack S){
	return S->top<=-1?1:0;
}
//4.判断队列是否为空
int Is_Queue_Empty(SeqQueue Q){
	return Q->rear<0?1:0;
}
//5.判断特定车辆是否在停车场内 
int Is_Car_In(SeqStack S,int n){
	return S->top>=(S->length-n)?1:0;
}
//6.车辆操作
SeqQueue Insert_Queue(SeqQueue Q,int t){
	Q->time[++Q->rear]=t;
	return Q;
}
SeqStack Insert_Stack(SeqStack S,int t){
	S->time[++S->top] = t;
	return S;
}
SeqStack Insert_From_Queue(SeqStack S,SeqQueue Q){
	S->time[++S->top] = Q->front;
	for(int i=0; i<Q->rear; i++){
		Q->time[i] = Q->time[i+1];
	}
	return S;
}
//7.停车
void Pause(SeqStack S,SeqQueue Q,int t){
	if(!Is_Stack_Full(S))
		S = Insert_Stack(S,t);
	else
		Q = Insert_Queue(Q,t);
}
//8.开车 
SeqQueue Exit_queue(SeqQueue Q,int n) {
	if(!Is_Queue_Empty(Q)) {
		for(int i=n-1; i<Q->rear; i++){
			Q->time[i] = Q->time[i+1];
		}
		Q->rear--;
		cout<<"0"<<endl;
		return Q;
	}
	else return Q;
}
SeqStack Exit_Stack(SeqStack S,int n,int t) {			//出室内，计费；
	int cost;
	n = S->length - n;		//转换下标
	cost = t - S->time[n];
	for(n; n<S->top; n++) {
		S->time[n] = S->time[n+1];
	}
	S->top--;
	cout<<cost<<endl;			//费用
	return S;
}
void Exit(SeqStack S,SeqQueue Q,int n,int t) {		//出停车场
	if(Is_Car_In(S,n)) {					//判断车在室内还是室外
		S = Exit_Stack(S,n,t);		// 调用 出室内 函数
		if(!Is_Queue_Empty(Q)) {		//如果便道里有车，则入停车场 
			S = Insert_From_Queue(S,Q);
		}
	}
	else{
		n = n - S->length;			//转换为便道的位置
		Q = Exit_queue(Q,n);					//否则 出便道
	}
}
int main(){
	int n,Q,type,time;
	cin>>n>>Q;
	_S = Ini_Stack(n);
	_Q = Ini_Queue();
	for(int i=0;i<Q;i++){
		cin>>type;
		switch(type){
			case 1:{
				cin>>time;
				Pause(_S,_Q,time);
				break;
			}
			case 2:{
				cin>>n>>time;
				Exit(_S,_Q,n,time);
				break;
			}
			default:break;
		}
	}
	return 0;
}
