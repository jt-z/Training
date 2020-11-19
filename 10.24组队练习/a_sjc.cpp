/**
 * @Author: zjt
 * @Date:   27-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: a_sjc.cpp
 * @Last modified by:   zjt
 * @Last modified time: 28-Oct-2020
 */
 #include<bits/stdc++.h>
using namespace std;
#define maxn 100005
struct node
{
	string name,color;
	int val;
}a[maxn],v[4][maxn];

set<string> used;
map<string,int> ind[4];
map<string,int> dict;
string color_;
int ans = 0;

double k[6] = {0,0.1,0.2,0.3};

bool cmp(node a,node b)
{
	return a.val>b.val;
}

int p[6];
int pos[6];
int max(int a,int b){return a>b?a:b;}

void dfs(int t, int num, double mul)
{
 	 // if(t>=3)
 	 // {
 	 // 	//cout<<t<<" t --- "<<num <<" -- "<<mul<<". -"<<endl;
 	 // 	for(int i = 0; i<=3; i++)
	 	// {
	 	// 	cout<< p[i]<< " ";
	 	// }

 	 // }
 	 if(t>=5)
	{
		ans = max(ans,(int)num*mul);
		// for(set<string>:: iterator it = used.begin(); it!=used.end(); it++)
		// 		{
		// 			cout<< *it <<" ";
		// 		}
		// 		cout<<endl;
		return;
	}
	for(int i = 0; i<=3; i++)
	{
		if( p[i]+1<=min(pos[i],5) )
		{
			p[i]++;
			if(!used.count(v[i][p[i]-1].name))
			{
				used.insert(v[i][p[i]-1].name);
				// cout<< v[i][p[i]].name <<endl;

				// cout<<endl;
				//cout<< num+val[i][p[i]-1] <<" "<<mul+k[i]<<endl;
				dfs(t+1,num+v[i][p[i]-1].val, mul+k[i]);
				used.erase(v[i][p[i]-1].name);

		    }
			dfs(t,num, mul);
			p[i]--;

		}

	}
}



int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int  n;
		cin >> n;
		memset(p,0,sizeof(p));
		memset(pos,0,sizeof(pos));
        memset(v,0,sizeof(v));
        used.clear();
        dict.clear();
        for(int i = 0;i<=3;i++)ind[i].clear();
		for(int i = 1 ; i <= n; i++)
		{

			cin >> a[i].name >> a[i].color >> a[i].val;

		}
		for(int i = 1 ; i <= 5; i++)
		{
			string s;
			cin >> s;
			dict[s] = 1;
		}
		cin >> color_;

		for(int i = 1 ; i <= n; i++)
		{
			if(!dict[a[i].name] && a[i].color != color_)
			{
				if(ind[0][a[i].name])
					v[0][ind[0][a[i].name]].val = max(v[0][ind[0][a[i].name]].val , a[i].val);
				else
				{
					v[0][pos[0]].val = a[i].val;
					ind[0][a[i].name] = pos[0];
					v[0][pos[0]++].name = a[i].name;

				}

			}
			if(dict[a[i].name] && a[i].color != color_)
			{
				if(ind[1][a[i].name])
					v[1][ind[1][a[i].name]].val = max(v[1][ind[1][a[i].name]].val , a[i].val);
				else
				{
					v[1][pos[1]].val = a[i].val;
					ind[1][a[i].name] = pos[1];
					v[1][pos[1]++].name = a[i].name;

				}
			}
			if(!dict[a[i].name] && a[i].color == color_)
			{
				if(ind[2][a[i].name])
					v[2][ind[2][a[i].name]].val = max(v[2][ind[2][a[i].name]].val , a[i].val);
				else
				{
					v[2][pos[2]].val = a[i].val;
					ind[2][a[i].name] = pos[2];
					v[2][pos[2]++].name = a[i].name;

				}
			}

			if(dict[a[i].name] && a[i].color == color_)
			{
				if(ind[3][a[i].name])
					v[3][ind[3][a[i].name]].val = max(v[3][ind[3][a[i].name]].val , a[i].val);
				else
				{
					v[3][pos[3]].val = a[i].val;
					ind[3][a[i].name] = pos[3];
					v[3][pos[3]++].name = a[i].name;

				}
			}


		}


		for(int i = 0 ; i <= 3; i++)
			sort(v[i],v[i]+pos[i],cmp);


		ans = 0;

		dfs(0,0,1);

		cout << ans <<endl;


	}


/*

1
14
1 Power 100
1 Power 2
1 Power 3
2 t 100
2 t 17
3 p 45000
3 p 100
3 p 98
4 t 100
4 t 6
4 twer 100
5 Pure 45000
6 Power 2000
7 p 100
1 2 3 4 5
p


1
6
Saaya Power 10
Kokoro Happy 10
Kasumi Cool 10
Rimi Power 10
Aya Pure 10
Aya Power 2
Saaya Tae Kasumi Rimi Arisa
Power

 */

	return 0;
}
