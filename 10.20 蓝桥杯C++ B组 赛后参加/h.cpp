/**
 * @Author: zjt
 * @Date:   19-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: h.cpp
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
  char s[100010];
  int sf[100010];
  mem(sf,0);

  cin.getline(s+1,100001);

  int n = strlen(s+1);
  sf[1] = 1;
  fori(i,2,n){
    int ppos = -1;
    ford(j,i-1,1){
        if(s[j] == s[i]) {// 最坏情况会TLE。
            ppos = j;
            break;
        }
    }

    int sigma = 0;

    if(ppos == -1) {
        sigma = i;
    } else {
        sigma = i-ppos;
    }
    sf[i] = sf[i-1] + sigma;
  }
  int sum = 0;
  fori(i,1,n) sum+=sf[i];
  cout<<sum<<endl;

return 0;
}
