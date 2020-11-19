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

//-----------ufds--start
 LL p[maxn];
 LL ofind(LL x){
 	return p[x]==-1 ? x:p[x]=ofind(p[x]);
 }
 void merge(LL u,LL v){
  LL pu,pv;
  pu=ofind(u);
  pv=ofind(v);
  if(pu!=pv) p[pu]=pv;
 }
//-----------ufds--end


void init(){fori(i,0,n-1) g[i].clear();}
void add_edge(int u,int v) /* u->v */{g[u].push_back(v);}

void dfs(int u){
    //cout<<"u "<<u<<endl;
    fori(i,0,(int)g[u].size()-1){
        int v = g[u][i];
        if(!vis[v]){
            vis[v] = true;
            dfs(v);
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
      mem(p,-1);
      fori(i,1,m){
          int u,v;
          cin>>u>>v; // u → v
          add_edge(u,v);
      }

      vis[6] = true;
      dfs(6);

      dv.clear();
      fori(i,1,n){
          if(i!=6 && vis[i] == false){
              dv.insert(i);
          }
      }

      memset(du,0,sizeof(du));
      foreach(e,dv){
        int i = *e;
        fori(j,0,(int)g[i].size()-1)
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
            dfs(u);
        } else {
            vis[u] =true;
            dfs(u);
        }
      }

      fori(i,1,n){
        if(!vis[i]){
            vis[i] = true;
            cnt++;
            dfs(i);
        }
      }

      cout<<cnt<<endl;

  }

return 0;
}
