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

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  int t,n;
  int a[100];
  while(cin>>t){
      fori(i,1,t){
        cin>>n;
        int cntall=0;
        int sp=0,ep;
        fori(i,1,n) {
            cin>>a[i];
            cntall = a[i]==0? cntall : cntall+1;
            if(sp ==0 && a[i] ) sp = i;
            ep = a[i]==1? i:ep;
        }

        int cnt = 0;
        fori(i,sp,ep){
            cnt = a[i]==0? cnt+1: cnt;
        }
        cout<<cnt<<endl;


        continue;
        int cntmid = (cntall+1)/2;
        int pos;
        int cnttemp = 0;
        fori(i,1,n) {
            cnttemp += a[i];
            if(cnttemp == cntmid){
                pos = i;
                break;
            }
        }
        int ans = 0 ;
        for(int i=1;i<=n;){
            if(a[i]==0) {i++; continue;}
            int tj=i;
            while(tj+1<=n && a[tj+1]==1) tj++;
            if(tj == i){
                if(i<=pos){
                    fori(j,i,pos){
                        ans = a[j] == 0?  ans+1:ans;
                    }
                } else if(i> pos){
                   fori(j,pos,i-1){
                        ans = a[j] == 0?  ans+1:ans;
                   }
               }
               i++;
           } else {

               if(i<=pos){
                   i=tj+1;
                   if(tj>=pos) { continue;}
                   fori(j,i,pos){
                       ans = a[j] == 0?  ans+1:ans;
                   }
               } else if(i> pos){
                  fori(j,pos,i-1){
                       ans = a[j] == 0?  ans+1:ans;
                  }
                    i = tj+1;
              }
           }
        }
        cout<<ans<<endl;

      }
  }
return 0;
}
