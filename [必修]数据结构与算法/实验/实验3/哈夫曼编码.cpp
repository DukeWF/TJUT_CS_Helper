/*********************Copyright  1997-2017  Duke.Wang********************/
//实验3-05：哈夫曼编码
//版本：1.0
//说明：测试
/************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;  
#define MaxWeight 10000
#define MaxLeaf 30
#define MaxNode MaxLeaf *2-1
#define MaxBit 100
typedef struct HTNode{
	char data;
	int weight;
	int parent;
	int lchild, rchild;
}HTNode;
typedef HTNode *HTree;

typedef struct HCode{
	int bit[MaxBit];
	int start;
}HCode;
int n;
HTNode H[MaxNode];
void init_Haffman(){
	int i,j,m1,m2,x1,x2;
	cin>>n;
	for(i=0;i<2*n-1;i++){
		H[i].weight=0;
		H[i].parent=-1;
		H[i].lchild=-1;
		H[i].rchild=-1;
	}
	for(i=0;i<n;i++){
		cin>>H[i].data;
	}
	for(i=0;i<n;i++){
		cin>>H[i].weight;
	}
	for(i=0;i<n-1;i++){
		m1=m2=MaxWeight;
		x1=x2=0;
		for(j=0;j<n;j++){
			if(H[j].weight<m1&&H[j].parent==-1){
				m2=m1;
				x2=x1;
				m1=H[j].weight;
				x1=j;
			}
			else if(H[j].weight<m2&&H[j].parent==-1){
				m2=H[j].weight;
				x2=j;				
			}
		}
		H[x1].parent=n+i;
		H[x2].parent=n+i;
		H[n+i].weight=H[x1].weight+H[x2].weight;
		H[n+i].lchild=x1;
		H[n+i].rchild=x2;
	}
}
void Coding(){
	string str;
	cin>>str;
	HCode C[MaxNode],cd;
	int i,j,c,p;
	for(i=0;i<n;i++){
		cd.start=n-1;
		c=i;
		p=H[c].parent;
		while(p){
			if(H[p].lchild==c) cd.bit[cd.start]=0;
			else cd.bit[cd.start]=1;
			cd.start--;
			c=p;
			p=H[c].parent;
		}
		for(j=cd.start+1;j<n;j++)
			C[i].bit[j]=cd.bit[j];
		C[i].start=cd.start;
	}
	for(i=0;i<n;i++){
		for(j=C[i].start+1;j<n;j++)
			cout<<C[i].bit[j];
	}
	cout<<endl;
}
int main(){
	int Q,x;
	cin>>Q;
	for(int i=0;i<Q;i++){
		cin>>x;
		switch(x){
			case 0:{
				init_Haffman();
				break;
			}
			case 1:{
				Coding();
				break;
			}
			case 2:{
				Decoding();
				break;
			}
		}
	}
	return 0;
} 
