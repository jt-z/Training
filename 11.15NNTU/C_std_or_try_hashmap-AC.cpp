/**
 * @Author: zjt
 * @Date:   16-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: C_std_or_try_hashmap.cpp
 * @Last modified by:   zjt
 * @Last modified time: 16-Nov-2020
 */
 #include<iostream>
 #include<algorithm>
 #include<cstring>
 #include <bits/stdc++.h>
 #define rep(i,a,b) for(int i=a;i<b;i++)
 #define mem(a,b) memset(a,b,sizeof a)
 using ll=long long;
 template<class ty>void read(ty&a){
 	a=0;int f=0,c=getchar();
 	for(;~c&&!isdigit(c);c=getchar()) f|=c=='-';
 	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
 	if(f) a=-a;
 }
 template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
 //----------------------------------
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
 using namespace std;
 hash_map Su;
 ll n,m;
 void add(ll p,ll x){
 	ll cnt=1;
 	while(p<=n)
 		Su[p]+=(cnt++)*x,p+=p&-p;
 }
 ll sum(ll x){
 	ll ret=0;
 	while(x)
 		ret+=Su[x],x-=x&-x;
 	return ret;
 }
 int main(){
     #ifdef LOCAL
     freopen("local.in","r",stdin);
     #endif

 	read(n,m);
 	while(m--){
 		int c;
 		ll l,r;
 		read(c,l,r);
 		if(c==1) add(l,r);
 		else printf("%lld\n",sum(r)-sum(l-1));
 	}
 }
