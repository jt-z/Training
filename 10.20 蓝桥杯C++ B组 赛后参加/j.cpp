/**
 * @Author: zjt
 * @Date:   19-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: j.cpp
 * @Last modified by:   zjt
 * @Last modified time: 20-Oct-2020
 */
 #include <bits/stdc++.h>
 using namespace std;
 typedef long long  ll;
 #define fori(i,l,u) for(ll (i)=(ll)(l);(i)<=(ll)(u);++(i))
 #define mem(A, X) memset(A, X, sizeof A)

 const int N = 1e4 + 10;
 char ans[N], res[N];
 int n, len;
 bool judge()
 {
 	int i = len;
 	while(ans[i] == res[i] && i) i--;
 	return res[i] < ans[i];
 }
 void dfs(int now, int maxn, int m, int sum) {
 	if(sum == n)
 	{
 		if(m < len || (m == len && judge()))
 		{
 			len = m;
 			for(int i = 1; i <= len; i++) 	ans[i] = res[i];
 		}
 		return;
 	}
 	if(now >= 26) return ;
 	for(int i = 1; i <= maxn; i++)
 	{
 		int temp = sum + m * i;
 		if(temp > n) return ;
 		res[m + i] = char(now + 'a');
 		dfs(now + 1, i, m + i, temp);
 	}
 }

 int main()
 {
     len = 0x3f3f3f3f;
     //freopen("local.in","r",stdin);
     //scanf("%d", &n);
     fori(i,1,100){

         n = i;
         n=22;
         dfs(0, 8, 0, 0);
         for(int i = len; i >= 1; i--)
 		 putchar(ans[i]);
         cout<<endl;
         break;
     }
     return 0;
 }
