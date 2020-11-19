/**
 * @Author: zjt
 * @Date:   19-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: 3056_add.cpp
 * @Last modified by:   zjt
 * @Last modified time: 19-Nov-2020
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
ll T,n;
const int maxn = 1e5 +10;
ll a[maxn];
const int mod = 1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif
    while(cin>>T){
        while(T--){
            cin>>n;
            fori(i,1,n) cin>>a[i];
            sort(a+1,a+1+n);

            ll ans = 1;
            fori(i,1,n){
                ll t = (a[i] - i +1);
                ans = ans *t %mod;
            }

            cout<<ans<<endl;
        }
    }

return 0;
}
