/**
 * @Author: zjt
 * @Date:   12-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: 3037.cpp
 * @Last modified by:   zjt
 * @Last modified time: 18-Oct-2020
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
typedef long long  ll;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(ll (i)=(ll)(l);(i)<=(ll)(u);++(i))
#define ford(i,l,u) for(ll (i)=(ll)(l);(i)>=(ll)(u);--(i))


const int maxn=1e3+5;
const int maxm=2e3+5;
struct Edge{
    int u,v,next,w;
    Edge(){}
    Edge(int pu,int pv,int pn,int pw) {u=pu; v=pv; next=pn; w=pw;}
}e[maxm];
int cnt,n,m;
int head[maxn];
int vis[maxn];// 注意数组的类型定义，之前一开始定义为了bool类型，可是自己却用的1和-1来代表有效性。
bool valid[maxn];
int qu,qv;

void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
void insert(int u,int v,int w){
    e[cnt]=Edge(u,v,head[u],w);
    head[u]=cnt++;
}
void visit(int u){
    for(int i=head[u];i!=-1;i=e[i].next){
        cout<<"u->v:w "<<e[i].u<<"->"<<e[i].v<<":"<<e[i].w<<endl;
    }
}

bool dfs_df(int u){
    //cout<<"22"<<u;
    vis[u] = 1;
    //cout<<"u is "<<u<<""<<endl;
    if(u == qv) return true;

    //cout<<"vis u:"<<u<<endl;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v = e[i].v;
        //cout<<"vis[v] "<<v<<"  000"<<vis[v]<<endl;
        if(valid[v] == 0 || vis[v]==1 ) continue;

        //cout<<"v : "<<v<<endl;
        vis[v] = 1;
        if(dfs_df(v) ) return true;
        vis[v] = -1;
    }

    return false;
}

int solve(){
    mem(vis,-1);
    mem(valid,1);
    //cout<<1<<endl;
    if( dfs_df(qu) == false ) return -1;
    //cout<<33;
    int DF_cnt=0;
    fori(u,1,n){
        //clear Edges
        if(u==qu||u==qv) continue;
        valid[u] = 0;

        mem(vis,-1);
        if (  dfs_df(qu) == false ) DF_cnt ++;
        valid[u] = 1;
    }
    return DF_cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  //freopen("local.in","r",stdin);
  init();
  cin>>n>>m;
  fori(i,1,m){
      int u,v;
      cin>>u>>v;
      insert(u,v,1); // w=1  valid  0 invalid
      insert(v,u,1);
  }
  cin>>qu>>qv;
  //for(int i=1;i<=n; i++) {visit(i); cout<<endl<<endl;}
  //cout<<endl;

  cout<<solve()<<endl;

return 0;
}
