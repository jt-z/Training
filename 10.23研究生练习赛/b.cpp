/**
 * @Author: zjt
 * @Date:   23-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: b.cpp
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


// struct pro{
//     int time;
//     int value;
//     bool operator <(const pro& x, const pro& y){
//         return x.time<
//     }
// };
int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  int T,n,m;
  PII p[5];
  while(cin>>T){
      while(T--){
          cin>>n>>m;
          fori(i,1,n) cin>>p[i].first;// time
          fori(i,1,n) cin>>p[i].second;// value

         int valA = 0,valB = 0;
         sort(p+1,p+1+n); // first
         int res = m;
         int id = 1;
         while(res>0 && id<=n){
            if(res >= p[id].first) {
                valA += p[id].second;
                res -= p[id].first;
                id ++;
            } else {
                break;
            }

         }


         res = m;
         fori(i,1,n) swap(p[i].first,p[i].second);// first val
         sort(p+1,p+1+n); // first
         reverse(p+1,p+1+n);
          id = 1;
         while(res>0 && id<=n){
            if(res >= p[id].second) {
                valB += p[id].first;
                res -= p[id].second;
                id ++;
            } else {
                break;
            }

         }

         string ans;
         if(valA>valB) ans = "A";
         else if(valA < valB) ans = "B";
         else ans = "SAME";
         cout<<ans<<endl;
      }
  }

return 0;
}
