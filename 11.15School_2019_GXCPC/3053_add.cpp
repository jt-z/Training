/**
 * @Author: zjt
 * @Date:   17-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: 3053_add.cpp
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

//---ch

//-----------------pollard 分解--------start
// 接口说明： 调用findfac函数得到数的所有素因子，无序的排列在factor中，从factor[0]开始，一共tol个。
// 注意，必须保证带分解的数大于数字1,因为1不能写成任何素数的大于零次幂。
const ll S=20;//随机算法判定次数，S越大，判错概率越小
//计算 (a*b)%c.   a,b都是long long的数，直接相乘可能溢出的
//  a,b,c <2^63
long long mult_mod(long long a,long long b,long long c)
{
   a%=c;
   b%=c;
   long long ret=0;
   while(b)
   {
       if(b&1){ret+=a;ret%=c;}
       a<<=1;//别手残，这里是a<<=1,不是快速幂的a=a*a;
       if(a>=c)a%=c;
       b>>=1;
   }
   return ret;
}

//计算  x^n %c
long long pow_mod(long long x,long long n,long long mod)//x^n%c
{
   if(n==1)return x%mod;
   x%=mod;
   long long tmp=x;
   long long ret=1;
   while(n)
   {
       if(n&1) ret=mult_mod(ret,tmp,mod);
       tmp=mult_mod(tmp,tmp,mod);
       n>>=1;
   }
   return ret;
}

//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(long long a,long long n,long long x,long long t)
{
   long long ret=pow_mod(a,x,n);
   long long last=ret;
   for(ll i=1;i<=t;i++)
   {
       ret=mult_mod(ret,ret,n);
       if(ret==1&&last!=1&&last!=n-1) return true;//合数
       last=ret;
   }
   if(ret!=1) return true;
   return false;
}

// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;

bool Miller_Rabin(long long n)
{
   if(n<2)return false;
   if(n==2)return true;
   if((n&1)==0) return false;//偶数
   long long x=n-1;
   long long t=0;
   while((x&1)==0){x>>=1;t++;}
   for(ll i=0;i<S;i++)
   {
       long long a=rand()%(n-1)+1;//rand()需要stdlib.h头文件
       if(check(a,n,x,t))
           return false;//合数
   }
   return true;
}


//************************************************
//pollard_rho 算法进行质因数分解
//************************************************
long long factor[100];//质因数分解结果（刚返回时是无序的）
ll tol;//质因数的个数。数组小标从0开始

long long gcd(long long a,long long b)
{
   if(a==0)return 1;//???????
   if(a<0) return gcd(-a,b);
   while(b)
   {
       long long t=a%b;
       a=b;
       b=t;
   }
   return a;
}

long long Pollard_rho(long long x,long long c)
{
   long long i=1,k=2;
   long long x0=rand()%x;
   long long y=x0;
   while(1)
   {
       i++;
       x0=(mult_mod(x0,x0,x)+c)%x;
       long long d=gcd(y-x0,x);
       if(d!=1&&d!=x) return d;
       if(y==x0) return x;
       if(i==k){y=x0;k+=k;}
   }
}
//对n进行素因子分解
void findfac(long long n)
{
   if(Miller_Rabin(n))//素数
   {
       factor[tol++]=n;
       return;
   }
   long long p=n;
   while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
   findfac(p);
   findfac(n/p);
}
//----------------------pollard--end------------------------------------------
ll che(ll n){
    tol = 0;
    findfac(n);
    int cnt = 0;
    //cout<<"factors of "<<n<<" is :";//<<endl;
    //fori(i,0,tol-1) cout<<factor[i]<<" ";
    //cout<<endl;
    map<int,int> fp;

    fori(i,0,tol-1){

        fp[factor[i]]++;
       //while(n%factor[i] == 0) {cnt++; n/=factor[i];}
       //ans = gcd (ans , cnt);
    }
    int ans = fp[factor[0]];
    foreach(e,fp){
       // cout<<"e->fir "<<e->fir<<endl;
        //cout<<"e->sec "<<e->sec<<endl;
        ans = gcd(ans, e->sec);
    }
    return ans;
    //cout<<ans<<" of "<<n<<endl;

}

//--ch

ll T;
ll n;
ll mypow1(ll a,ll k){
    ll ret = 1;
    while(k--) ret*=a;
    return  ret;
}
ll mypow(ll a,ll b)
{
	if(b==0)
	{
		return 1;
	}
	if(b&1)
	{
		return a*mypow(a,b-1);
	}
	else
	{
		ll t=mypow(a,b/2);
		return t*t;
	}
}

ll f(ll n,ll k){
    ll l = 1, r = n, mid,t;
    while(l<=r){
        mid = (r+l)>>1;
        cout<< "l r "<<l<<" "<<r<<endl;
         t = mypow(mid,k);
        if(t > n){
            r = mid -1;
        } else if(t == n){
            r = mid;
            break;
        } else {
            l = mid+1;
        }
    }
    return r;
}

ll f2(ll n){
    int ans=70;
    while(1)
    {
        if(ans==1)	break;
        ll temp=1ll*pow(1.0*n,1.0/ans);
        bool flag=true;
        if(mypow(temp+1,ll(ans))!=n&&mypow(temp,ll(ans))!=n)	flag=false;
        if(!flag)	ans--;
        else	break;
    }
    // cout<<ans<<endl;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif
    //cout<<f(810000000000000000,2)<<endl;
    //cout<<pow(810000000000000000,0.5)<<endl;
    // return 0;
    while(cin>>T){
        //T = 8100001;
        while(T--){
            cin>>n;
            //ll t = rand();
            //n = ((double)t)/(2ll<<31-1) * (2ll<<59-1);
            //cout<<"n "<<n<<endl;
            //*(ll)rand();
            //n = t;
            //cout<<" n is "<<n<<endl;
            bool flag = false;
            ll ans = -1;
            ford(i,60,1){

                ll rin = pow(n,1.0/i);
                //if(i==1) {cout<<1<<endl; break;}
                fori(ti,0,1) {
                    if(mypow(rin+ti,i) == n) {
                        ans = i;
                        //cout<<i<<endl;//<<" of n"<<n<<endl;
                        //if(che(n) != i) cout<<"not ok of n "<<n<< endl;
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
                // ll rl = rin-1, rr =  rin + 1;
                // if( mypow(rl,i)  == n ||  mypow(rin,i)  == n ||  mypow(rr,i)  == n ){
                //
                //     cout<<i<<endl;
                //     break;
                // }
            }
            cout<<ans<<endl;
        }
    }

return 0;
}

// 123412341234123412 应该输出1.
/*
1
36
1
576460752303423488

7
4
8
81
36
64
128
27

9
555
12765
66
688
8990
1200
3444
5555
777899


1
810000000000000000

19

2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
36


3
4
6
36

9
2
4
6
8
12
11
13
14
16

2
810000000000000000
1620000000000000000

4
123213412341234123
312342314321341234
34123412341234123
123412341234123412

91
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007
1000007

6
120341
123412341234123412
1234123
23433333
22222222
431223433

*/
