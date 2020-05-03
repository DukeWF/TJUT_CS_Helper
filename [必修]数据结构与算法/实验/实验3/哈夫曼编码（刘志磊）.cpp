#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
#define MaxWeight 10000
#define MaxLeaf 10000
#define maxnode MaxLeaf * 2-1
#define maxbit 100

typedef struct HTNode{
	int weight;
	int parent;
	int lchild;
	int rchild;
	char data;
}HTNode;

typedef struct Leaf{
	char data;
	int weight;
}Leaf;

typedef struct HCode{
	int bit[maxbit];
	int start;
}HCode;

HTNode H[maxnode];
Leaf L[MaxLeaf];
HCode C[maxnode];
int n;
int whole = 0;
void init_Haffman() {
	int i,j,m1,m2,x1,x2;
	for(i=0; i<2*n-1; i++) {
		H[i].weight=0;
		H[i].parent=-1;
		H[i].lchild=-1;
		H[i].rchild=-1;
	}
	for(i=0; i<n; i++) {
		H[i].data=L[i].data;
		H[i].weight=L[i].weight;
	}
	for(i=0; i<n-1; i++) {
		m1=m2=MaxWeight;
		x1=x2=0;
		for(j=0; j<n+i; j++) {
			if(H[j].weight<m1&&H[j].parent==-1) {
				m2=m1;
				x2=x1;
				m1=H[j].weight;
				x1=j;
			} else if(H[j].weight<m2&&H[j].parent==-1) {
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

void init_Code(){
	HCode cd;
	int i,j,c,p;
	for(i=0;i<n;i++){
		cd.start=n-1;  c=i;
		p=H[c].parent;
		while(p!=-1){
			if(H[p].lchild==c)  cd.bit[cd.start]=0;
			else cd.bit[cd.start]=1;
			cd.start--;  c=p;
			p=H[c].parent;
		}
		for(j=cd.start+1;j<n;j++){
			C[i].bit[j]=cd.bit[j];
		}
		C[i].start=cd.start;
	}
}

void Code_Now(){
	string str;
	cin>>str;
	for(int i=0;str[i]!=NULL;i++){
		for(int j=0;j<n;j++){
			if(str[i]==H[j].data){
				for(int k=C[j].start+1;k<n;k++){
					cout<<C[j].bit[k];
				}
				break;
			}
		}
	}
	cout<<endl;
}

void Decode_Now(){
	string str;
	int i,j,k,l;
	cin>>str;
	int len=str.length();
	whole = len;

	while(whole!=0){
		for(i=0;i<n;i++){
			int m=0;
			for(k=C[i].start+1,j=0;k<n&&j<whole;k++,j++){
				if((str[j]-'0')==C[i].bit[k])
				m++;
			}
			if(m==j){
				cout<<H[i].data;
				for(int x=0;(x+j)<whole;x++){
					str[x]=str[x+j];
				}
				whole -= j;
				break;
			}
		}
	}
}


int main(){
	int Q,x;
	cin>>Q;
	for(int i=0;i<Q;i++){ 
		cin>>x;
		switch(x){
			case 0:
				cin>>n;
				for(int i=0; i<n; i++){
					cin>>L[i].data;
				}
				for(int j=0; j<n; j++){
					cin>>L[j].weight;
				}
				init_Haffman();
				init_Code();
				break;
			case 1:
				Code_Now();
				break;
			case 2:
				Decode_Now();
				break;
		}
	}
	return 0;
}
