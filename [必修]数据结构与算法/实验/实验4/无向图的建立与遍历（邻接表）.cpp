/*********************Copyright  1997-2017  Duke.Wang********************/
//实验4-01：无向图的建立与遍历 
//版本：1.0
//说明：邻接表表示法 
/************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;  
#define MAX_VERTEX_NUM 20 
#define TRUE 1
#define FALSE 0
//数据结构定义（邻接矩阵） 
//1.节点定义 
typedef int InfoType;
typedef int VertexType;//顶点信息类型 
//1.图的类型（枚举类型,可略） 包括有向图（DG），有向网络（DN），无向图（AG），无向网络（AN） 
typedef enum{
	DG,DN,AG,AN
}GraphKind;
//2.节点定义 
typedef struct ArcNode{
	int adjvex;//该边所指向顶点下标 
	ArcNode *nextarc;//指针域 
}ArcNode;
//3.顶点定义 
typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;//指向第一条边的指针 
}VNode, AdjList[MAX_VERTEX_NUM];//顶点数组AdjList[] 
//3.图的定义 
typedef struct{
	AdjList vertex;//邻接表 
	int vexnum,arcnum;//顶点数，边数 
	GraphKind kind;//图的种类 
}Graph;
//全局变量 
bool visited[MAX_VERTEX_NUM]={false};

//1.无向图的建立（邻接表）
ArcNode* New(ArcNode* s ,int adj, ArcNode* next){
	s->adjvex=adj;
	s->nextarc=next;
	return s;
}
void Create_AG(Graph &G, int n, int e){
	//设置图类型 
	G.kind=AG;
	int i,x,y;
	ArcNode* s; 
	//初始化邻接表头节点 
	for(i=0;i<n;i++){
		G.vertex[i].data=i;//存储图节点元素
		G.vertex[i].firstarc=NULL;
	}
	//构造邻接表 
	for(i=0;i<e;i++){
		cin>>x>>y;
		
		s=(ArcNode*)malloc(sizeof(ArcNode));
		s=New(s,y,NULL);
		s->nextarc=G.vertex[x].firstarc;
		G.vertex[x].firstarc=s;
		
		s=(ArcNode*)malloc(sizeof(ArcNode));
		s=New(s,x,NULL);
		s->nextarc=G.vertex[y].firstarc;
		G.vertex[y].firstarc=s; 
	}
}
//2.深度优先搜索（DFS）
void Visit(Graph G, int v){
	cout<<G.vertex[v].data;
	visited[v]=TRUE;
}

void DFS(Graph G, int v){
	ArcNode *p;
	visited[v]=TRUE;
	Visit(G,v);
	p=G.vertex[v].firstarc;
	while(p){
		if(visited[p->adjvex]==0) DFS(G,p->adjvex);
		p=p->nextarc;
	}
}
void DFSTraverse(Graph G){
	for(int v=0;v<G.vexnum;++v) visited[v]=FALSE;
}
//3.广度优先搜索（BFS）
//void BFS(Graph G, int v, int visit[MAX_VERTEX_NUM]){
//	ArcNode *p;
//	int que[MAX_VERTEX_NUM], front=0, rear=0;
//	int j;
//	Visit(v);
//	visit[v]=1;
//	rear=(rear+1)%MAX_VERTEX_NUM;
//	que[rear]=v;
//	while(front!=rear){
//		front=(front+1)%MAX_VERTEX_NUM;
//		j=que[front];
//		p=G.vertex[j].firstarc;
//		while(p){
//			if(visit[p->adjvex]==0)
//				DFS(G,p->adjvex);
//			p=p->nextarc;
//		}
//	}
//}
int main(){
	Graph G;
	int n,m;
	cin>>n>>m;
	
	Create_AG(G,n,m);
	DFS(G,1);//TODO 有问题！ 
}
