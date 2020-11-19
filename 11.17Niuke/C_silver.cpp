/**
 * @Author: zjt
 * @Date:   18-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: C_silver.cpp
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

ll n;
const int mod =  1e9+7;
long long cowModCount(long long num) {
        // write code herek=n;
        long long ans=0,k=num,n=num,mod=1e9+7;
        //分块k/i  从1->n
        for(long long l=1,r;l<=n;l=r+1)
        {
            r=(k/l)?min(k/(k/l),n):n;//取min防止r超出边界
            long long x=k/l;
        //n*x- x*2*i
            ans=(ans+n*x%mod*(r-l+1)%mod)%mod;
            ans=(ans-x*x%mod*((l+r)*(r-l+1)/2%mod)%mod+mod)%mod;
            //  cout<<l<<" "<<r<<" "<<x<<" "<<ans<<endl;
        }
        return ans;
    }
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif
    while (cin>>n) {
        ll res = 0;

        ll phi = n;
        while(phi>=1){
            ll k = n/phi;
            //if(k == 1) {phi--;continue;}
            ll plo = n/(k+1) +1;
            ll cnt = phi - plo + 1;
            //cout<<"phi plo "<<phi<<" "<<plo<<" ";
            ll t = k*(cnt*n%mod  - ( k *( (plo + phi)*cnt/2 )%mod ) + mod )%mod;
            res = (res+ ( t ))%mod;
            //cout<<"n p res "<<n<<" "<<phi<<" "<<res<<endl;
            phi = plo -1;
        }
        if(res!=cowModCount(n)) cout<< res<<" "<<cowModCount(n)<<" n: "<<n<<endl;
    }

return 0;
}
