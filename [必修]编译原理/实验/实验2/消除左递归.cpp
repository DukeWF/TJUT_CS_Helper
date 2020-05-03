#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cctype>
#include <map>
#include <set>
#define MAX 507

using namespace std;

class WF
{
    public:
        string left;
        set<string> right;
        WF ( const string& temp )
        {
            left = temp;
            right.clear();
        }
        void print ( )
        {
            printf ( "%s::=" , left.c_str() );
            set<string>::iterator it = right.begin();
            printf ( "%s" , it->c_str());
            it++;
            for ( ; it!= right.end() ; it++ )
                printf ( "|%s" , it->c_str() );
            puts("");
        }
        void insert ( const string& temp )
        {
            right.insert(temp);
        }
};

map<string,int> VN_dic;
vector<WF> VN_set;
string start;
bool used[MAX];

//消除间接左递归
void remove1 ( )
{
    for ( int i = 0 ; i < VN_set.size() ; i++ )
        for ( int j = 0 ; j < i ; j++ )
        {
            vector<string> cont;
            set<string>& right1 = VN_set[i].right;
            set<string>& right2 = VN_set[j].right;
            char ch = VN_set[j].left[0];
            set<string>::iterator it1 = right1.begin();
            set<string>::iterator it2;
            for ( ; it1 != right1.end() ; it1++ )
                if ( it1->at(0) == ch )
                    for ( it2 = right2.begin() ; it2 != right2.end() ; it2++ )
                        cont.push_back ( *it2 + it1->substr(1) ); 
            int nn = right1.size();
            while ( nn-- )
            {
                if ( right1.begin()->at(0) == ch ) 
                    right1.erase ( right1.begin() );
                else 
                {
                    cont.push_back ( *right1.begin() );
                    right1.erase ( right1.begin() );
                }
            }
            for ( int i = 0 ; i < cont.size() ; i++ )
                right1.insert ( cont[i] );
        }
#define DEBUG
#ifdef DEBUG
    for ( int i = 0 ; i < VN_set.size() ; i++ )
        VN_set[i].print();
#endif
}

//消除直接左递归
void remove2 ( )
{
    for ( int i = 0 ; i < VN_set.size() ; i++ )
    {
        char ch = VN_set[i].left[0];
        set<string>& temp = VN_set[i].right;
        set<string>::iterator it = temp.begin();
        string tt = VN_set[i].left.substr(0,1)+"\'";
        bool flag = true;
        for ( ; it != temp.end() ; it++ )
            if ( it->at(0) == ch )
            {
                VN_set.push_back ( WF(tt));
                VN_dic[tt] = VN_set.size();
                flag = false;
                break;
            }
        int x = VN_dic[tt]-1;
        if ( flag ) continue;
        vector<string> cont;
        set<string>& ss = VN_set[x].right;
        ss.insert ( "~" );
        while (!temp.empty())
        {
            if ( temp.begin()->at(0) == ch )
                ss.insert(temp.begin()->substr(1)+tt);
            else 
            {
                //cout << "YES : " << temp.begin()->substr(1)+tt;
                cont.push_back (temp.begin()->substr(0)+tt);
            }
            temp.erase(temp.begin());
        }
        puts ("");
        for ( int i = 0 ; i < cont.size() ; i++ )
        {
            //cout << cont[i] << endl;
            temp.insert ( cont[i] );
        }
    }
    
#define DEBUG
#ifdef DEBUG
    for ( int i = 0 ; i < VN_set.size() ; i++ )
        VN_set[i].print();
#endif

}

void dfs ( int x )
{
    if ( used[x] ) return;
    used[x] = 1;
    set<string>::iterator it = VN_set[x].right.begin();
    for ( ; it != VN_set[x].right.end(); it++ )
        for ( int i = 0 ; i < it->length() ; i++ )
            if ( isupper(it->at(i)) )
            {
                if ( it->length() > i+1 && it->at(i+1) == '\'' )
                    dfs ( VN_dic[it->substr(i,2)]-1 );
                else 
                    dfs ( VN_dic[it->substr(i,1)]-1 );
            }
}

//化简
void simplify ( )
{
    memset ( used , 0 , sizeof ( used ) );
    int x = VN_dic[start]-1;
    dfs ( x );
    puts ( "finish" );
    vector<WF> res;
    for ( int i = 0 ; i < VN_set.size() ; i++ )
        if ( used[i] ) 
            res.push_back ( VN_set[i] );
    VN_set.clear();
    VN_set = res;
}

void print () 
{
    puts("**********消除左递归后的结果********");
    for ( int i = 0 ; i < VN_set.size() ; i++ )
        VN_set[i].print();
    puts("");
}

int main ( )
{
    char buf[MAX];
    int n;
    VN_dic.clear();
    VN_set.clear();
    start="S";
    puts ("请输入文法G[S]的产生式数量");
    while ( ~scanf ("%d" , &n ) )
    {
        scanf ( "%d" , &n );
        while ( n-- )
        {
            scanf ( "%s" , buf );
            int len = strlen ( buf ),i;
            for ( i = 0 ; i < len ; i++ )
                if ( buf[i] == ':' ) 
                {
                    buf[i] = 0;
                    break;
                }
            string temp = buf;
            if ( !VN_dic[temp] )
            {
                VN_set.push_back ( WF(temp));
                VN_dic[temp] = VN_set.size();
            }
            int x = VN_dic[temp]-1;
            temp = buf+i+3;
            //cout <<"the right :  " << temp << endl;
            VN_set[x].insert(temp);
        }
        remove1();
        remove2();
        simplify();
        print();
        //puts ("请输入文法G[S]的产生式数量");
    }   
}


