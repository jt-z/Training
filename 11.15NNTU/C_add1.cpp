/**
 * @Author: zjt
 * @Date:   16-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: C_add1.cpp
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
#define lowbit(x) ((x)&(-(x)))
#define fir first
#define sec second

int T,m;
ll N;
int id;
const int SIZE = 1e5+7;
ll vec[SIZE << 6];
ll bit[SIZE << 6];

struct seq{
    int op;
    ll l,r;
}a[SIZE];
int f(ll x){
    int l=1,r=id;
    int m;
    while(l<=r){
        m = (l+r)>>1;
        vec[m]>x ? r = m-1 : l = m+1;
    }
    return r;
}
void pushd(ll x,ll v){
    ll d = v;
    while(x<N){
        bit[f(x)]+=d;
        x+=lowbit(x);
        d+=v;
    }
}
void push(ll x,int op){
    if(op){
        while(x<N) {vec[++id] = x; x+=lowbit(x);}
    } else {
        while(x) {vec[++id] = x; x-=lowbit(x);}
    }
}
ll sum(ll x){
    ll ret =0;
    while(x){
        ret += bit[f(x)];
        x -= lowbit(x);
        //cout<< "x  f(x)"<<x<<"  "<<f(x)<<endl;
        //cout<<"ret in "<<ret<<endl;
    }
    //cout<<"ret"<<ret<<endl;
    return ret;
}
int main()
{
    //ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif
    //cout<<lowbit(2)<<endl;
    //cout<<lowbit(3)<<endl;
    while(scanf("%lld",&N)!=EOF ){
            scanf("%d",&m);
            //cout<<N<<" "<<m<<endl;
            fori(i,1,m<<6) bit[i] = 0;
            id = 0;
            fori(i,1,m){
                scanf("%d%lld%lld",&a[i].op,&a[i].l,&a[i].r);
                //cout<<a[i].op<<" "<<a[i].l<<" "<<a[i].r<<endl;
                if(a[i].op == 1) push(a[i].l,1);
                else push(a[i].l-1,0),push(a[i].r,0);
            }
            sort(vec+1,vec+id+1);
            unique(vec+1,vec+id+1);
            fori(i,1,m){
                if(a[i].op == 1){
                    pushd(a[i].l,a[i].r);
                } else {
                    ll t = sum(a[i].r) -sum(a[i].l-1);
                    printf("%lld\n",t);
                }
            }
            //fori(i,1,SIZE) if(bit[i] ) cout<<"i: "<<i<<" vec(i)"<<vec[i]<<"   "<<bit[i]<<" "<<endl;
    }

    return 0;
}
