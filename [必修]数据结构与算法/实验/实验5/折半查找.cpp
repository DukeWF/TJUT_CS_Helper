/*********************Copyright  1997-2017  Duke.Wang********************/
//实验5-01：折半查找
//版本：2.2
//说明：更新算法为折半查找，测试
/************************************************************************/
#include <iostream>
using namespace std;
typedef int KeyType; 
typedef struct ElemType{
	KeyType key;
}ElemType;
int n;
KeyType key;
int Binary_Search(ElemType record[],KeyType k){
	int low=1;
	int high=n;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(record[mid].key==k) return mid;
		else if(k<record[mid].key) high=mid-1;
		else low=mid+1;
	}
	return -1;
}
ElemType Construction(ElemType str[]){
	for(int i=1;i<n+1;i++){
		cin>>str[i].key;
	}
}
	
int main(){
	cin>>n>>key;
	ElemType str[n+1];
	Construction(str);
	cout<<Binary_Search(str,key);
	return 0;
}
