/*
	Name: 
	Description:
	1.
	2.
		2.1:
		2.2:
	3.
	Time Complexity£º O()-O()-O()
*/
#include <iostream>

using namespace std;
typedef int ELEMENT;

struct Stack{
	int *list;
	int curNumber;
};

void initStack(Stack *s){
		
	s->curNumber=0;
	s->list = new int[0];
}

void clearStack(Stack *s){
	delete s->list;
	s->curNumber=0;
}

void push(Stack *s, ELEMENT obj){
		
	s->curNumber++;
		
	int *temp = new int[s->curNumber]; 
	for(int i=0;i<s->curNumber-1;i++){
		temp[i]=s->list[i];
	}
	temp[s->curNumber-1]=obj;
	
	int *old = s->list;
	s->list=temp;
	delete[] old;
}

int Is_empty(Stack *s){
	if(s->curNumber==0) return 1;
	else return 0;
}

void pop(Stack *s){
	if(s->curNumber==0) return;
	else{
		s->curNumber--;
		
		int *temp = new int[s->curNumber]; 
		for(int i=0;i<s->curNumber;i++){
			temp[i]=s->list[i];
		}
		
		int *old = s->list;
		s->list=temp;
		delete[] old;
	}
}



void display(Stack *s){
	for(int i=(s->curNumber)-1;i>=0;i--){
		cout<<s->list[i]<<" ";
	}
	cout<<endl;
}

int main(){

	Stack *s;
	s = (Stack*)malloc(sizeof(Stack));
	initStack(s);

	push(s,1);
	push(s,2);
	push(s,3);
	display(s);
	pop(s);
	display(s);
	
	cout<<Is_empty(s); 

	return 0;
}

