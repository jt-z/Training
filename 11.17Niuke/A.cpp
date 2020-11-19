/**
 * @Author: zjt
 * @Date:   17-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: A.cpp
 * @Last modified by:   zjt
 * @Last modified time: 17-Nov-2020
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef pair<int,int> PII;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(ll (i)=(ll)(l);(i)<=(ll)(u);++(i))
#define ford(i,l,u) for(ll (i)=(ll)(l);(i)>=(ll)(u);--(i))
#define lowbit(x) (x)&(-(x))
#define fir first
#define sec second

int a[1003];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif
    string line;
    while(cin>>line){
        fori(i,1,line.size()-2){
            if(line[i] == ',') line[i] =' ';
        }
        stringstream ss(line.substr(1,line.size()-2 ));
        int cnt = 0;
        while(ss>>a[cnt++]){

        }
        sort(a,a+cnt);
        int minv = 100000;
        fori(i,1,cnt-1) minv = min(minv,a[i]-a[i-1]);
        cout<<minv<<endl;

    }

return 0;
}
