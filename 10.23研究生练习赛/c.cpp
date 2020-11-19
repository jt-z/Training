/**
 * @Author: zjt
 * @Date:   23-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: c.cpp
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

int a[20];
bool sel[20];
int T,n,m,golds;
int selt[4];
bool dfs(int selcnt, int teamcnt){
    if(selcnt>n) return false ;
    if(teamcnt == 3){
        //cout<<" "<<a[selt[1]] <<" "<<a[selt[2]]<<" "<< a[selt[3]] <<endl;
        int ability = 3*a[selt[1]] + 2*a[selt[2]] + a[selt[3]];
        if(ability>=m){
            golds ++;
            sel[selt[1]] = 1;
            sel[selt[2]] = 1;
            sel[selt[3]] = 1;
            //fori(i,1,n) cout<<" "<<sel[i];
            //cout<<endl;
            return true;
        } else {
            sel[selt[1]] = 0;
            sel[selt[2]] = 0;
            sel[selt[3]] = 0;
            return false;
        }
    } else {
        if(teamcnt == 1){
            fori(i,1,n-2){
                if(sel[i] ) continue;
                selt[teamcnt] = i;
                sel[i] = 1;
                if( !dfs(selcnt+1, teamcnt+1) ) sel[i] =false;

            }
        } else if(teamcnt == 2){
            ford(i,n,selt[1]+2){ // selt[3] = i
                    if(sel[i] ) continue;
                    selt[3] = i;
                    sel[i] = true;
                    bool flag = 0;
                    ford(tt,i,selt[1]+1){
                        if(sel[tt] ) continue;
                        selt[2] = tt;
                        sel[tt] = true;
                        if(!dfs(selcnt+1, teamcnt+1)) {
                            sel[tt] = false;
                        } else {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag != 1){
                        sel[i] = false;

                    }else {
                        break;
                    }
            }
        }
    }
    return false;
}
int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  while(cin>>T){
    while(T--){
        cin>>n>>m;
        golds = 0;
        mem(sel,false);
        fori(i,1,n) cin>>a[i];
        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);
        dfs(1,1);
        cout<<golds<<endl;
    }
  }


return 0;
}
