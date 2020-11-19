/**
 * @Author: zjt
 * @Date:   15-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: 3053.cpp
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


int m = 1000;
bool vis[1010000];

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}



bool f(ll x){
    ll sq = sqrt(x);
   if( sq * sq == x  )  return false;
   else return true;
}
int tol;
int v[1000000];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif

  int T;
  ll n;

  mem(vis,0);
  //std::vector<int> v;
  tol = 0;
  fori(i,2,m){
      if(vis[i]){
        for(int j = i*i; j<=n;j+=i) vis[j] = 1;
      }
  }
  fori(i,2,1000000) if(!vis[i] ) v[tol++] = i;

  while(cin>>T){
    while(T--){
     cin>>n;
     std::vector<PII> vv;
     int ans;
     bool flag = false;
     //cout<<"n is :"<<n<<endl;
     fori(i,0,tol-1){
         int p = v[i];
         if( n%p==0){
             int cnt = 0;
             while(n%p==0) {cnt++; n/=p; if(n==0) break;}
             vv.push_back(make_pair(p,cnt));
             if(!flag) {ans = cnt; flag=true;}
             else ans = gcd(ans,cnt);
         }
     }
     //cout<<"factor and power: "<<endl;
     //foreach(e,v) cout<<e->fir<<" "<<e->sec<<endl;
     //cout<<endl;
     if(vv.size()==0){
         ll sq = sqrt(n);
        if( sq * sq == n  ) ans  = 2 ;
        else ans = 1;
    } else {
        if( n!=0 ) {
            ans = 1;
        }
    }

     cout<<ans<<endl;

    }
}
  //cout<<(int)sqrt(900000000l*900000000l)<<" "<<(900000000l*900000000l) <<endl;
  //cout<<(int)sqrt(900000000l*900000000l)<<" "<<(2*900000000l*900000000l) <<endl;

return 0;
}
