/**
 * @Author: zjt
 * @Date:   17-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: C.cpp
 * @Last modified by:   zjt
 * @Last modified time: 18-Nov-2020
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

string s;
int k;
void f(string &t, int val){
    int car = val;
    int pos = (int)t.size()-1;
    do{
        int tt = t[pos]+car - '0';
        if(tt>9) car = 1;
        else car = 0;
        t[pos] = '0'+tt%10;
        pos -- ;
        if(pos<0){
            t = "1" +t;
            break;
        }
    }
    while(car);

}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif
    while(cin>>s>>k){
        sort(s.begin(),s.end() );
        reverse(s.begin(),s.end() );
        string t = s.substr(0,(int)s.size()-k+1);
        fori(i,(int)t.size(),s.size()-1) f(t,s[i]-'0');
        cout<<s<<" "<<t<<endl;

    }

return 0;
}
