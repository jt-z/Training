/**
 * @Author: zjt
 * @Date:   15-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: C.cpp
 * @Last modified by:   zjt
 * @Last modified time: 16-Nov-2020
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


string s;
const int maxn = 2e5+10;
int dp[maxn];
int f(int l,int r){ // 1 2 1 1 2  2 1 1 2
    if(l == r) return 0;
    else if(l == r-1) {
        if(s[l] == s[r]) return 0;
        else return 1;
    } else if(r ==  r-2){
        return 1;
    } else { //len >3
        dp[l] = 0;
        if(s[l+1]!=s[l]) dp[l+1] = 1;
        dp [l+2] = 1;
        fori(i,l+3,r){
            dp[i] = dp[i-1];
            if(s[i-1]!=s[i]) dp[i] = max(dp[i], dp[i-2]+1);
            else {
                if(s[i-2]==s[i]) dp[i] = max(dp[i],dp[i-3]+1);
            }
        }
        return dp[r];
    }


}
const int SIZE = 2E5 + 7, Mod = (1E9 + 7, 998244353);
int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  while(cin>>s){
      int len = s.size();
      mem(dp,0);
      fori(i,0,len-1) s[i] = '0' + ((s[i] - '0')%3);
      //cout<<s<<endl;
      int p = 0;
      int ans = 0;
      while(p<len){
        if(s[p]=='0') {ans ++;p++;}
        else {
            int np = p+1;
            while(np<len && s[np]!='0') np++;
            // [p,np]
            ans += f(p,np-1);
            //cout<<"p np"<<p<<" "<<np-1<<endl;
            // char pre = s[p];
            // int cnt = 1;
            // bool is_new = true;
            // for(int i=p+1;i<=np;){
            //     char cur = s[i];
            //     if(pre!=cur) {
            //         ans++;
            //         is_new = true;
            //     }
            // }

            p = np;
        }
      }

       cout<<ans<<endl;

  }

return 0;
}
