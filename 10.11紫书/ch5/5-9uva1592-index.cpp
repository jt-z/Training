/**
 * @Author: jt
 * @Date:   22-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: 5-9uva1592.cpp
 * @Last modified by:   jt
 * @Last modified time: 22-Oct-2020
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long  LL;
typedef pair<int,int> PII;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define ford(i,l,u) for(LL (i)=(LL)(l);(i)>=(LL)(u);--(i))

const int maxn = 100010;
const int maxm = 12;
int s[maxn][maxm];
int cnt;
map<string,int> ind;
int id(string s){
    if(ind.count(s) == 0){
        ind[s] = ++cnt;
    }
    return ind[s];
}
map< PII,int> mm;
int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL
  freopen("local.in","r",stdin);
  #endif
  int n,m;
  string line1;
  while(getline(cin, line1)) {
    cnt  = 0;
    ind.clear();
    stringstream ss1(line1);
    if(!(ss1 >> n >> m)) break;
    fori(i,1,n){
        string line;
        getline(cin,line);
        stringstream ss(line);
        string ceLL;
        int j = 1;
        while(getline(ss,ceLL,',')){
            s[i][j++] = id(ceLL);;

        }
    }
    mm.clear();
    string ans = "YES";
    int r1,r2,c1,c2;
    fori(col1,1,m-1){
        fori(col2,col1+1,m){
            mm.clear();
            fori(row,1,n){
                int s1=s[row][col1],s2=s[row][col2];

                //string pss = s1+","+s2;
                PII temp = make_pair(s1,s2);
                if(mm.count(temp)>0) {
                   ans = "NO";
                   r1 = mm[temp];
                   r2 = row;
                   c1 = col1;
                   c2 = col2;
                   break;
                }
                mm[ temp ]= row;
            }
            if(ans=="NO") break;
        }
        if(ans=="NO") break;
    }
    if(ans =="YES") cout<<ans<<endl;
    else {
        cout<<ans<<endl;
        cout<<r1<<" "<<r2<<endl;
        cout<<c1<<' '<<c2<<endl;

    }
  }

return 0;
}
