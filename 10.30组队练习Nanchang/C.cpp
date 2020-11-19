
/**
 * @Author: zjt
 * @Date:   30-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: c.cpp
 * @Last modified by:   zjt
 * @Last modified time: 30-Oct-2020
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


const int mod = 1000000007;
ll h[100005];
ll qsm(ll a,ll b){
    //cout<<"a^b"<<a<<" "<<b<<" ";
    ll ret =1;
    while(b){
        if(b&1) ret = (ret*a)%mod;
        b/=2;
        a = a*a%mod;
    }
    //cout<<"ret  "<<ret<<endl;
    return ret;
}
int main()
{
  ios::sync_with_stdio(false);
  //freopen("local.in","r",stdin);
  int t;
  string s;
  while(cin>>t){
      while(t--){
          cin>>s;
          int pos = 0;
          h[0] = 0;
          int m = 0;
          int cnt0 = 0;
          ford(i,(int)s.size()-1,0){
              if(s[i] == '0'){
                 cnt0++;
              } else{
                pos++;
                m++;
                h[pos] = h[pos-1] + cnt0;
                cnt0 = 0;
              }

          }
          //fori(i,1,m) cout<<h[i]<<" ";
          //cout<<endl;
          ll ans = 1;
          ll t2 = 1, t3 =1;
          fori(i,1,m){
             ll temp = (qsm(2,h[i]) * qsm(3,i-1))%mod;
             ans = (ans + temp)%mod;
          }
          cout<<ans<<endl;
      }
  }


return 0;
}
