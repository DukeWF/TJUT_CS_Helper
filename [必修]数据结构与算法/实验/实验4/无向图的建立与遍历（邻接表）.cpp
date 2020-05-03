/*********************Copyright  1997-2017  Duke.Wang********************/
//ʵ��4-01������ͼ�Ľ�������� 
//�汾��1.0
//˵�����ڽӱ��ʾ�� 
/************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;  
#define MAX_VERTEX_NUM 20 
#define TRUE 1
#define FALSE 0
//���ݽṹ���壨�ڽӾ��� 
//1.�ڵ㶨�� 
typedef int InfoType;
typedef int VertexType;//������Ϣ���� 
//1.ͼ�����ͣ�ö������,���ԣ� ��������ͼ��DG�����������磨DN��������ͼ��AG�����������磨AN�� 
typedef enum{
	DG,DN,AG,AN
}GraphKind;
//2.�ڵ㶨�� 
typedef struct ArcNode{
	int adjvex;//�ñ���ָ�򶥵��±� 
	ArcNode *nextarc;//ָ���� 
}ArcNode;
//3.���㶨�� 
typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;//ָ���һ���ߵ�ָ�� 
}VNode, AdjList[MAX_VERTEX_NUM];//��������AdjList[] 
//3.ͼ�Ķ��� 
typedef struct{
	AdjList vertex;//�ڽӱ� 
	int vexnum,arcnum;//������������ 
	GraphKind kind;//ͼ������ 
}Graph;
//ȫ�ֱ��� 
bool visited[MAX_VERTEX_NUM]={false};

//1.����ͼ�Ľ������ڽӱ�
ArcNode* New(ArcNode* s ,int adj, ArcNode* next){
	s->adjvex=adj;
	s->nextarc=next;
	return s;
}
void Create_AG(Graph &G, int n, int e){
	//����ͼ���� 
	G.kind=AG;
	int i,x,y;
	ArcNode* s; 
	//��ʼ���ڽӱ�ͷ�ڵ� 
	for(i=0;i<n;i++){
		G.vertex[i].data=i;//�洢ͼ�ڵ�Ԫ��
		G.vertex[i].firstarc=NULL;
	}
	//�����ڽӱ� 
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
//2.�������������DFS��
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
//3.�������������BFS��
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
	DFS(G,1);//TODO �����⣡ 
}
