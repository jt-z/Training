/**
 * @Author: zjt
 * @Date:   23-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: a.cpp
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

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  int a[1000];
  int cnt = 0 ;
  fori(i,1,9){
    fori(j,1,4){
        int temp = i;
        fori(k,2,j) temp =  temp*10 + i;
        a[++cnt] = temp ;
        //cout<<temp<<endl;
    }
  }
  int t;
  while(cin>>t){
    while(t--){
        int n;
        cin>>n;
        int cnt = 0;
        fori(i,1,36){
            int digit;
            if(a[i]<10) digit=1;
            else if(a[i]<100) digit =2;
            else if(a[i]<1000) digit =3;
            else digit=4;

            cnt += digit;
            if(n==a[i]){

                cout<<cnt<<endl;
                break;;
            }  
        }
    }
  }

return 0;
}
