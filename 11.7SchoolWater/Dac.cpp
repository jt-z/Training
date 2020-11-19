/**
 * @Author: zjt
 * @Date:   07-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: Dac.cpp
 * @Last modified by:   zjt
 * @Last modified time: 07-Nov-2020
 */
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 200;
const int INF=1e9+7;
int a[10]={6,2,5,5,4,5,6,3,7,6};
string s;
int ans[maxn];
int fun(int x){
   if(x%7==0) return x/7;
   else return x/7+1;
}
int main() {
    ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif

    cin.tie(0);
    cout.tie(0);
    int t,n;
    while(cin>>t){
    while (t--) {
        cin>>n;
        cin>>s;
        int d=0,l=s.length();
        for(int i=0; i<l; i++){
            d+=a[s[i]-'0'];
        }
        int wei=fun(d);
        for(int i=0;i<wei;i++){
            if(i==0){
                int v=-INF;
                for(int j=1;j<10;j++){
                /*  		if((d-a[j])%7==0)
                {
				ans[i]=8;
                        v=j;
                }	*/
                    if(fun(d-a[j])==wei-i-1&&(v==-INF||v>j)){
                        ans[i]=j;
                        v=j;
                    }
                }
                d-=a[v];
            }
            else{
                int v=-INF;
                for(int j=0;j<10;j++){
              /*  		if((d-a[j])%7==0)
                {
				ans[i]=8;
                        v=j;
                }	*/
                     if(fun(d-a[j])==wei-i-1&&(v==-INF||v>j)){
                        ans[i]=j;
                        v=j;
                    }
                }
                d-=a[v];
            }
        }
        for(int i=0;i<wei;i++) cout<<ans[i];
            cout<<endl;
    }
}
    return 0;
}
