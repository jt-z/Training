/**
 * @Author: zjt
 * @Date:   17-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: B.cpp
 * @Last modified by:   zjt
 * @Last modified time: 18-Nov-2020
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef pair<int,int> PII;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(ll (i)=(ll)(l);(i)<=(ll)(u);++(i))
#define ford(i,l,u) for(ll (i)=(ll)(l);(i)>=(ll)(u);--(i))
#define lowbit(x) (x)&(-(x))
#define fir first
#define sec second
int d;
int getd(int n){
    int cnt = 0;
    while(n){
        cnt++;
        n = n >> 1;
    }
    return cnt;
}
const ll mod = 998244353;
ll inv(ll a,ll mod){
    return 499122177;
}
ll pw2[161];

ll f(ll n){

       ll ans=0;
       long long tp=1,dep=1;
       while(tp<=n){
       long long r=min(2*tp-1,n);
       ans=(ans+dep*((tp+r)*(r-tp+1)/2%mod)%mod)%mod;
       tp=r+1;
       dep++;
     //  cout<<tp<<"  "<<r<<" "<<ans<<endl;
        }

        return ans;
    }




int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif
    //cout<<inv(2,mod)<<endl;
    pw2[0] = 1;
    pw2[1]= 2;
    for(int i=2;i<=122;i++) pw2[i] =2 *pw2[i-1]%mod;
    int n;
    while(1){
        n ++;
        d = getd(n);
        ll ans = 0;
        fori(i,1,d-1){
            ll t;
            if(i==1) t = 1;
            else if(i==2) t=10;
            else {
                t = i;
                //t = t * pw2[i-2] %mod;
                //t = t* ( (3ll*pw2[i-1]%mod) - 1ll + mod)%mod;
                ll tt = pw2[2*i-3];
                tt = (tt+ pw2[2*i-2] )%mod;
                tt = (tt - pw2[i-2] + mod) %mod;
                t = t*tt%mod;
            }
            ans = (ans+ t)%mod;
        }
        ll les = d;
        les = les*( (pw2[d-1] +n) %mod)%mod;
        les = les *(n- pw2[d-1] +1) %mod;
        les = les * 499122177 %mod;
        ans = (ans + les)%mod;
        cout<<ans<<endl;
        //if(ans!=f(n) ) {cout<<ans<<" "<<f(n)<<"  n "<<n<<endl;break;}
    }
return 0;
}
