#include <iostream> 
using namespace std;
class vector{
	protected:
		int d;
		int *v;
	public:
		vector(int _d):d(_d){
			v=new int[d+1];
			int i;
			for(i=0;i<d;i++){
				cout<<"V["<<i<<"]:";
				cin>>v[i];
			}
			v[i]='\0';
		}
		vector(vector &t){ 
			d=t.d; 
			v=new int[t.d]; 
			for(int i=0;i<t.d;i++) 
				v[i]=t.v[i]; 
		} 	
		vector operator+(vector &t){//加法 
			vector temp(d);
			int i;
			for(i=0;i<d;i++){
				temp.v[i]=v[i]+t.v[i];
			}
			return temp;
		}
//		vector operator-(vector &t){//减法 
//			return vector(v-t.v);
//		}
//		vector operator *(vector &t){//点乘 
//			int sum=0;
//			for(int i=0;i<d;i++){
//				sum+=v[i]*t.v[i];
//			}
//			return sum;
//		}
//		vector operator *(int k){//数乘 
//			return vector((*v)*k);
//		}
		~vector(){
			delete []v;
		} 
//		void show(){
//			
//		}
};
int main(){
	vector a(5);
	vector b(5);
	vector c(5);
	c(5)=a(5)+b(5);
}
