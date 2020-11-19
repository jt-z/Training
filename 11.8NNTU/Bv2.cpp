/**
 * @Author: zjt
 * @Date:   08-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: B.cpp
 * @Last modified by:   zjt
 * @Last modified time: 08-Nov-2020
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long  LL;
typedef pair<int,int> PII;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define ford(i,l,u) for(LL (i)=(LL)(l);(i)>=(LL)(u);--(i))

int n,m;

const int maxn=5000+5;
vector<int> g[maxn];
int du[maxn],L[maxn];

bool acc[maxn],vis[maxn];// 6 access
std::set<int> dv;
bool vissc[maxn];
//-------
const int N=100010;
struct data
{
    int to,next;
} tu[N*2];
int head[N];
int ip;
int dfn[N], low[N];///dfn[]表示深搜的步数，low[u]表示u或u的子树能够追溯到的最早的栈中节点的次序号
int sccno[N];///缩点数组，表示某个点对应的缩点值
int step;
int scc_cnt;///强连通分量个数
void init()
{
    ip=0;
    memset(head,-1,sizeof(head));
}
void add(int u,int v)
{
    tu[ip].to=v,tu[ip].next=head[u],head[u]=ip++;
}
vector<int> scc[N];///得出来的缩点，scc[i]里面存i这个缩点具体缩了哪些点
stack<int> S;
void dfs(int u)
{
    dfn[u] = low[u] = ++step;
    S.push(u);
    for (int i = head[u]; i !=-1; i=tu[i].next)
    {
        int v = tu[i].to;
        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!sccno[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        scc_cnt += 1;
        scc[scc_cnt].clear();
        while(1)
        {
            int x = S.top();
            S.pop();
            if (sccno[x] != scc_cnt) scc[scc_cnt].push_back(x);
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}
void tarjan(int n)
{
    memset(sccno, 0, sizeof(sccno));
    memset(dfn, 0, sizeof(dfn));
    step = scc_cnt = 0;
    for (int i = 1; i <=n; i++)
        if (!dfn[i]) dfs(i);
}

//-------

void add_edge(int u,int v) /* u->v */{g[u].push_back(v);}

void dfs2(int u){
    //cout<<"u "<<u<<endl;
    fori(i,0,(int)g[u].size()-1){
        int v = g[u][i];
        if(!vis[v]){
            vis[v] = true;
            dfs2(v);
        }
    }
}
int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  while(cin>>n>>m){

      fori(i,1,n) g[i].clear();
      mem(acc,false);
      mem(vis,false);
      init();
      fori(i,1,m){
          int u,v;
          cin>>u>>v; // u → v
          add_edge(u,v);
          add(u,v);
      }
      tarjan(n);

      vis[6] = true;
      dfs2(6);

      mem(vissc,0);
      dv.clear();
      fori(i,1,n){
          if(i!=6 && vis[i] == false){
              dv.insert(i);
          } else {
              vissc[ sccno[i] ] = true;
          }
      }



      memset(du,0,sizeof(du));
      fori(i,1,n){
        fori(j,0,(int)g[i].size()-1){
            int v =  g[i][j];
            
        }
          du[g[i][j]]++;
      }
      queue<int> Q;
      foreach(e,dv){
        int i = *e;
        if(!du[i]) Q.push(i);
      }
      //cout<<Q.size()<<endl;
      //continue;
      int cnt = 0;
      while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(!vis[u]) {
            cnt++;
            vis[u] =true;
            dfs2(u);
        } else {
            vis[u] =true;
            dfs2(u);
        }
      }

      fori(i,1,n){
        if(!vis[i]){
            vis[i] = true;
            cnt++;
            dfs2(i);
        }
      }

      cout<<cnt<<endl;

  }

return 0;
}
