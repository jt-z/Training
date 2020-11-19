/**
 * @Author: zjt
 * @Date:   19-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: c.cpp
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
int a[51][51];
int main()
{
  ios::sync_with_stdio(false);
  freopen("local.in","r",stdin);
  int px,py,dx,dy;
  px = 1;
  py = 1;
  dx = -1;
  dy = 1;
  int cnt =1;
  while(px<42){
      a[px][py] = cnt++;
      int tx =  px + dx;
      int ty =  py + dy;
      if(tx<1){
          dx = 1;
          dy = -1;
          px = 1;
          py = py + 1;
      } else if(ty<1){
          dx = -1;
          dy = 1;
          px = px+1;
          py = 1;
      } else{
          px = tx;
          py = ty;
      }
  }
fori(i,1,42){
    fori(j,1,42){
        cout<<setw(3)<<a[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl<<endl<<a[20][20]<<endl;
return 0;
}
