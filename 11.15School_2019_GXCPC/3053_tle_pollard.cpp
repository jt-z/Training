/**
 * @Author: zjt
 * @Date:   15-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: 3053.cpp
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
#define fir first
#define sec second

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
//----------------------pollard--end------------------------------------------------------

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif

  int T;
  ll n;
  while(cin>>T){
    while(T--){
     cin>>n;
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
     cout<<ans<<" of "<<n<<endl;
    }
  }
  //cout<<(int)sqrt(900000000l*900000000l) <<endl;

return 0;
}
