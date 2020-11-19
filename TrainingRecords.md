

[toc]

# blank

 【腾讯文档】GXUN小队训练记录

    [ https://docs.qq.com/sheet/DWFd3aERFTHF0bU5P](https://docs.qq.com/sheet/DWFd3aERFTHF0bU5P)
# 10.20 蓝桥杯补题
  - [x] A
    - **description**
    - **idea**
    - **ref**
  - [ ] B
      - **description**
      - **idea**
      - **ref**
  - [ ] C
      - **description**
      - **idea**
      - **ref**

  - [ ] D
      - **description**
      - **idea**
      - **ref**
  - [ ] E
      - **description**
      - **idea**
      - **ref**
  - [ ] F
      - **description**
      - **idea**
      - **ref**
  - [ ] G
      - **description**
      - **idea**
      - **ref**
  - [ ] H
      - **description**
      - **idea**
      - **ref**
  - [ ] I
      - **description**
      - **idea**
      - **ref**
  - [ ] J
      - **description**
      - **idea**
      - **ref**
# 10.23 x 研究生个人赛 done
  ## e
  - description
    在无向图的结点 1-n 之间任意建边，使得从结点 1 到结点 n 的最短路径的数量达到最大。
  - idea
    问题等价于求（n-2）的最大拆分的整数的乘积，
    对于整数拆分最大化乘积方案:
    If a set of positive numbers has sum n, this is the largest value of their product.
    - dp: `a(n) = max{(n - i)*a(i) : i < n}; a(0) = 1 `
    - 数学思想：
       ```
          a(3n) = 3^n;
          a(3*n+1) = 4*3^(n-1) for n > 0;
          a(3*n+2) = 2*3^n.
        ```
      - 可以用数学归纳法证明对任意一个整数最大的拆分形式为 n = 2^p * 3^q (n >= 3, p, q为自然数)，并且q应该尽可能大（理由：如果q减少2，则p要增加3，而2^3 < 3^2，因此应该尽可能增加q）。

   - 整数拆分详细题解： https://leetcode-cn.com/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/
# Team10.24 银川
# 10.30 Team 南昌

  [2019 ICPC Asia Nanchang Regional - 比赛 - 计蒜客](https://www.jisuanke.com/contest/14923/challenges)

- [x] A
  - **description**
  - **idea**
  - **ref**
- [ ] B
    - **description**
    - **idea**
    - **ref**
- [ ] C
    - **description**
    - **idea**
    - **ref**

- [ ] D
    - **description**
    - **idea**
    - **ref**
- [ ] E
    - **description**
    - **idea**
    - **ref**
- [ ] F
    - **description**
    - **idea**
    - **ref**
- [ ] G
    - **description**
    - **idea**
    - **ref**
- [ ] H
    - **description**
    - **idea**
    - **ref**
- [ ] I
    - **description**
    - **idea**
    - **ref**
- [ ] J
    - **description**
    - **idea**
    - **ref**








    ## B



    ## C And and Pair

    - description

      给定 $n \in N^+$, $n<10^5$,给定一个最长n位的二进制下的字符串S，S可能有前导零，计算满足如下条件的有序对(i,j)的个数：


      - 0 ≤ *j* ≤ *i*≤ *n*;

      - $i \& n = i ;$ and

      - $i \& j =0$;

      $\&$ 是按位与操作，最后的结果取模后输出。

    - 思路

      -

    - 公式、构造




    ## 补题

    [2019ICPC南昌站C.And and Pair - wz-Archer - 博客园](x-devonthink-item://3CEAD486-7AFF-4DF6-BC5C-6D323199FCF2)

    [2019ICPC南昌站E.Bob's Problem - wz-Archer - 博客园](x-devonthink-item://8A90BFE1-BC58-4A64-9354-66CD42F3E4EC)

    [2019ICPC南昌 E Bob's Problem （最大生成树）_邵光亮的博客-CSDN博客](x-devonthink-item://33BC78DA-E69F-4A16-AD9B-7977957240C0)







    [2019 ICPC银川区域赛题解 – GOATWU｜ACM](x-devonthink-item://43BF4934-8A44-4413-B1FF-360EB99552C8)
# 10.31 Regional 西部赛区

     ## B 聚会
    - description
    - add
      - [洛谷原题补题链接](https://www.luogu.com.cn/problem/P3524)
# 11.7 SW

# 11.8 NNTU
  - 目录里有官方题解文件
- [x] A
  - **description**
  - **idea**
  - **ref**
- [ ] B
    - **description**
    - **idea**
    - **ref**
- [ ] C
    - **description**
    - **idea**
    - **ref**

- [ ] D
    - **description**
    - **idea**
    - **ref**
        [spoj 694 求字符串的不同子串个数 题解](https://blog.csdn.net/qq_24489717/article/details/51281262)
- [ ] E
    - **description**
    - **idea**
    - **ref**
- [ ] F
    - **description**
    - **idea**
    - **ref**
# 11.15School_2019_GXCPC
- [x] A
  - **description**
  - **idea**
  - **ref**
- [ ] B
    - **description**
    - **idea**
    - **ref**
- [ ] C
    - **description**
    - **idea**
    - **ref**

- [ ] D
    - **description**
    - **idea**
    - **ref**
- [ ] E
    - **description**
    - **idea**
    - **ref**
- [ ] F
    - **description**
    - **idea**
    - **ref**
- [ ] G
    - **description**
    - **idea**
      
      - ```cpp
        cin>>a[++cnt].ai>>a[cnt].bi>>a[cnt].wi; //多关注程序的warning,自增自减运算顺序未定导致结果出错。

        cnt++;
        cin>>a[++cnt].ai>>a[cnt].bi>>a[cnt].wi;
        ```

    - **ref**
    -
- [ ] H
    - **description**
    - **idea**
    - **ref**
- [ ] I
    - **description**
    - **idea**
    - **ref**
- [ ] J
    - **description**
    - **idea**
    - **ref**
# 11.15NNTU 5/6
- 补题链接 https://oj.gxu.edu.cn/problems?page=20
- 比赛链接 https://oj.gxu.edu.cn/contest/183/problems
- [x] A
  - **description**
  - **idea**
  -     注意可能会有负值或者非法值
  - **ref**
- [x] B
    - **description**
    - **idea**
    -       取模的问题尤其要注意用int数据类型存储的变量是否超出了int的范围，而且要及时取模，防止爆long long。
    - **ref**
- [x] C
    - **description**
    - **idea**
    - **ref**
    本题卡常数、卡 map、unordered_map、需要手写离散化或者用冲突少的(开放寻址的)哈希表来存储树状数组，另外就是树状数组的常用累加操作的优化。
    - oj https://oj.gxu.edu.cn/problem/1403

- [ ] D
    - **description**
    - **idea**
     有点儿难，线段树的维护，还涉及了矩阵序列的操作，做题的时候想到了一部分。
    - **ref**
- [x] E
    - **description**
    - **idea**
    -       模拟,不要读错题目的意思了。
    - **ref**
- [x] F
    - **description**
    给出一个数字符串 S，S 不存在前缀 0，将 S 切割为一些长度大于0的段，使得能被3整除的段尽可能的多，求该数量。
    - **idea**
      从题目的特点出发，先将字符串S的每一位数字都对3取模,然后贪心可知：若$s[i]$为字符‘0’,则直接将其切割出来，S于是必然变成若干个仅由1、2构成的子串,考虑对每个子串$s[l,r]$求最值，$dp[i]$表示子串$[l,i]$的最值,$i\in[l,r]$,则
      $$dp[i]=\begin{cases}
        0 & i == l\\
        1 & i == l+1 \&\& s[i]!=s[i-1] \\
        0 & i == l+1 \&\& s[i]==s[i-1] \\
        1 & i == l+2 \\
        max(dp[i-1],dp[i-2]+1) & i>l+2  \cap s[i] \neq s[i-1] \\
        max(dp[i-1],dp[i-3]+1) &  i>l+2 \cap s[i] == s[i-1] == s[i-2]
        \end{cases}$$
        - 思路2
           可以发现要想使某一段$[L,i]$的最值增大，必然是通过增加一个以$[pos,i]$的子串切割方式来使得以$[L,i]$的值增加，或者就是$S[i]$单独作为一个无效的串,具体参考官方题解中的描述。值得借鉴的地方是：保留了之前的三种可能的转移状态0、1、2，转移比较清晰。
           ```cpp
            char S[SIZE]; int DP[SIZE], g[3];
            int main() {
            	scanf("%s", S + 1);
            	int Len = strlen(S + 1); g[1] = g[2] = -1;
            	for (int pos = 1, pre = 0; pos <= Len; pos++) {
            		(pre += S[pos] - '0') %= 3;
            		DP[pos] = max(DP[pos - 1], g[pre] + 1);
            		g[pre] = max(g[pre], DP[pos]);
            	} printf("%d\n", DP[Len]);
                return 0;
            }
           ```
    - **ref**
# 11.17Niuke 4/4
   ref: https://blog.nowcoder.net/n/7d542c322778478ea770eb494b2a94dc?f=comment
   比赛： https://ac.nowcoder.com/acm/contest/9004
   https://ac.nowcoder.com/acm/contest/9005
   - [x] A
     - **description**
     - **idea**
     - **ref** 注意溢出和题目给的数据可能超过int。
   - [ ] B
       - **description**
       - **idea** 推简单公式，注意取模运算的优先级。
       - **ref**
   - [ ] C
       - **description**
       - **idea** 简单贪心。
       - **ref**

   - [ ] D
       - **description**
       - 链接：https://ac.nowcoder.com/acm/contest/9005/C
       来源：牛客网
    牛牛的数学老师教会了牛牛除法，牛牛十分开心，他知道任意一个正整数都可以表示为$n = p^k + mn=p×k+m $(k 为商，m为余数) 的方式，现在死脑筋的牛牛想要计算对于小于等于nn的每一个数$p(p≥1)$， 计算所有 $k×m$ 的和。这可难倒了牛牛，请你来帮帮他吧。(由于答案可能过大，请对10^9+7取模)
       - **idea** 简单分块，
       - **ref**
# 题单

- 比赛 牛客 https://ac.nowcoder.com/acm/contest/vip-index
- 牛客的acm题库  https://ac.nowcoder.com/acm/problem/list
- 牛客按照知识点分类的题单很好 https://ac.nowcoder.com/acm/skill/acm
 [ [OI] BZOJ 刷题表](https://www.acwing.com/file_system/file/content/whole/index/content/3105/)
 51nod 题库 http://www.51nod.com/Challenge/ProblemList.html#isAsc=false

 - extend
   - 离散化
     - https://blog.csdn.net/listenhhh/article/details/102365254
     - https://blog.nowcoder.net/n/aa21f22774f64735884bc9cdf8671044
   - 分块
     - https://zhuanlan.zhihu.com/p/114268236
     - https://www.cnblogs.com/sweetsc/archive/2012/08/15/2639395.html
