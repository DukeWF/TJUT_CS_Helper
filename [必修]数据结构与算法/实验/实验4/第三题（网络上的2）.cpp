#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
    int father[100001], height[100001];
    void build(int n){
        for(int i=1; i<=n; i++){
            father[i] = i;
            height[i]=0;
        }
}
    int find(int x){
        if(x == father[x]) return x;
        else{
            father[x] = find(father[x]);
            return father[x];
        }
    }
    void merge(int x, int y){
        x=find(x);
        y=find(y);
        father[x] = y;
    }
    bool judge(int x, int y){
        return find(x) == find(y);
    }
}Node;

struct lines{
	int from, to, value;
}line[100002];

bool compare(lines a, lines b){
	return a.value < b.value;
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>(line[i].from)>>(line[i].to)>>(line[i].value);
    }

    sort(line, line+m, compare);//��ԭͼ�����б߰�Ȩֵ��С��������

    unsigned long long money = 0;
    Node.build(n);
    for(int i=0; i<m; i++){//��Ȩֵ��С�ı߿�ʼ����ÿ����
        if(Node.judge(line[i].from, line[i].to) == false){//�������ͨ����ô���в���
            money += line[i].value;
            Node.merge(line[i].from, line[i].to);
        }
    }
    cout<<money;
    return 0;

}
