/**
 * @Author: zjt
 * @Date:   19-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: f.cpp
 * @Last modified by:   zjt
 * @Last modified time: 19-Oct-2020
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long  ll;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(ll (i)=(ll)(l);(i)<=(ll)(u);++(i))
#define ford(i,l,u) for(ll (i)=(ll)(l);(i)>=(ll)(u);--(i))

int main()
{
  ios::sync_with_stdio(false);
  freopen("local.in","r",stdin);
  int n;
  int a[10010];
  cin>>n;
  fori(i,1,n) cin>>a[i];
  int c65=0,c85=0;
  fori(i,1,n){
      if(a[i]>=65) c65++;
      if(a[i]>=85) c85++;
  }
  double r65,r85;
  r65 = ((double)c65) / ((double)(n));
  r85 = (double)c85 / ((double)(n));
  int p65 = (r65+0.005)*100;
  int p85 = (r85+0.005)*100;
  cout<<p65<<"%"<<endl;
  cout<<p85<<"%"<<endl;

return 0;
}
