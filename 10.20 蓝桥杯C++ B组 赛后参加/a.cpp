/**
 * @Author: zjt
 * @Date:   19-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: a.cpp
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
  int n = 2020;
  int cnt = 0;
  while(n){
      int t =  n;
      while(t){
          if(t%10 == 2) cnt ++;
          t = t/10;
      }
    n--;
  }
  cout<<cnt<<endl;

return 0;
}
