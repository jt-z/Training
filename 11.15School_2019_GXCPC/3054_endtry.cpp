/**
 * @Author: zjt
 * @Date:   19-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: 3054_endtry.cpp
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
const int maxn = 1e5+10;
struct node{
    int  ai,bi,wi;
} a[3*maxn];
bool cmp(const node&a,const node & b){
    return a.wi<b.wi;
    // if(a.kind == 1) {
    //     if(b.kind ==1){
    //         return a.ci<b.ci;
    //     } else {
    //         return a.ci<=b.wi;
    //     }
    // }else {
    //     if(b.kind == 1){
    //         return a.wi<b.ci;
    //     } else {
    //         return a.wi<b.wi;
    //     }
    // }
}


int T,n,m;
bool vis[maxn];
//-----------ufds--start
ll p[maxn];
ll ofind(ll x){
   return p[x]==-1 ? x:p[x]=ofind(p[x]);
}
void merge(ll u,ll v){
 ll pu,pv;
 pu=ofind(u);
 pv=ofind(v);
 if(pu!=pv) p[pu]=pv;
}
//-----------ufds--end
ll pcnt[maxn];
ll pcost[maxn];
void pnode(node & t){
    cout<<"kind   ";
    // cout<<t.kind<<"  i "<<t.i<<" ci "<<t.ci<<" ai "<<t.ai<<" bi "<<t.bi<<" wi "<<t.wi<<endl;

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
            int cnt = 0;
            fori(i,1,n) {
                 cnt++;
                cin>>a[cnt].wi;
                a[cnt].ai =0;
                a[cnt].bi = i;

            }
            fori(i,1,m){

                 cnt++;
                cin>>a[cnt].ai>>a[cnt].bi>>a[cnt].wi;


            }
            sort(a+1,a+1+cnt,cmp);
            mem(p,-1);


            ll cost = 0;
            fori(i,1,cnt){
                node &t = a[i];
                //node(t);
                // if(t.kind == 1){
                //     int pt = ofind(t.i);
                //     if(vis[pt]) continue;
                //     else{
                //         vis[pt] = true;
                //         gscnt+=pcnt[pt];
                //         cost +=pcost[pt]+t.ci;
                //          //cout<<"cost : "<<cost<<endl;
                //          //cout<<"i is "<<t.i<<"   pt : "<<pt<<endl;
                //         // cout<<"p: ";
                //         // fori(ti,1,n) cout<<p[ti]<<" ";
                //         // cout<<endl<<endl;
                //         if(gscnt == n ) break;
                //     }
                // } else {
                ll pa  = ofind(t.ai),pb = ofind(t.bi);
                if(pa != pb ){
                    //cout<<"pa "<<pa<<" "<<pb<<endl;
                    // if(!vis[pa]  && !vis[pb]) {
                    //     pcnt[pb] += pcnt[pa];
                    //     pcost[pb] += pcost[pa]+t.wi;
                    //     p[pa] = pb;
                    // } else if(vis[pa]&&!vis[pb]){
                    //     gscnt += pcnt[pb];
                    //     cost += pcost[pb] + t.wi;
                    //     if(gscnt==n) break;
                    // } else if(!vis[pb]&&!)

                    cost+=t.wi;
                    p[pa] = pb;
                }

                // }
            }
            cout<<cost<<endl;
            //cout<<"$$$$$$"<<endl;

        }
    }

return 0;
}
/*
1
2 1
5 7
1 2 4

1
6 3
5 5 5 5 5 5
2 3 1
4 5 2
5 6 3

1
1 0
1

1
3 0
3 2 1


1
5 6
9 9 9 9 9
1 2 2
1 3 1
2 4 3
3 4 2
3 5 5
4 5 7

1
9 16
22 22 22 22 22 22 22 22 22
1 2 8
1 3 12
2 3 13
2 5 9
2 4 25
3 4 14
3 7 21
4 5 20
4 6 8
4 7 12
4 8 12
4 9 16
5 6 19
6 8 11
7 9 11
8 9 9



1
9 16
1 1 1 1 1 1 8 8 8
1 2 8
1 3 12
2 3 13
2 5 9
2 4 25
3 4 14
3 7 21
4 5 20
4 6 8
4 7 12
4 8 12
4 9 16
5 6 19
6 8 11
7 9 11
8 9 9

*/
