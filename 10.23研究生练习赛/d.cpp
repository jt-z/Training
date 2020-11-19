/**
 * @Author: zjt
 * @Date:   23-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: d.cpp
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

int n;
string s[101];
int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  int T;
  while(cin>>T){
      while(T--){
        cin>>n;
        fori(i,1,n){
            cin>>s[i];
        }
        int ok = 0;
        fori(firch,0,25){
            string t = " ";
            t[0] = 'a'+firch;
            string temp = ""+t;
            //cout<< "temp: "<<temp<<endl;
            bool is_sustr =false;
            fori(i,1,n) if(s[i].find(temp) != -1 ) {is_sustr = true; break;}
            if(is_sustr){
                continue;
            } else {
                cout<<temp<<endl;
                ok = 1;
                break;
            }
            if(is_sustr == false) break;
        }
        if(ok == 1) continue;
        fori(firch,0,25){
            string t = " ";
            t[0] = 'a'+firch;
            string temp = ""+t;
            //cout<< "temp: "<<temp<<endl;
            bool is_sustr =false;
            fori(secch,0,25){
                t[0] = 'a'+secch;
                string pretemp = temp;
                temp = temp+t;
                //cout<<"temp2: "<<temp<<endl;
                is_sustr =false;
                fori(i,1,n) if(s[i].find(temp) != -1 ) {is_sustr = true; break;}
                if(is_sustr == false) {
                    cout<<temp<<endl;
                    ok = 1;
                    break;
                }
                temp =  pretemp;
            }

            if(is_sustr == false) break;
        }



      }
  }

return 0;
}
