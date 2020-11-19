/**
 * @Author: zjt
 * @Date:   10-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: Bv1add.cpp
 * @Last modified by:   zjt
 * @Last modified time: 11-Nov-2020
 */
 /**
  * @Author: zjt
  * @Date:   08-Nov-2020
  * @Email:  jianting112358@gmail.com
  * @Filename: B.cpp
 * @Last modified by:   zjt
 * @Last modified time: 11-Nov-2020
  */
 #include <bits/stdc++.h>
 using namespace std;
 typedef long long  LL;
 typedef pair<int,int> PII;


  //#define debug
 #define mem(A, X) memset(A, X, sizeof A)
 #define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
 #define fori(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
 #define ford(i,l,u) for(LL (i)=(LL)(l);(i)>=(LL)(u);--(i))

 int n,m;

 const int maxn=5000+5;
 vector<int> g[maxn];
 bool acc[maxn],good[maxn],bad[maxn],vis[maxn],vis2[maxn];// 6 access
 int cnt[maxn];

 void init(){fori(i,1,n) g[i].clear();}
 void add_edge(int u,int v) /* u->v */{g[u].push_back(v);}

 void dfs1(int u){
     //cout<<"u "<<u<<endl;
     vis[u]= true, good[u] = true;
     fori(i,0,(int)g[u].size()-1){
         int v = g[u][i];
         if(!vis[v]){
             dfs1(v);
         }
     }
 }

 int dfs2(int u){
     if(cnt[u]) return cnt[u];
     cnt[u] = 1;
     fori(i,0,(int)g[u].size()-1){
         int v = g[u][i];
         if(!good[v] && !vis2[v]){
             vis2[v] = true;
             cnt[u] += dfs2(v);
         }
     }
     return cnt[u];
 }

 void dfs3(int u){
      vis[u]= true, good[u] = true;
      fori(i,0,(int)g[u].size()-1){
          int v = g[u][i];
          if(!vis[v] && !good[v]){
              dfs3(v);
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
       init();
       mem(good,false);
       mem(vis,false);
       fori(i,1,m){
           int u,v;
           cin>>u>>v; // u → v
           add_edge(u,v);
       }
       dfs3(6);
       #ifdef debug
       cout<<"dfs1 good:"<<endl;
       fori(i,1,n) {
           if(good[i]) cout<<i<<" ";
       }
       cout<<endl;
       #endif

       mem(cnt,0);
       std::vector<PII> vii;
        fori(i,1,n){
            mem(vis2,false);
            if(!good[i]) vii.push_back(make_pair(dfs2(i),i) );
        }
        sort(vii.begin(),vii.end());
        reverse(vii.begin(),vii.end());

        #ifdef debug
        cout<<"dfs2 vii cnt:"<<endl;
        foreach(e,vii) {
            cout<<"id: "<<e->second<<"  cnt: "<<e->first<<endl;
        }
        cout<<endl;
        #endif

        int res =0;
        foreach(e,vii){
            int u = e->second;
            if(!good[u] ){
                mem(vis,0);
                dfs3(u);
                res++;
            }
        }


        cout<<res<<endl;

        #ifdef debug
        cout<<"$$$$$$$$$$"<<endl;
        #endif
   }

 return 0;
 }
