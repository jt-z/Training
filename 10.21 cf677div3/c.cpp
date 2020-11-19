/**
 * @Author: zjt
 * @Date:   23-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: c.cpp
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

int a[300005];
int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  int t,n;
  while(cin>>t){
      while(t--){
          cin>>n;
          fori(i,1,n) {
              cin>>a[i];
             /// cout<<a[i]<<" ";
          }
          //cout<<endl;

          int ans = -1;
          int maxm=a[1];
          fori(i,2,n) {

              maxm =  max(maxm, a[i]);
              if(a[i]!=a[1]) ans = 0;
            }
          //cout<< "maxm "<<maxm<<endl;
          if(ans ==0) {
              fori(i,1,n){
                  if( (i-1>=1) && (a[i-1]==maxm) && a[i]!=maxm) {ans = i-1; break;}
                  if( (i+1<=n) && (a[i+1]==maxm)  && a[i]!=maxm) {ans = i+1;
                  //cout<<"ans "<<ans<<" i"<<i<<endl; break;
                }
              }
          }
          cout<<ans<<endl;;
      }
  }
return 0;
}
