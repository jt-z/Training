/**
 * @Author: zjt
 * @Date:   26-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: a.cpp
 * @Last modified by:   zjt
 * @Last modified time: 26-Oct-2020
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
  while(cin>>n){
      fori(i,1,n){
          int cnt = 0;
          fori(j,1,4){
              int a;
              cin>>a;
              if(a>0) cnt++;
          }
        string ans;
      if(cnt ==0 ) ans="Typically Otaku";
      else if(cnt ==  1) ans ="Eye-opener";
      else if(cnt == 2) ans = "Young Traveller";
      else if(cnt ==3 ) ans = "Excellent Traveller";
      else ans = "Contemporary Xu Xiake";
        cout<<ans<<endl;
      }
  }

return 0;
}
