/**
 * @Author: zjt
 * @Date:   15-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: B.cpp
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

const int maxn =  1e7 +10;
const int mod =  998244353;
ll f[maxn];


//求逆元
ll inv(ll a, ll m)
{
    if (a == 1) return 1;
    return inv(m % a, m) * (m - m / a) % m;
}

ll q_power(ll a,ll b,ll m) {//return the a^b  mod m.
    a%=m;
    ll ans = 1;
    while(b){//用一个循环从右到左便历b的所有二进制位
        if(b&1) ans = (ans*a)%m;//乘到结果上，这里a是a^(2^i)%m
        b/=2;
        a = a*a%m;
    }
    return ans;
}


int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  ll inv4 = inv(4,mod);
  f[0] = f[1] = 1;
  fori(i,2,10000000) f[i] = i * (ll)f[i-1] %mod;
  ll T,n;
  while(cin>>T){
      while(T--){
          cin>>n;
          ll g =( ( ((n*n)%mod) * ((n+1)*(n+1)%mod ) %mod ) *inv4 ) %mod;
          ll fval  = q_power(f[n],2*n,mod);
          cout<<g<<" "<<fval<<endl;
      }
  }
return 0;
}
