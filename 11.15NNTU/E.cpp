/**
 * @Author: zjt
 * @Date:   15-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: B.cpp
 * @Last modified by:   zjt
 * @Last modified time: 15-Nov-2020
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef pair<int,int> PII;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(ll (i)=(ll)(l);(i)<=(ll)(u);++(i))
#define ford(i,l,u) for(ll (i)=(ll)(l);(i)>=(ll)(u);--(i))
#define fir first
#define sec second

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  string s;
  while(cin>>s){
      string sre= s;
      fori(i,0,(int)s.size()-1) sre[i] = s[(int)s.size()-1-i];
      //if(s!=sre) {cout<<"NO"<<endl; continue;}
      //else{
      string sch = sre;
      fori(i,0,(int)s.size()-1){
          if(sre[i] == 'b')  sch[i] = 'd';
          else if(sre[i] == 'd')  sch[i] = 'b';
          else if(sre[i] == 'p')  sch[i] = 'q';
          else if(sre[i] == 'q')  sch[i] = 'p';
      }
      if(s != sch){cout<<"NO"<<endl; continue;}
      else cout<<"YES"<<endl;
      //}

  }

return 0;
}
