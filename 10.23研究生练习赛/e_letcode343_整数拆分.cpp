/**
 * @Author: zjt
 * @Date:   23-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: e.cpp
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

LL a[59];
int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  a[2] = 2;
  a[1] = 1;

  fori(i,3,59){
    a[i] = i;
    fori(j,1,i-1) a[i] = max((LL)a[i], (i-j)*a[j]);
    cout<<a[i]<<" ";//<<endl;
  }
  a[2] = 1;
  a[3] = 2;

  cout<<endl;

  int t,n;
  cin>>n;
  cout<<a[n]<<endl;

return 0;
}
