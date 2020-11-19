/**
 * @Author: zjt
 * @Date:   23-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: e.cpp
 * @Last modified by:   zjt
 * @Last modified time: 23-Oct-2020
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long  LL;
typedef pair<int,int> PII;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define ford(i,l,u) for(LL (i)=(LL)(l);(i)>=(LL)(u);--(i))

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif

  int n;
  LL ans;
  while(cin>>n){
    LL sn = n/2;
    ans = 1;
    fori(i,1,n) {
        if(i == sn || i == n) continue;
        ans*=i;
    }
    ///fori(i,1,sn-1) ans = ans* i*i;
    //ans/=2;
    cout<<ans<<endl;
  }
return 0;
}
