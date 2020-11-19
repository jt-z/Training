/**
 * @Author: zjt
 * @Date:   07-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: D.cpp
 * @Last modified by:   zjt
 * @Last modified time: 07-Nov-2020
 */



#include<string>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int a[10]={6,2,5,5,4,5,6,3,7,6};
string f(int k,int dig){
    string ret="";
    string t="0";
    while(k--) {
            t[0]+=dig;
            ret+=t;
            t[0]='0';
        }
    return ret;
}
int main(){

    int T;
   // cout<<f(9,8)<<endl;
    //freopen("local.in","r",stdin);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif

    while(cin>>T){
        while(T--){
            int n;
            cin>>n;
            string s;
            cin>>s;
            int cnt=0;
            int len=s.size();
            for(int i=1;i<=len;i++){
                cnt+=a[ s[i-1]-'0'];
            }
            int m=cnt%7;
            int k=cnt/7;
            string ans="";
            if(cnt<=13){
                if(cnt==2) ans="1";
                else if(cnt==3) ans="7";
                else if(cnt==4) ans="4";
                else if(cnt==5) ans="2";
                else if(cnt==6) ans="6";
                else if(cnt==7) ans="8";
                else if(cnt==8) ans="10";
                else if(cnt==9) ans="18";
                else if(cnt==10) ans="22";
                else if(cnt==11) ans="20";
                else if(cnt==12) ans="28";
                else if(cnt==13) ans="68";
                cout<<ans<<endl;
                continue;
            }
            if(m==0){
                ans=f(k,8);
            }else if(m==1){
                ans+=f(1,1);
                ans+=f(1,0);
                ans+=f((cnt-8)/7, 8);
            }else if(m==2){
                ans+=f(1,1);
                ans+=f((cnt-2)/7, 8);
            }else if(m==3){
                ans+=f(1,2);
                ans+="00";
                ans+=f( (cnt-10-7)/7, 8);
                //2008888888888888
                //2288888888888888
            }else if(m==4){
                ans+="20";
                ans+=f((cnt-11)/7, 8);
            }else if(m==5){
                ans+="2";
                ans+=f((cnt-5)/7, 8);
            }else if(m==6){
                ans+="6";
                ans+=f((cnt-6)/7, 8);
            }
            cout<<ans<<endl;
       }
    }


    return 0;
}
