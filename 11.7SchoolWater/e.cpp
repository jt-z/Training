/**
 * @Author: zjt
 * @Date:   07-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: e.cpp
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

int gcd(int a, int b){
    return b==0? a: gcd(b,a%b);
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  int T,n;
  while(cin>>T){
      while(T--){
          cin>>n;
          int a ;
          cin>>a;
          fori(i,2,n) { int b; cin>>b; a = gcd(max(a,b),min(a,b));}
          cout<<a*n<<endl;
      }
  }

return 0;
}
