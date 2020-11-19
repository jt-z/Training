/**
 * @Author: zjt
 * @Date:   17-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: B_temp.cpp
 * @Last modified by:   zjt
 * @Last modified time: 18-Nov-2020
 */



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param n long长整型 表示标准完全二叉树的结点个数
     * @return long长整型
     */
    int d;
    int getd(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n = n >> 1;
        }
        //cout<<"d of n "<<cnt<<" "<<n<<endl;
        return cnt;
    }
    const long long mod = 998244353;

    long long tree4(long long n) {
        // write code here
        long long pw2[61];
        pw2[0] = 1;
        pw2[1]= 2;
        for(int i=2;i<=60;i++) pw2[i] =2 *pw2[i-1]%mod;
        d = getd(n);
        long long ans = 0;
        for(int i=1;i<=d-1;i++){
            long long t;
            if(i==1) t = 1;
            else if(i==2) t=10;
            else {
                t = i;
                t = t * pw2[i-2] %mod;
                t = t * ( (3l*pw2[i-1]%mod) - 1l + mod)%mod;
            }
            ans =  ans + t%mod;
        }
        long long les = d;
        les = les *(pw2[d-1] +n %mod)%mod;
        les = les *(n- pw2[d-1] +1) %mod;
        les = les * 499122177 %mod;
        ans = ans + les%mod;
        cout<<ans<<endl;


    }
};
