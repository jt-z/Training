/**
 * @Author: zjt
 * @Date:   12-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: 3036.cpp
 * @Last modified by:   zjt
 * @Last modified time: 12-Oct-2020
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
 // freopen("local.in","r",stdin);
  int T;
  int sub_n;
  string s[51];
  while(cin>>T){
      while (T--) {
        cin>>sub_n;
        bool ac = false;
        int wa_cnt = 0;
        int rank = 0;
        if(!sub_n) {
            cout<<"-"<<endl;
            continue;
        }
        while(sub_n--){
            cin>>s[sub_n];
            if(s[sub_n]=="AC") {
                ac = true;
                rank = wa_cnt+1;
            }
            if(!ac) wa_cnt++;
        }
        if(!ac) cout<<"-"<<wa_cnt<<endl;
        else if(rank == 1) cout<<"+"<<endl;
        else cout<<"+"<<wa_cnt<<endl;

      }
  }

return 0;
}
