/**
 * @Author: zjt
 * @Date:   15-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: D.cpp
 * @Last modified by:   zjt
 * @Last modified time: 15-Nov-2020
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef pair<int,int> PII;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(ll (i)=(ll)(l);(i)<=(ll)(u);++(i))
#define ford(i,l,u) for(ll (i)=(ll)(l);(i)>=(ll)(u);--(i))
#define fir first
#define sec second

const ll maxn=5e5+10;
const int mod = 1e9+7;
ll n,a[maxn],m;
string s;
struct mt{
  ll val,pos;
}temp[maxn];
ll ans;

//---------------s------线段树 区间增减
const ll maxterm=1e5+10;
const ll maxnode=4*maxterm;
ll nodesize,termsize;
ll cntb[maxnode],addv[maxnode];
void init(ll pt){
  termsize=pt;
  nodesize=termsize*4;
  fori(i,1,nodesize) cntb[i]=addv[i]=0;
}

ll pl,pr,val;
void maintain(ll o,ll L,ll R){
  cntb[o]=0;
  if(R>L){
    cntb[o]+=cntb[o*2]+cntb[o*2+1];
  }
  if(addv[o])  cntb[o]-=(R-L+1);
}
void update(ll o,ll L,ll R){
  if(pl<=L&&R<=pr) addv[o]=(addv[o]+val)%2;
  else {
    ll mid =L+(R-L)/2;
    if(pl<=mid) update(o*2,L,mid);
    else update(o*2+1,mid+1,R);
  }
  maintain(o,L,R);
}
void rev(ll ppl,ll ppr,ll value){
  pl=ppl, pr=ppr, val=value;
  update(1,1,termsize);
}


ll query(ll o,ll L,ll R,ll add){
  ll ret=0;
  if(pl<=L&&R<=pr) {
      if(add%2==1)  ret = (R-L+1 - cntb[o]);
      ret=cntb[o]; //+add*(R-L+1);
  }
  else {
    ll mid=L+(R-L)/2;
    if(pl<=mid) ret+=query(o*2,L,mid,add+addv[o]);
    if(mid+1<=pr) ret+=query(o*2+1,mid+1,R,add+addv[o]);
  }
  return ret;
}

ll get_sum(ll ppl,ll ppr){
  pl=ppl,pr=ppr;
  return query(1,1,termsize,0);
}
//------------e


int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  while(cin>>n>>m){// a 0  b 1    sum B
      cin>>s;
      init(n);
      int i= 0;
      while(i<n){
          if(s[i]=='B') {
             int prei = i;
             while(i<n && s[i]=='B' ) i++;
             rev(prei,i-1,1);
         } else {
             i++;
         }

      }
      int op;
      cin>>op;
      if(op==1){
          int l,r;
          cin>>l>>r;
          rev(l,r,1);
      }else {
          int l,r,qa,qb;
          cin>>l>>r>>qa>>qb;
          ll sumb = get_sum(l,r);
          ll suma = r-l +1 - sumb;
          ll ansa = (qa+(suma*qb%mod)%mod) ;
          ll ansb = (qb+(sumb*qa%mod)%mod) ;
          cout<<ansa<<" "<<ansb<<endl;
      }

  }


return 0;
}
