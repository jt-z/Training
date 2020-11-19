/**
 * @Author: zjt
 * @Date:   08-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: C.cpp
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


int n;

//-------------------s
void get_primefactor(LL m,vector <PII> &m_factor) {//注意m必须大于1.
    if(m<=1) while(1);
    m_factor.clear();
    for(LL i=2;i*i<=m;i++) {
      if(m%i==0) {
          LL cnt=0;
          while(m%i==0)  {m/=i;cnt++;}
          m_factor.push_back(make_pair(i,cnt));
      }
    }
    if(m!=1) m_factor.push_back(make_pair(m,1) );
}
//-------------------e



int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  int T;
  cin>>T;
  while(T--){
    cin>>n;
    std::vector<PII> v;
    if(n==1) {cout<<"NO"<<endl; continue;}
    get_primefactor(n,v);
    int cnt = 1;
    foreach(e,v) cnt = cnt* (e->second+1);
    string ans;
    cnt++;
    ans = cnt%2==0? "NO" : "YES";
    cout<<ans<<endl;
  }

return 0;
}
