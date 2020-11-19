/**
 * @Author: zjt
 * @Date:   19-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: e.cpp
 * @Last modified by:   zjt
 * @Last modified time: 19-Oct-2020
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(ll (i)=(ll)(l);(i)<=(ll)(u);++(i))
#define ford(i,l,u) for(ll (i)=(ll)(l);(i)>=(ll)(u);--(i))

const int maxn = 10;
bool e[maxn][maxn];

bitset<7> bs;
bool vis[10]; //1-7
void dfs(int u){ //1-7
    vis[u] = true;
    fori(v,1,7){
        if(e[u][v] && bs[v-1] && vis[v]==false){
            vis[v] = true;
            dfs(v);
        }
    }
}
int main()
{
  ios::sync_with_stdio(false);
  freopen("local.in","r",stdin);
  mem(e,false);
  e[1][2] = true;
  e[1][6] = true;
  e[2][1] = true;
  e[2][3] = true;
  e[2][7] = true;
  e[3][2] = true;
  e[3][7] = true;
  e[3][4] = true;
  e[4][3] = true;
  e[4][5] = true;
  e[5][4] = true;
  e[5][7] = true;
  e[5][6] = true;
  e[6][5] = true;
  e[6][1] = true;
  e[6][7] = true;
  e[7][6] = true;
  e[7][2] = true;
  e[7][5] = true;
  e[7][3] = true;

  bs = 0;
  int res = 0;
  fori(i,1,127){
    bs = i;
    mem(vis,false);
    int cnt = 0;
    fori(node,1,7){
        if(bs[node-1] == 1 && vis[node-1] == false ) {
            dfs(node);
            cnt ++;
        }
    }
    if(cnt==1) {
        cout<<i<<endl;
        res ++;
        if(bs[0] == 1) cout<<"--";
        else cout<<" ";
        cout<<endl;
        if(bs[5] == 1) cout<<"|";
        else cout<<" ";
        cout<<" ";
        if(bs[1] == 1) cout<<"|";
        else cout<<" ";
        cout<<endl;

        if(bs[6] == 1) cout<<"--";
        else cout<<" ";
        cout<<endl;

        if(bs[4] == 1) cout<<"|";
        else cout<<" ";
        cout<<" ";
        if(bs[2] == 1) cout<<"|";
        else cout<<" ";
        cout<<endl;

        if(bs[3] == 1) cout<<"--";
        else cout<<" ";
        cout<<endl;

        cout<<"$$$$$$"<<endl;
    }
  }
  cout<<res<<endl;

  return 0;
}
