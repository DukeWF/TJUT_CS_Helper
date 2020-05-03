#include<stdio.h>
#include<stdlib.h>
struct node{
	int x,y,d;
};
node e[100010];
int len=0;
int F[100010];
int find(int x)
{
	if(F[x]==x) return x;
	else 
	{
		F[x]=find(F[x]);
		return F[x];
	}
}
void qsort(int l,int r)
{
	int i=l,j=r;
	node m,t;
	m=e[(l+r)/2];
	while(i<=j){
		while(e[i].d<m.d) i++;
		while(e[j].d>m.d) j--;
		if(i<=j){
			t=e[i];
			e[i]=e[j];
			e[j]=t;
			i++;
			j--;
		}
	}
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}

int main(){
	int n,m,x,y,d,t;
	long long ans=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int t,g,h;
		scanf("%d %d %d",&t,&g,&h);
		len++;
		e[len].x=t;
		e[len].y=g;
		e[len].d=h;
	}
	qsort(1,len);
	for(int i=1;i<=n;i++) F[i]=i;
	for(int i=1;i<=len;i++){
		int fx,fy;
		fx=find(e[i].x);
		fy=find(e[i].y);
		if(fx!=fy){
			ans+=e[i].d;
			F[fx]=fy;
			t++;
			if(t==n-1) break;
		}
	}
	printf("%lld",ans);
}
