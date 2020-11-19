/**
 * @Author: zjt
 * @Date:   08-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: D.cpp
 * @Last modified by:   zjt
 * @Last modified time: 08-Nov-2020
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long  LL;
typedef pair<int,int> PII;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define ford(i,l,u) for(LL (i)=(LL)(l);(i)>=(LL)(u);--(i))


#define N int(1e5+10)
#define inf int(0x3f3f3f3f)
#define mod int(1e9+7)
typedef long long LL;


#ifdef CDZSC
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

char s[N];
int sa[N], t[N], t2[N], c[N];

void build_sa(int n, int m)//n表示字符串的长度,m表示基数，用于m基数排序，数字的上限
{
   int i, *x = t, *y = t2;
   for (i = 0; i<m; i++)c[i] = 0;
   for (i = 0; i<n; i++)c[x[i] = s[i]]++;
   for (i = 1; i<m; i++)c[i] += c[i - 1];
   for (i = n - 1; i >= 0; i--)sa[--c[x[i]]] = i;
   for (int k = 1; k <= n; k <<= 1)
   {
       int p = 0;
       for (i = n - k; i<n; i++)y[p++] = i;
       for (i = 0; i<n; i++)if (sa[i] >= k)y[p++] = sa[i] - k;

       for (i = 0; i<m; i++)c[i] = 0;
       for (i = 0; i<n; i++)c[x[y[i]]]++;
       for (i = 1; i<m; i++)c[i] += c[i - 1];
       for (i = n - 1; i >= 0; i--)sa[--c[x[y[i]]]] = y[i];
       swap(x, y);
       p = 1; x[sa[0]] = 0;
       for (i = 1; i<n; i++)
           x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
       if (p >= n)break;
       m = p;
   }
}

int Rank[N], height[N];
void gethight(int n)//n表示字符串的长度
{
   int i, j, k = 0;
   for (int i = 0; i<n; i++)Rank[sa[i]] = i;
   for (int i = 0; i<n; i++)
   {
       if (k)k--;
       else k = 0;
       int j = sa[Rank[i] - 1];
       while (s[i + k] == s[j + k])k++;
       height[Rank[i]] = k;
   }
}
int main()
{

        #ifdef LOCAL
        freopen("local.in","r",stdin);
        #endif
       while (scanf("%s", s)!=EOF)
       {
           LL ans;

           int len = strlen(s);
           ans = 0;
           build_sa(len+1, 128);
           gethight(len+1);
           for (int i = 1; i <= len; i++)
           {
               //printf("%d %d %d\n", sa[i], height[i], height[i]);
               ans +=( len-sa[i]-height[i]);
               /*sa数组表示下标，
               height[i]数组表示sa[i-1]和sa[i]的最长公共前缀，
               每一个子串一定是某个后缀的前缀，那么问题便等价
               于求所有后缀之间的不相同的前缀个数。我们按sa的
               顺序来考虑，当加入sa[k]的时候，sa[k]这个后缀的
               长度为n-sa[k]，那么便有n-sa[k]个前缀，但是由
               heigh数组可知sa[k]与sa[k-1]有height[k]个前缀
               是相同的，所以要除去，最终的答案便是
               sigma(n-sa[k]+height[k])*/
           }
           printf("%lld\n",ans);
       }
   return 0;
}
