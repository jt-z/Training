/**
 * @Author: zjt
 * @Date:   27-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: a.cpp
 * @Last modified by:   zjt
 * @Last modified time: 27-Oct-2020
 */



#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define maxn 100005
typedef long long  ll;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(ll (i)=(ll)(l);(i)<=(ll)(u);++(i))
#define ford(i,l,u) for(ll (i)=(ll)(l);(i)>=(ll)(u);--(i))

int nameid[maxn],colorid[maxn];
struct node
{
	string name,color;
	int val;
}a[maxn],v[4][maxn];

int name_id_cnt,color_id_cnt;
map<string,int> names,colors;
int get_name_id(string name){
	if(!names[name]) {
		names[name] = ++name_id_cnt;
	}
	return names[name];
}
int get_color_id(string color){
	if(!colors[color]) {
		colors[color] = ++color_id_cnt;
	}
	return colors[color];
}


set<string> used;
int bonus_color_id;
map <int,bool> dict;
map <int,int> max_name[4];
string color_;
int ans = 0;

double k[5] = {0,0.1,0.2,0.3};

bool cmp(node a,node b)
{
	return a.val>b.val;
}

int p[5]; // selected
int pos[5]; // size of each group

void dfs(int t, int num, double mul)
{
	if(t>=5)
	{
		ans = max(ans,(int)((double)num*mul));
		return;
	}
	for(int i = 0; i<=3; i++)
	{
		if( p[i] <= min(4,pos[i]-1) )
		{
			p[i]++;
			used.insert(v[i][p[i]].name);
			dfs(t+1,num+v[i][p[i]-1].val, mul+k[i]);
			used.erase(v[i][p[i]].name);
			dfs(t,num, mul);
			p[i]--;
		}
	}
}

int main()
{
	int T;
    freopen("local.in","r",stdin);
    while(cin>>T){
    	while(T--)
    	{
    		int  n;
    		cin >> n;
    		memset(p,0,sizeof(p));
    		memset(pos,0,sizeof(pos));
            memset(v,0,sizeof(v));
			fori(i,0,3) max_name[i].clear();
			dict.clear();
			used.clear();
			names.clear();
			colors.clear();
			name_id_cnt = 0;
			color_id_cnt = 0;

    		for(int i = 1 ; i <= n; i++){
    			cin >> a[i].name >> a[i].color >> a[i].val;
				get_name_id(a[i].name);
				get_color_id(a[i].color);
				//max_name[name_id] = max(max_name[name_id], a[i].val);
			}
    		for(int i = 1 ; i <= 5; i++)
    		{
    			string s;
    			cin >> s;
				if(names[s]) dict[names[s]] = 1;
    		}
    		cin >> color_;
			if(colors[color_]) bonus_color_id = colors[color_];
    		for(int i = 1 ; i <= n; i++)
    		{
				int name_id = names[ a[i].name ];
    			if(!dict[name_id] && a[i].color != color_)
				{

    				v[0][pos[0]].val = a[i].val,v[0][pos[0]++].name = a[i].name;

				}
    			if(dict[name_id] && a[i].color != color_)
    				v[1][pos[1]].val = a[i].val,v[1][pos[1]++].name = a[i].name;
    			if(!dict[name_id] && a[i].color == color_)
    				v[2][pos[2]].val = a[i].val,v[2][pos[2]++].name = a[i].name;
    			if(dict[name_id] && a[i].color == color_)
    				v[3][pos[3]].val = a[i].val,v[3][pos[3]++].name = a[i].name;

    		}

    		for(int i = 0 ; i <= 3; i++)
    			sort(v[i],v[i]+pos[i],cmp);

    		ans = 0;
    		dfs(0,0,1);
    		cout << ans <<endl;
    	}
    }
	return 0;
}
