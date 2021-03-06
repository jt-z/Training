/**
 * @Author: zjt
 * @Date:   07-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: c.cpp
 * @Last modified by:   zjt
 * @Last modified time: 07-Nov-2020
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
  int T;
  while(cin>>T){
      while(T--){
         int n;
         cin>>n;
         int ans =0;
         while(n--){
             string s;
             cin>>s;
             ans+=s.size();
         }
         cout<<ans<<endl;
      }
  }

return 0;
}
