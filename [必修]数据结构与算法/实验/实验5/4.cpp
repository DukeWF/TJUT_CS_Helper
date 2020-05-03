#include <iostream>
using namespace std;
typedef struct word{
	int count[26];
}word,*W;
void init(W word){
	for(int i=0;i<26;i++){
		word.count[i]=0;
	}
	return;
}
class List{
	private:
		W *word;
	public:
		List(int n){
			word=new W[n];
			string nm;
			for(int i=0;i<n;i++){
				cin>>nm;
				init(word[i]);
				for(int j=0;j<nm.length;j++){
					word[j][nm[j]-'a']++;
				}
			}
		}
		query(int q, int n){
			for(int i=0;i<q;i++){
				
			}
		}
};
int main(){
	int n,q;
	cin>>n>>q;
	List l(n);
	
}
