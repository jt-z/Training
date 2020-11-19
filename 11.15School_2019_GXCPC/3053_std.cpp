/**
 * @Author: zjt
 * @Date:   19-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: 3053_std.cpp
 * @Last modified by:   zjt
 * @Last modified time: 19-Nov-2020
 */
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 ll Pow(ll a,ll b)
 {
 	if(b==0)
 	{
 		return 1;
 	}
 	if(b&1)
 	{
 		return a*Pow(a,b-1);
 	}
 	else
 	{
 		ll t=Pow(a,b/2);
 		return t*t;
 	}
 }
 int main()
 {

 	int t;
 	cin>>t;
 	while(t--)
 	{
 		ll n;
 		cin>>n;

 		int ans=60;
 		while(1)
 		{
 			if(ans==1)	break;
 			ll temp=1ll*pow(1.0*n,1.0/ans);
 			bool flag=true;
 			if(Pow(temp+1,ll(ans))!=n&&Pow(temp,ll(ans))!=n)	flag=false;
 			if(!flag)	ans--;
 			else	break;
 		}
 		cout<<ans<<endl;
 	}
 	return 0;
 }
