#include<iostream>  
#include<algorithm>  
#include<string.h>
#include<map>  
using namespace std;  
#define MAX 50005  
map<int, int>p;  
int a[MAX],b[MAX],flag[MAX]={0},f[MAX]={0};  
int main(){  
    int n,k,len=0;  
    long long sum;
    cin>>n;
    for(int i = 0;i < n;i++){  
        scanf("%d", &a[i]);  
        if (!p[a[i]])  
        {  
            p[a[i]] = 1;  
            b[len++] = a[i];  
        }  
    }  
    sort(b,b+len);  
    for(int i=0;i<len;i++) p[b[i]]=i;  
    int ANS=0,s=n-1,x=0,y=0;  
    sum=0;
    for(int i=0;i<n;i++){  
        if(flag[p[a[i]]]){  
            sum+=ANS;  
            continue;  
        }  
        flag[p[a[i]]]=1;  
        x++;
        ANS=0;
        int key = 0;  
        for(int j=s;j>=0;j--){  
            if(!flag[p[a[j]]]) break;  
            if(key){  
                ANS++;  
                s=j-1;  
                continue;  
            }
            if(!f[p[a[j]]]){  
                y++;  
                f[p[a[j]]]=1;  
            }
            if(x==y){  
                key=1;  
                ANS++;  
                s=j-1;  
            }
        }
        sum+=ANS;  
    }
    cout<<sum;  
    return 0;  
}
