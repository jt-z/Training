/**
 * @Author: zjt
 * @Date:   08-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: A.cpp
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

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  int x,y,a,b;
  while(cin>>x>>y>>a>>b){
      int res = 0;
      int del  = abs(x-y);
      int con  = min(x,y);
      if(a*2<=b){
         res+=  (x+y)*a;
     } else {
         res+= del*a;
         res+=con*b;
     }
     cout<<res<<endl;
  }

return 0;
}
