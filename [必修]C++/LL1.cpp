#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<stack>
#include<set>
#include<cstring>
using namespace std;
map<char,int>getnum;
char gchar[100];         //��ö�Ӧ�ַ�
vector<string>proce;
int table[100][100];      //Ԥ�������
int num=0;int numvt=0;     //numvt���ս�����ϣ�0�ǡ�#����numvt�����
string first[100];
string follow[200];
void readin()
{
    memset(table,-1,sizeof(table));
    getnum['#']=0;
    gchar[0]='#';
    cout<<"�������ս������"<<endl;
    char x;
    do
    {
      cin>>x;
     getnum[x]=++num;
      gchar[num]=x;
    }while(cin.peek()!='\n');
     numvt=++num;
     getnum['@']=numvt;        //kong zi
     gchar[num]=('@');
    cout<<"��������ս������"<<endl;
    do
    {
      cin>>x;
      getnum[x]=++num;
      gchar[num]=x;
    }while(cin.peek()!='\n');
    cout<<"�������в���ʽ�������á�@����ʾ��,�ԡ�end������:"<<endl;
    string pro;
     while(cin>>pro&&pro!="end")
     {
         string ss;
         ss+=pro[0];
         for(int i=3;i<pro.size();i++)
         {
             if(pro[i]=='|')
             {
                  proce.push_back(ss);
                  ss.clear();ss+=pro[0];
             }
             else
             {
                 ss+=pro[i];
             }
         }
          proce.push_back(ss);
    }
}
void jiaoji(string &a,string b)  //a=a or b   ȡa,b������ֵ��a
{
    set<char>se;
    for(int i=0;i<a.size();i++)
       se.insert(a[i]);
    for(int i=0;i<b.size();i++)
       se.insert(b[i]);
    string ans;
    set<char>::iterator it;
    for(it=se.begin();it!=se.end();it++)
        ans+=*it;
    a=ans;
}
string get_f(int vn,int & has_0)     //dfs:vn���Ƴ��Ĳ������ֵ�vt���ϣ������ж�vn�ܷ��Ƴ�����
{
    if(vn==numvt)has_0=1;
    if(vn<numvt)return first[vn];
    string ans;
    for(int i=0;i<proce.size();i++)
        {
           if(getnum[proce[i][0]]==vn)
             ans+=get_f(getnum[proce[i][1]],has_0);
        }
    return  ans;
}
void getfirst()
{
    for(int i=1;i<=numvt;i++)     //�ս����first�����䱾��
    {
         first[i]+=('0'+i);
    }
    for(int j=0;j<proce.size();j++)    //ɨ�����в���ʽ
    {
        int k=0;int has_0=0;        //kɨ��ò���ʽ
       do{
            has_0=0;
            k++;
           if(k==proce[j].size())  //�Ƶ����һ���ˣ��򸽼ӿ���
           {
               first[getnum[proce[j][0]]]+=('0'+numvt);
               break;
          }                     //�ϲ�֮
           jiaoji(first[getnum[proce[j][0]]],get_f(getnum[proce[j][k]],has_0));
         }
      while(has_0);  //���޷��Ƴ�����Ϊֹ
    }
}
void print_first()
{
    cout<<"first������:"<<endl;
    for(int i=1;i<=num;i++)
     {
         cout<<"first ["<<gchar[i]<<"]: ";
        for(int j=0;j<first[i].size();j++)
          cout<<gchar[first[i][j]-'0']<<" ";
            cout<<endl;
     }
     cout<<endl;
}
void getfollow()
{
    jiaoji(follow[getnum[proce[0][0]]],"0");  //����ӡ�#����
    for(int j=0;j<proce.size();j++)       //ɨ���в���ʽ
    {
        for(int jj=1;jj<proce[j].size();jj++)   //ÿ�����ս����follow��
        {
          if(getnum[proce[j][jj]]<=numvt)continue;  //vt��follow��
         int k=jj; int has_0;
          do
         {
           has_0=0;
            k++;
           if(k==proce[j].size())   //�����Ƴ����֣�follow��=����ʽ��ߵ�vn��
           {
              jiaoji(follow[getnum[proce[j][jj]]],follow[getnum[proce[j][0]]]);
              break;
           }
          jiaoji(follow[getnum[proce[j][jj]]],get_f(getnum[proce[j][k]],has_0));
         }while(has_0);
        }
    }
}
void gettable()          //��Ԥ�������
{
   for(int i=0;i<proce.size();i++)   //ɨ���в���ʽ
   {
       if(proce[i][1]=='@')     //ֱ���Ƴ����ֵģ������£�follow��=����ʽ��ߵ�vn��Ԫ���
          {
             string flw=follow[getnum[proce[i][0]]];
             for(int k=0;k<flw.size();k++)
             {
               table[getnum[proce[i][0]]][flw[k]-'0']=i;
             }
          }
       string temps=first[getnum[proce[i][1]]];
       for(int j=0;j<temps.size();j++)               //����first��
       {

           if(temps[j]!=('0'+numvt))
           {
              table[getnum[proce[i][0]]][temps[j]-'0']=i;
           }
           else                                     //�п��ֵģ�����follw��
           {
               string flw=follow[getnum[proce[i][1]]];
              for(int k=0;k<flw.size();k++)
             {
                 table[getnum[proce[i][0]]][flw[k]-'0']=i;
             }
           }
       }
   }
}
string get_proce(int i)  //�ɶ�Ӧ�±��ö�Ӧ����ʽ��
{
    if(i<0)return " ";    //�޸ò���ʽ
    string ans;
    ans+=proce[i][0];
    ans+="->";
    //ans+=(proce[i][0]+"->");  ע���������У�˼֮���ɡ�
    for(int j=1;j<proce[i].size();j++)
       ans+=proce[i][j];
   return ans;
}
void print_table()
{
    cout<<"Ԥ����������£�"<<endl;
   for(int i=0;i<numvt;i++)
      cout<<'\t'<<gchar[i];
      cout<<endl;
   for(int i=numvt+1;i<=num;i++)
    {
       cout<<gchar[i];
       for(int j=0;j<numvt;j++)
       {
           cout<<'\t'<<get_proce(table[i][j]);
       }
       cout<<endl;
    }
    cout<<endl;
}
void print_follow()
{
    cout<<"follow�����£�"<<endl;
     for(int i=numvt+1;i<=num;i++)
     {
        cout<<"follow ["<<gchar[i]<<"]: ";
        for(int j=0;j<follow[i].size();j++)
         cout<<gchar[follow[i][j]-'0']<<" ";
            cout<<endl;
     }
     cout<<endl;
}
string word;
bool analyze()       //�ܿأ�������word�ĺϷ��ԣ����Ϸ���������в���ʽ��
{
    stack<char>sta;
    sta.push('#');sta.push(proce[0][0]);
    int i=0;
    while(!sta.empty())
    {
       int cur=sta.top();
       sta.pop();
       if(cur==word[i])       //���ս�����ƽ�
       {
           i++;
       }
       else  if(cur=='#')   //�ɹ�������
       {
           return 1;
       }
       else  if(table[getnum[cur]][getnum[word[i]]]!=-1) //���
       {

           int k=table[getnum[cur]][getnum[word[i]]];
           cout<<proce[k][0]<<"->";
          for(int j=1;j<proce[k].size();j++)
                 cout<<proce[k][j];
           cout<<endl;
           for(int j=proce[k].size()-1;j>0;j--)  //������ջ
                {  if(proce[k][j]!='@')
                   sta.push(proce[k][j]);
                }
       }
       else      //ʧ�ܣ�
       {
           return 0;
       }
    }
    return 1;
}
int main()
{
    readin();
    getfirst();
    getfollow();
    getfollow();
    gettable();
    print_first();
    print_follow();
    print_table();
   cout<<"�������֣�"<<endl;
   cin>>word;
    if(analyze())
        cout<<"succeed!������Ч�����ò���ʽ���ϡ�"<<endl;
    else   cout<<"error!"<<endl;
    return 0;
}

