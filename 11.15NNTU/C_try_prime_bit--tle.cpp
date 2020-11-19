/**
 * @Author: zjt
 * @Date:   15-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: C.cpp
 * @Last modified by:   zjt
 * @Last modified time: 16-Nov-2020
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
#define lowbit(x) (x)&(-(x))
unordered_map<ll,ll> c;
//---------------s
//const ll maxn=50000+10;
//ll c[maxn]; // c1 c2 ... cn
ll n,m;
ll sum(ll x){
  //cout<<"x is ______ : "<<x<<endl;
  ll ret=0;
  while(x>0){
    //cout<<"c[x] "<<c[x]<<"  ";
    //cout<<"x: "<<x<<endl;
    ret+=c[x];
    x-=x&(-x);
  }
  //cout<<"sum: "<<ret<<endl;
  return ret;
}
void add(ll x,ll v){
  while(x<=n){
    c[x]+=v;
    //cout<<"add c[x] "<<c[x]<<endl;
    //cout<<x<<endl;
    x+=x&(-x);
  }
}
void add2(ll x,ll v){
        for(ll d=v;x<=n;x+=lowbit(x), d+=v){
            c[x]+=d;
        }
}
//----------------e

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  while(cin>>n>>m){
    fori(i,1,m){
        int op;
        cin>>op;
        if(op==1){
            ll x,v;
            cin>>x>>v;
            add2(x,v);
        } else {
            ll l,r;
            cin>>l>>r;
            cout<<sum(r) - sum(l-1)<<endl;
        }
    }
    c.clear();
  }

return 0;
}
