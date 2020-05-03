/*********************Copyright  1997-2017  Duke.Wang********************/
//实验4-01：无向图的建立与遍历 
//版本：1.0
//说明：邻接矩阵表示法 
/************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;  
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20 
#define TRUE 1
#define FALSE 0
//数据结构定义（邻接矩阵） 
typedef int VRType;//顶点关系类型（图为整型，网为权值数据类型） 
typedef int InfoType;//指针类型 
typedef int VertexType;//顶点类型 
//1.图的类型（枚举类型） 包括有向图（DG），有向网络（DN），无向图（AG），无向网络（AN） 
typedef enum{
	DG,DN,AG,AN
}GraphKind;
//2.边（弧）的类型 
typedef struct Arc{
	VRType adj;
	InfoType *info;
}Arc,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//3.图的定义 
typedef struct{
	VertexType vertex[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
	GraphKind kind;
}Graph;

//1.无向图的建立（邻接矩阵） 
void Create_AG(Graph &G, int n, int e){
	//构造顶点矩阵 
	int i,j;
	for(i=0;i<n;++i){
		G.vertex[i]=(i+1);
	}
	//构造空邻接矩阵 
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			G.arcs[i][j]={0,NULL};
		}
	}
	//获取顶点关系 
	for(i=0;i<e;++i){
		cin>>i>>j;
		G.arcs[i][j]=G.arcs[j][i]={1,NULL};
	}
}
//2.深度优先搜索（DFS）
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
