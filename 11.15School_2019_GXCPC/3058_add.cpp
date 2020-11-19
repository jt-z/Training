/**
 * @Author: zjt
 * @Date:   19-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: 3056.cpp
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
ll T,n,k;
const int mod = 1e9+7;
const int maxn =  305;

ll dp[maxn][maxn];
ll seg[maxn][maxn];
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif
    while(cin>>T){
        while(T--){
            cin>>n>>k;
            fori(i,1,n) {cin>>a[i]; a[i]%=k;}
            fori(tk,0,k-1) dp[1][tk] =  a[1]==tk? 1:0;
            fori(tk,0,k-1) dp[2][tk] = 0,dp[0][tk] = 1;  //初始化的值需要考虑到。
            ll tadd  =(a[1] +a[2] )%k, tmul =a[1]*a[2]%k;
            dp[2][tadd]++,dp[2][tmul]++;
            fori(i,1,n)
                fori(j,i,n){
                    if(j==i) {seg[i][j] = a[i]; continue;}
                    seg[i][j] = seg[i][j-1] * a[j] % k;// 模错数字了之前。。
                }
            fori(i,3,n){
                fori(tk,0,k-1){
                    dp[i][ (tk+a[i])%k ] = dp[i-1][tk] ;
                }
                // cout<<"pos1  i="<<i<<endl;
                // fori(j,0,k-1){
                //    cout<<dp[i][j]<<" ";
                // }
                // cout<<endl;
                fori(lli,1,i-1){ // [lli,i]
                    tmul = seg[lli][i];
                    //cout<<"lli   i-1   a[lli]  a[i]  seg "<<lli<<" "<<i-1<<" "<<a[lli]<<" "<<a[i]<<" "<<seg[lli][i-1]<<endl;
                    if(lli==1){
                        int tt =tmul;
                        dp[i][tt] = (1 + dp[i][tt])%mod; //特殊情况特殊处理，省得实现麻烦。
                        // cout<<"pos2 i="<<i<<endl;
                        // fori(j,0,k-1){
                        //    cout<<dp[i][j]<<" ";
                        // }
                        // cout<<endl;

                        continue;
                    }
                    fori(tk,0,k-1){
                        int tt =(tk+tmul)%k;
                        dp[i][tt] = (dp[lli-1][tk] + dp[i][tt])%mod;
                        // cout<<"pos3 i="<<i<<endl;
                        // fori(j,0,k-1){
                        //    cout<<dp[i][j]<<" ";
                        // }
                        // cout<<endl;
                    }
                }

            }

            // cout<<endl;
            // fori(i,1,n){
            //     fori(j,0,k-1){
            //        cout<<setw(10)<<dp[i][j]<<" ";
            //     }
            //        cout<<endl;
            // }
            cout<<dp[n][0]<<endl;
        }
    }

return 0;
}

/*
1
3 2
2 1 2

1
4 2
2 1 2 1

1
2 2
2 1

1
8 3
3 3 3 3 3 3 3 3

1
2 7
2 3

1
5 6
2 1 3 2 3

1
3 3
3 4 5

1
13 4
2 3 4 2 5 5 2 3 2 5 8 9 8

1
9 4
2 3 4 2 5 5 2 3 2

1
3 7
4 6 3

1
3 7
4 3 7


1
52 4
2 3 4 2 5 5 2 3 2 5 8 9 8 2 3 4 2 5 5 2 3 2 5 8 9 8 2 3 4 2 5 5 2 3 2 5 8 9 8 2 3 4 2 5 5 2 3 2 5 8 9 8

1
7 4
1 1 1 1 1 1 1

*/
