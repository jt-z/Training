/**
 * @Author: zjt
 * @Date:   08-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: E.cpp
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
  LL f[100];
  f[1] = 1;
  f[2] = 2;
  fori(i,3,99) f[i] = f[i-1] + f[i-2];
  int n;
  while(cin>>n){
      cout<<f[n]<<endl;
    }
return 0;
}
