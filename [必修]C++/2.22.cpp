#include <iostream>
using namespace std;

int main()
	{
		int *F;
		F = new int;//¶¯Ì¬·ÖÅä
		F[0] = F[1] = 1;
		for(int i=0;i<20;i++)
			{
				if(i>=2)
					F[i]=F[i-1]+F[i-2];
				cout<<F[i]<<endl;
			}
		delete F;
		return 0;	
	}
