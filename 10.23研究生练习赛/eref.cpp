/**
 * @Author: zjt
 * @Date:   08-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: eref.cpp
 * @Last modified by:   zjt
 * @Last modified time: 08-Nov-2020
 */
 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
     int f[45],n,t;
     f[0]=1,f[1]=1;
     for(int i=2;i<40;i++)
     {
         int t=1,j=i;
         while(j>4)
         {
             t*=3;
             j-=3;
         }
         t*=j;
         f[i]=t;

        cout<<f[i]<<" ";//<<endl;
     }
     // scanf("%d",&t);
     // while(t--)
     // {
     //     cin>>n;
     //     cout<<f[n-2]<<endl;
     // }
     return 0;
 }
