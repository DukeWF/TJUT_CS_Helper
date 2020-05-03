#include<iostream>
using namespace std;
typedef struct list{
	int coef;
	int expn;
	struct list* next;
}list; 
list* init(int c[], int e[]){
	list* l,t;
	l=(list*)malloc(sizeof(list));
	l->coef=c[0];
	l->expn=e[0];
	list* p=l;
	for(int i=1;c[i]!='';i++){
		t=(list*)malloc(sizeof(list));
		p->next=t;
		t->coef=c[i];
		t->expn=e[i];		
		t->next=NULL;
		p=t;
	}
	return l;
}
list* plus(list* A, list* B){
	
}
void show(list p){
	if(p->expn!=0) cout<<p->coef<<"X"<<p->expn<<"+";
	else cout<<p->coef<<"+";	
}
void show(list p, int x){
	if(p->expn!=0) cout<<p->coef<<"X"<<p->expn;
	else cout<<p->coef;	
}
void visit(list l){
	list* p=l;
	while(p->next!=null){
		show(p);
		p=p->next;
	}
	show(p,0);
	cout<<endl;
	return;
}
int main(){
	list* A;
	list* B;
	int a1[4]={3,4,5,6};
	int a2[4]={0,1,2,4};
	int b1[4]={3,4,5,6};
	int b2[4]={1,3,5,7};
	A=init(a1[4],a2[4]);
	B=init(b1[4],b2[4]);
	
	list* C;
	C=plus(A,B);
	visit(C);
	
	return 0;
}
