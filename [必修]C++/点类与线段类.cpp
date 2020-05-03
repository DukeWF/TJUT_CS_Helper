#include <iostream>
#include <cmath>
using namespace std;
class point{
	protected:
		int x,y;
	public:
		point(int a=0, int b=0){
			x=a;
			y=b;
		}
		int get_x(){
			return x;
		}
		int get_y(){
			return y;
		}
		double get_len(point&t){
			return sqrt(pow((x-t.x),2),pow((y-t.y),2));
		}
		void show(){
			cout<<"("<<x<<","<<y<<")"<<endl;
		}
}; 
class segment{
	protected:
		point p1, p2;
		double len;
	public:
		segment(int a, int b, int c, int d):p1(a,b),p2(c,d){
//			point t1(a,b);,
//			point t2(c,d);
//			p1=t1;
//			p2=t2;
		}	
		segment(){
			int x1,x2,y1,y2; 
			cout<<"请输入起点:"<<endl<<"X1=";
			cin>>x1;
			cout<<"Y1=";
			cin>>y1;
			cout<<"请输入终点:"<<endl<<"X2=";
			cin>>x2;
			cout<<"Y2=";
			cin>>y2;
			point t1(x1,y1);
			point t2(x2,y2);
			p1=t1;
			p2=t2;			
		}
		void show(){
			cout<<"起点是：" ;
			p1.show();
			cout<<"终点是：" ;
			p2.show();
			cout<<endl;
			cout<<"距离为：";
			 
		} 
		double distance_1(){
			len=sqrt(pow((p1.get_x()-p2.get_x()),2)-pow((p1.get_y()-p2.get_y()),2));
			return len;
		}
		double distance_2(){
			return p1.get_len(p2);
		}
}; 
class cline:public segment{
	
}; 

int main(){
	segment ln;
	ln.show();
}
