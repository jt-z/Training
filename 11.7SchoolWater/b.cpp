/**
 * @Author: zjt
 * @Date:   07-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: b.cpp
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

//-----------ufds--start
const LL maxn=1e4+10;
LL pp[maxn];
LL ofind(LL x){
   return pp[x]==-1 ? x:pp[x]=ofind(pp[x]);
}
void merge(LL u,LL v){
 LL pu,pv;
 pu=ofind(u);
 pv=ofind(v);
 if(pu!=pv) pp[pu]=pv;
}
//-----------ufds--end
struct node{
    int id,x,y;
    node(int a=0,int b=0,int c=0) : id(a),x(b),y(c){}
};
bool cmpy(const node &a, const node &b){
    return a.y<b.y;
}
bool cmpx(const node &a, const node &b){
    return a.x<b.x;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  int T,n,k;
  while(cin>>T){
      while(T--){
          cin>>n>>k;
          std::vector< node> v;
          mem(pp,-1);
          fori(i,1,n){
              int x,y;
              cin>>x>>y;
              v.push_back(node(i,x,y) );
          }
          sort(v.begin(),v.end(),cmpx);

          int p = 0;
          bool flag = true;
          int cnt =0;
          std::vector<std::set<int>  > vv;

          while(p<v.size()){
              node t = v[p];
              if(flag)  flag=false;
              if(p+1<v.size() ){
                node nt = v[p+1];
                if(nt.x - t.x > k) flag =true;
                else  merge(t.id,nt.id);
              }
              p++;
          }
          sort(v.begin(),v.end(),cmpy);
          p = 0;
          while(p<v.size()){
              node t = v[p];
              if(flag)  flag=false;
              if(p+1<v.size() ){
                node nt = v[p+1];
                if(nt.y - t.y > k)  flag =true;
                else merge(t.id,nt.id);
              }
              p++;
          }

          cnt = 0;
          fori(i,1,n) cnt = pp[i]==-1? cnt+1:cnt;
          cout<<cnt<<endl;
          continue;
      }
  }

return 0;
}
