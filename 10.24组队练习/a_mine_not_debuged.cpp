/**
 * @Author: zjt
 * @Date:   27-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: a.cpp
 * @Last modified by:   zjt
 * @Last modified time: 28-Oct-2020
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
	//string name,color;
    int name_id;
    int color_id;
	int val;
};//a[maxn];
vector< vector<node> > a;
vector<node>v[4];

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
map <int,bool> bonus_name;
map <int,int> max_name_bc,max_name_nbc;
string color_;
int ans = 0;

double k[5] = {0,0.1,0.2,0.3};

bool cmp(node a,node b) {
	return a.val>b.val;
}
bool cmpvector(node a,node b){
	return a.val>b.val;
}

int p[5]; // selected
int pos[5]; // size of each group

bool vis[maxn];
int sel[5];
void dfs(int col,int cnt, int sum, double mul){ // cnt  selected
    cout<<"col "<<col<<" cnt:"<<cnt<<" "<<endl;
	if(cnt == 5){
		ans = max(ans,(int)((double)sum*mul));
		return;
	}
    fori(i,col+1,3){
        fori(j,0,5){

            int same_cnt = 0;
            vector<int> ok_pos;
            fori(tti,0,j-1){
                int t = same_cnt;
                fori(ti,0,cnt-1){
                    if(v[i][tti].name_id == sel[i]) same_cnt++;
                }
                if(same_cnt == t) ok_pos.push_back(tti);
            }
            int pos_cnt = ok_pos.size();
            if(pos_cnt ==0) continue;
            int tsum = 0;
            if(j-same_cnt+cnt<=5){
                fori(ti,0,pos_cnt-1){
                    node t = v[i][ok_pos[ti]];
                    sel[cnt++] = t.name_id;
                    tsum += t.val;
                }
            }
            dfs(col+1,cnt+ok_pos.size(),sum+tsum,mul + k[i]*pos_cnt );

        }
    }
}

int main()
{
	int T;
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif

    while(cin>>T){
    	while(T--)
    	{
    		int  n;
    		cin >> n;
    		memset(p,0,sizeof(p));
    		memset(pos,0,sizeof(pos));
            memset(v,0,sizeof(v));
            max_name_bc.clear();
            max_name_nbc.clear();
			bonus_name.clear();
			used.clear();
			names.clear();
			colors.clear();
			name_id_cnt = 0;
			color_id_cnt = 0;
            a.clear();

    		for(int i = 1 ; i <= n; i++){
                string name,color;
                int val;
    			cin >>name >>color >>val;
				int nid = get_name_id(name);
				int cid = get_color_id(color);
                node t ={nid,cid,val};
                if(nid<=a.size()){
                    a[nid-1].push_back( t );
                }else{
                    a.resize(a.size()+1);
                    a[nid-1].push_back( t );
                }
			}

    		for(int i = 1 ; i <= 5; i++)
    		{
    			string s;
    			cin >> s;
				if(names[s]) bonus_name[names[s]] = 1;
    		}
    		cin >> color_;
			if(colors[color_]) bonus_color_id = colors[color_];

            fori(i,0,(ll)a.size()-1){
                sort( a[i].begin(), a[i].end(),cmpvector);
                int bonus_maxp_pos=-1,nbonus_maxp_pos=-1;
                int bonus_maxval = 0, nbonus_maxval = 0;

                bool flag1 = false, flag2 = false;
                fori(j,0,(ll)a[i].size()-1){
                    int clrid = a[i][j].color_id;
                    int val =  a[i][j].val;
                    if(clrid == bonus_color_id) {
                        flag1 = true;
                        if(val>bonus_maxval) {
                            bonus_maxval = val;
                            bonus_maxp_pos = j;
                        }
                    } else {
                        flag2 =true;
                        if(val>nbonus_maxval) {
                            nbonus_maxval = val;
                            nbonus_maxp_pos = j;
                        }
                    }
                }
                node bt,nt;
                if(flag1) bt= a[i][bonus_maxp_pos];
                if(flag2) nt= a[i][nbonus_maxp_pos];
                a[i].clear();
                if(flag1) a[i].push_back(bt);
                if(flag2) a[i].push_back(nt);
            }

            fori(i,0,(ll)a.size()-1)
    		{
                fori(j,0,(ll)a[i].size()-1){
                    int name_id = i+1;
        			if(!bonus_name[name_id] && a[i][j].color_id != bonus_color_id)
        				v[0].push_back(a[i][j]);
                    if(bonus_name[name_id] && a[i][j].color_id != bonus_color_id)
        				v[1].push_back(a[i][j]);
        			if(!bonus_name[name_id] && a[i][j].color_id == bonus_color_id)
        				v[2].push_back(a[i][j]);
        			if(bonus_name[name_id] && a[i][j].color_id == bonus_color_id)
        				v[3].push_back(a[i][j]);
                }
    		}
    		for(int i = 0 ; i <= 3; i++)
    			sort(v[i].begin(),v[i].end(),cmp);
    		ans = 0;
            cout<<"here"<<endl;
    		dfs(0,0,0,1);
    		cout << ans <<endl;
    	}
    }
	return 0;
}
