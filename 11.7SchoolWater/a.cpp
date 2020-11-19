/**
 * @Author: zjt
 * @Date:   07-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: b.cpp
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

bool ok(int a, int b,int c){

    if(a == 0 ){
        return b==c;
    } else {
        return (a+b>c) && (a+c>b) && (b+c>a);
    }

}
int main()
{
  //ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  int T;
  int aa[5];
  while(cin>>T){
      while(T--){
          fori(i,1,4) cin>>aa[i];
          // cout<<1<<endl;
          double ans  = -1;
          fori(up,1,3){
              fori(down,up+1,4){
                  int lup = aa[up];
                  int ldown =aa[down];
                  std::vector<int> v;
                  fori(i,1,4){if(i!=up && i!=down ) v.push_back(aa[i]);}

                  int mav = max(lup,ldown),miv = min(lup,ldown);
                  int del = mav - miv;
                  //cout<<del<<" "<<v[0]<<" "<<v[1]<<endl;
                  if(ok(del,v[0],v[1]) ) {
                    //cout<<del<<" "<<v[0]<<" "<<v[1]<<endl;
                    double res;
                    if(del == 0) {
                        res  = lup * v[0];
                    } else {
                        int a = v[0];
                        int b = v[1];
                        int c = del;
                        double p = (a+b+c)/2.0;
                        double s1 = sqrt(p*(p-a)*(p-b)*(p-c)) ;
                        double s2 = miv*2*s1/c;
                        res = s1+s2;
                    }
                    ans = max(ans, res);
                  }
              }
          }
          if(ans<-0.5) {
              cout<<"IMPOSSIBLE"<<endl;
              continue;
          } else {
              printf("%.2f\n", ans);
              //cout<<setw(3)<<setprecision(3)<<ans<<endl;
          }
          //double aaa = 2;
          //printf("----%.2f\n", aaa);

          // double p = (a+b+ot)/2.0;
          // cout<<"p "<<p<<endl;
          // double s1 = sqrt(p*(p-a)*(p-b)*(p-ot)) ;
          // double s2 = c*2*s1/ot;
          // cout<<s1<<" "<<s2<<endl;
          // cout<<setw(2)<<s1+s2<<endl;
      }
  }


return 0;
}
