//Homework: 
#include <iostream>
using namespace std;
class Fraction{
	protected:
		int fenzi,fenmu;
	public:
		Fraction(int m, int z){
			
		} 
		Fraction operation+(Fraction &f);
		int gcd(int m, int n){//利用辗转相除法求最大公约数 
			if(m<n){
				int t=m;
				m=n;
				n=t
			}
			int r=m%n;
			while(r){
				m=n;
				n=r;
				r=m%n;
			}
			return n;
		}
		int mcb(int m,n){//求最小公倍数 
			
			return m*n/gcd(m,n); 
		}
};
