/**
 * @Author: zjt
 * @Date:   15-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: 3052.cpp
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
int T,n,m;
const int maxn = 2010;
PII car[maxn];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif

  while(cin>>T){
    while(T--){
        cin>>n>>m;
        fori(i,1,n) cin>>car[i].fir>>car[i].sec;
        fori(i,1,m){
            string op;
            cin>>op;
            if(op=="?"){
                int x;
                cin>>x;
                cout<<car[x].fir<<endl;
            } else {
                int x,k;
                cin>>x>>k;
                if(op=="L"){
                    car[x].fir -= k;
                    car[x].sec -= k;
                    int pos = x-1;

                    if(x>1){
                        while(pos>=1){
                            if(car[pos].sec > car[pos+1].fir){
                                int del = car[pos].sec - car[pos+1].fir;
                                car[pos].fir -= del;
                                car[pos].sec -= del;
                                pos--;
                            } else {
                                break;
                            }
                        }
                    }
                } else {
                    car[x].fir += k;
                    car[x].sec += k;
                    int pos = x+1;
                    if(x<n){
                        while(pos<=n){
                            if(car[pos].fir<car[pos-1].sec){
                                int del =  car[pos-1].sec - car[pos].fir;
                                car[pos].fir += del;
                                car[pos].sec += del;
                                pos++;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        }

    }

  }

return 0;
}
