/**
 * @Author: zjt
 * @Date:   19-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: g.cpp
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

bool is_rui(int y){
    if(y%4==0) {
        if(y%100!=0) return true;
        else{
            if(y%400==0) return true;
            else return false;
        }
    } else
    return false;

}

bool valid(int y,int m,int d){
    int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_rui(y) ){
        day[2] = 29;
    }
    return d<=day[m];

}
int main()
{
  ios::sync_with_stdio(false);
  freopen("local.in","r",stdin);
  int N;
  cin>>N;
  //N = 20200202;
  int pal,abpal;

  int year = N/10000;
  fori(i,year+1,8999){
      int month = 0,day = 0;
      int dl1,dl2,dl3,dl4,ti=i;
      dl1 = ti%10;
      ti /= 10;
      dl2 = ti%10;
      ti /= 10;
      dl3 = ti%10;
      ti/=10;
      dl4 = ti%10;
      month = dl1*10 + dl2;
      day = dl3*10 + dl4;
      if( valid(i,month,day) ) {
          pal = i*10000+ month *100 + day;
          break;
      }
  }
  fori(i,year+1,8999){
      int month = 0,day = 0;
      int dl1,dl2,dl3,dl4,ti=i;
      dl1 = ti%10;
      ti /= 10;
      dl2 = ti%10;
      ti /= 10;
      dl3 = ti%10;
      ti/=10;
      dl4 = ti%10;
      month = dl1*10 + dl2;
      day = dl3*10 + dl4;
      if( valid(i,month,day) && month==day && dl1!=dl2) {
          abpal = i*10000+ month *100 + day;
          break;
      }
  }



  cout<<pal<<endl<<abpal<<endl;
  //cout<<sizeof(pal)<<endl;

return 0;
}
