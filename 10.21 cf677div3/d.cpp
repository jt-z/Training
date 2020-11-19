/**
 * @Author: zjt
 * @Date:   23-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: d.cpp
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
  int t,n;
  int a[5001];
  while(cin>>t){
      while(t--){
          cin>>n;
          fori(i,1,n) cin>>a[i];
          bool all_same =true;
          fori(i,2,n) if(a[i] != a[1] ) {all_same = false;  break;}
          if(all_same) cout<<"NO"<<endl;
          else{
            int cl1 = a[1];
            int pos2;
            cout<<"YES"<<endl;
            fori(i,1,n){
                if(a[i]!=cl1) {pos2 = i; cout<<1<<" "<<i<<endl;}
            }
            fori(i,1,n){
                if(a[i] == cl1 && i!=1){
                    cout<<pos2<<" "<<i<<endl;
                }
            }
          }

      }
  }
return 0;
}
