/**
 * @Author: zjt
 * @Date:   19-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: d.cpp
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

bool is_rui(int x){
    bool ret = false;
    if(x%4==0){
        if(x%100!=0) ret =true;
        else if(x%100==0){
            if(x%400 == 0) ret =true;
        }
    }
    return ret;
}
struct date{
    int year,month,day;
};
int main()
{
  ios::sync_with_stdio(false);
  freopen("local.in","r",stdin);
  int cnt =0;
  date start = {2000,1,1};
  date end = {2020,10,1};
  date cur = start;
  int weekday = 6;

  int rui =0;
  fori(i,2000,2020) if(is_rui(i)) { rui++; cout<<i<<endl;}
  cout<<rui<<endl;
  while(1){
      if(cur.year == 2020 && cur.month==10 && cur.day ==2) break;
      int cy = cur.year,cm = cur.month, cd = cur.day;
      if(cd == 1 || weekday==1) cnt +=2;
      else cnt+=1;
      //weekday = ( (weekday+1)%7)+1;   ÕâÊÇ´íµÄ¡£¡£¡£
      //cout<<weekday<<" "<<endl;
      weekday +=1;
      if(weekday>7) weekday = 1;
      cd = cd + 1;
      if(cd ==29){
          if(cm == 2 && (!is_rui(cy)) ) {
              cd = 1;
              cm += 1;
          }
      } else if(cd==30){
          if(cm == 2 ) {
              cd = 1;
              cm += 1;
          }
      }else if(cd==31){
          if( !(cm==1|| cm==3 || cm==5 || cm==7 || cm==8 || cm==10 ||cm==12) ) {
              cd = 1 ;
              cm += 1;
          }
      } else if(cd >31) {
          if(cm == 12){
              cy += 1;
              cm = 1;
              cd = 1;
          } else {
              cm +=1;
              cd = 1;
          }
      }
      cur = {cy,cm,cd};
      //cout<<"y,m,d"<<cy<<" "<<cm<<" "<<cd<<endl;
  }
  cout<<cnt<<endl;
  //int days = 6+20*365+1+31+29+31+30+31+30+31+31+30;

return 0;
}
