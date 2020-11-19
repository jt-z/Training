/**
 * @Author: zjt
 * @Date:   19-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: 3037_add.cpp
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

const int maxn = 1e5 +10;

int T;
ll n,dx,dy,dz;
struct node{
    int x,y,z;
    node(){x=0,y=0,z=0;}
    node(int a,int b,int c){x=a,y=b,z=c;}
} ;
node rec[maxn];
map<pair<ll,int> ,int > mp,idx;
inline ll mabs(ll x){
    return x>0? x:-x;
}
int d[3] ={-1,0,1};
int cnt = 0;

namespace IO {
   inline int read() {
       ll  o = 0, f = 1; char c = getchar();
       while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
       while (c > '/' && c < ':') { o = o * 10 + c - '0'; c = getchar(); }
       return o * f;
   }
   inline char recd() {
       char o; while ((o = getchar()) < '0' || o > '9'); return o;
   }
   inline double reod() {
       double o = read(), f = 1; char c;
       while ((c = getchar()) > '/' && c < ':') o += (c - '0') / (f *= 10);
       return o;
   }
}
using namespace IO;


const ll SZ=2e6+9; // 1e7+7 ok too. 取的这个数如果散列冲突太多次就会导致tle。
struct hash_map {
  struct data {
    long long u,v; //key val
   int nex;
};
  data e[SZ << 1];
  int h[SZ], cnt;
  ll& operator[](long long u) {
    int hu = u % SZ;
    for (int i = h[hu]; i; i = e[i].nex)
      if (e[i].u == u) return e[i].v;
    e[++cnt] = {u, 0, h[hu]}, h[hu] = cnt;
    return e[cnt].v;
  }
   hash_map() {
    cnt = 0;
    memset(h, 0, sizeof(h));
  }
};
hash_map Su;



int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif
    while(scanf("%d",&T)!=EOF){
        while(T--){
            n=read(),dx=read(),dy=read(),dz=read();
            //cin>>n>>dx>>dy>>dz;
            ll x,y,z;

            cnt = 0;
            string ans ="NO";
            mp.clear(),idx.clear();

            fori(i,1,n) {
                x=read(),y=read(),z=read();
                //cin>>x>>y>>z;
                //node t = node(x/dx,y/dy,z/dz);
                ll tt = x/dx*1000000000l+y/dy;
                //cout<<"SSSS  "<<tt<<" "<<z/dz<<endl;
                pair<ll,int> pt =make_pair(tt,z/dz);
                mp[pt]++;
                if(mp[pt]>1) {ans="YES"; }//cout<<endl<<"$$$$$$"<<endl;}
                //cout<<"ans  "<<ans<<endl;
                idx[pt] = ++cnt;
                rec[cnt] = node(x,y,z);
            }
            if(ans == "YES") {puts("YES"); continue;}

                ll xx,yy,zz,xxx,yyy,zzz;
            foreach(e,mp){
                pair<ll,int>  pe =e->fir;
                ll tt = pe.fir;
                y = tt%1000000000l;
                x = tt/1000000000l;
                z = pe.sec;
                int tid = idx[e->fir];
                //cout<<"before x y z "<<x<<" "<<y<<" "<<z<<endl;
                //cout<<"after  x y z "<<rec[tid].x<<"   "<<rec[tid].y<<"   "<<rec[tid].z<<endl;
                int id;
                fori(i,0,2)
                    fori(j,0,2)
                    fori(k,0,2){
                        if(i==j&& j==k && k==1)  continue;
                        //node nt = node(t.x+d[i],t.y+d[j],t.z+d[k]);
                        xx = x+d[i],yy = y+d[j],zz = z+d[k];
                        tt= xx*1000000000l+yy;
                        if(xx<0||yy<0||zz<0) continue;
                        id = idx[make_pair(tt,zz)];
                        if(!id) continue;
                        node adj = rec[id];
                        xxx= adj.x,yyy=adj.y,zzz=adj.z;
                        x= rec[tid].x,y=rec[tid].y,z=rec[tid].z;
                        //cout<<"i j k "<<i<<" "<<j<<" "<<k<<endl;
                        //cout<<"xxx yyy zzz "<<xxx<<" "<<yyy<<" "<<zzz<<endl;
                        if( mabs(x-xxx)<=dx &&  mabs(y-yyy)<=dy &&   mabs(z-zzz)<=dz ) { ans="YES"; break;}
                    }
            }
            if(ans[0]=='Y')puts("YES");
            else puts("NO");
            //cout<<ans<<endl;
        }
    }
return 0;
}
