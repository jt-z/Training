/**
 * @Author: zjt
 * @Date:   25-Oct-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: g.cpp
 * @Last modified by:   zjt
 * @Last modified time: 25-Oct-2020
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long  LL;
typedef pair<int,int> PII;
#define mem(A, X) memset(A, X, sizeof A)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define fori(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define ford(i,l,u) for(LL (i)=(LL)(l);(i)>=(LL)(u);--(i))


#define ls (p<<1)
#define rs (p<<1|1)
int q,n;
const int maxn = 100005;
//t 2,3,5,7;
//  0 1 2 3
const int maxnode = 4*maxn;

int _sum, _min, _max, op, qL, qR, v;

struct IntervalTree {
  int sumv[maxnode], minv[maxnode], maxv[maxnode], addv[maxnode];

  // 维护信息
  void maintain(int o, int L, int R) {
    int lc = o*2, rc = o*2+1;
    sumv[o] = minv[o] = maxv[o] = 0;
    if(R > L) {
      sumv[o] = sumv[lc] + sumv[rc];
      minv[o] = min(minv[lc], minv[rc]);
      maxv[o] = max(maxv[lc], maxv[rc]);
    }
    if(addv[o]) { minv[o] += addv[o]; maxv[o] += addv[o]; sumv[o] += addv[o] * (R-L+1); }
  }

  void update(int o, int L, int R) {
    int lc = o*2, rc = o*2+1;
    if(qL <= L && qR >= R) { // 递归边界
      addv[o] += v; // 累加边界的add值
    } else {
      int M = L + (R-L)/2;
      if(qL <= M) update(lc, L, M);
      if(qR > M) update(rc, M+1, R);
    }
    maintain(o, L, R); // 递归结束前重新计算本结点的附加信息
  }

  void query(int o, int L, int R, int add) {
    if(qL <= L && qR >= R) { // 递归边界：用边界区间的附加信息更新答案
      _sum += sumv[o] + add * (R-L+1);
      _min = min(_min, minv[o] + add);
      _max = max(_max, maxv[o] + add);
    } else { // 递归统计，累加参数add
      int M = L + (R-L)/2;
      if(qL <= M) query(o*2, L, M, add + addv[o]);
      if(qR > M) query(o*2+1, M+1, R, add + addv[o]);
    }
  }
};

const int INF = 1000000000;

IntervalTree t[4];

void add(int x,int tv){
    v = tv;
    int id;
    if(x == 2){
        id = 0;
    }else if(x == 3){
        id = 1;
    } else if(x == 5){
        id = 2;
    } else {
        id = 3;
    }
    t[id].update(1,1,n);

}

int main(){
	ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("local.in","r",stdin);
    #endif

	while(cin>>n>>q){
		for(int i=0;i<=3;i++) mem(t,0);
		bool has_mul=false;
		for(int i=1;i<=q;i++){
			string op;
			cin>>op;
			int l,r,x;
			cin>>l>>r;
            qL = l;
            qR = r;
			if(op[1]=='U') {
				cin>>x;
				has_mul = true;
 //2    change(0,1,l,r,mici,2)
 //3    change(1,1,l,r,mici,2)
 //5    change(2,1,l,r,mici,2)
 //7    change(3,1,l,r,mici,2)
				if(2==x || 3==x || 5==x || 7==x) {
                    add(x,1);
				} else if(4==x){
                    add(2,2);
				} else if(6==x){
                    add(2,1);
                    add(3,1);
				} else if(8==x){
                    add(2,3);
				} else if(9==x){
                    add(3,2);
				} else if(10==x){
                    add(2,1);
                    add(5,1);
				}
			}else{
				if(!has_mul ) {cout<<"ANSWER 1"<<endl; continue;}
				int ans=-1;
                _max = -INF;
				for(int i=0;i<=3;i++){
                    t[i].query(1,1,n,0);
					ans  = max(ans, _max);
				}
				cout<<"ANSWER "<<ans<<endl;

			}



		}
	}

	return 0;
}
