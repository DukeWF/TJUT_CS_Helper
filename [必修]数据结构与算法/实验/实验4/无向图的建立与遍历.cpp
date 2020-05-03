/*********************Copyright  1997-2017  Duke.Wang********************/
//ʵ��4-01������ͼ�Ľ�������� 
//�汾��1.0
//˵�����ڽӾ����ʾ�� 
/************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;  
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20 
#define TRUE 1
#define FALSE 0
//���ݽṹ���壨�ڽӾ��� 
typedef int VRType;//�����ϵ���ͣ�ͼΪ���ͣ���ΪȨֵ�������ͣ� 
typedef int InfoType;//ָ������ 
typedef int VertexType;//�������� 
//1.ͼ�����ͣ�ö�����ͣ� ��������ͼ��DG�����������磨DN��������ͼ��AG�����������磨AN�� 
typedef enum{
	DG,DN,AG,AN
}GraphKind;
//2.�ߣ����������� 
typedef struct Arc{
	VRType adj;
	InfoType *info;
}Arc,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//3.ͼ�Ķ��� 
typedef struct{
	VertexType vertex[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
	GraphKind kind;
}Graph;

//1.����ͼ�Ľ������ڽӾ��� 
void Create_AG(Graph &G, int n, int e){
	//���춥����� 
	int i,j;
	for(i=0;i<n;++i){
		G.vertex[i]=(i+1);
	}
	//������ڽӾ��� 
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			G.arcs[i][j]={0,NULL};
		}
	}
	//��ȡ�����ϵ 
	for(i=0;i<e;++i){
		cin>>i>>j;
		G.arcs[i][j]=G.arcs[j][i]={1,NULL};
	}
}
//2.�������������DFS��
void Visit(int v){
	cout<<v;
}
int FirstAdjVex(Graph G, int v){
	return 0; 
}
int NextAdjVex(Graph G, int v, int w){
	return 0; 
}
bool visited[MAX_VERTEX_NUM]={TRUE};
void DFS(Graph G, int v){
	visited[v]=TRUE;
	Visit(v);
	for(int w=FirstAdjVex(G,v);w!=0;w=NextAdjVex(G,v,w))
		if(!visited[w]) DFS(G,w);
}
void DFSTraverse(Graph G){
	for(int v=0;v<G.vexnum;++v)
		visited[v]=FALSE;
		
}

int main(){
	cout<<"ejdf";
}
