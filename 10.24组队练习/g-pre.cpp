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

#define ls (p<<1)
#define rs (p<<1|1)
typedef long long ll;
int q;
const int maxn = 100005;
//t 2,3,5,7;
//  0 1 2 3
struct sgt
{
	int l,r;
	ll sum,ladd,lmul;//区间和，加法标记，乘法标记
}t[4][400100];//,t3[maxn<<2],t5[maxn<<2],t7[maxn<<2];
int n,m,Q=100000007;
int a[100010];
void updata(int id,int p)
{
	t[id][p].sum = (t[id][ls].sum+t[id][rs].sum)%Q;
}

void build(int id,int p,int l,int r)
{
	t[id][p].l = l,t[id][p].r = r;
	t[id][p].ladd = 0,t[id][p].lmul = 1;
	if(l==r)
	{
		//cin>>t[id][p].sum;
		t[id][p].sum=0;
		return;
	}
	int mid = (l+r)/2;
	build(id,ls,l,mid);
	build(id,rs,mid+1,r);
	updata(id,p);
}

void spread(int id,int p)
{
	if(t[id][p].lmul!=1)
	{
		t[id][ls].sum  = (t[id][ls].sum *t[id][p].lmul)%Q;
		t[id][rs].sum  = (t[id][rs].sum *t[id][p].lmul)%Q;
		t[id][ls].lmul = (t[id][ls].lmul*t[id][p].lmul)%Q;
		t[id][rs].lmul = (t[id][rs].lmul*t[id][p].lmul)%Q;
		t[id][ls].ladd = (t[id][ls].ladd*t[id][p].lmul)%Q;
		t[id][rs].ladd = (t[id][rs].ladd*t[id][p].lmul)%Q;
		t[id][p].lmul = 1;
	}
	if(t[id][p].ladd)
	{
		t[id][ls].sum  = (t[id][ls].sum +t[id][p].ladd*(t[id][ls].r-t[id][ls].l+1))%Q;
		t[id][rs].sum  = (t[id][rs].sum +t[id][p].ladd*(t[id][rs].r-t[id][rs].l+1))%Q;
		t[id][ls].ladd = (t[id][ls].ladd+t[id][p].ladd)%Q;
		t[id][rs].ladd = (t[id][rs].ladd+t[id][p].ladd)%Q;
		t[id][p].ladd  = 0;
	}
}

void change(int id,int p ,int l,int r,int k,int a) //a为哪种运算
 // 2    change(0,1,l,r,mici,2)
 //  3   change(1,1,l,r,mici,2)
 //   5  change(2,1,l,r,mici,2)
 //    7 change(3,1,l,r,mici,2)
{
	spread(id,p);
	if(l<=t[id][p].l && t[id][p].r<=r)
	{

		if(a==2)
		{	t[id][p].sum = (t[id][p].sum+k*(t[id][p].r - t[id][p].l+1))%Q;
			t[id][p].ladd = (t[id][p].ladd+k)%Q;
		}
		if(a==1)
		{
			t[id][p].sum =(t[id][p].sum*k)%Q;
			t[id][p].lmul =(t[id][p].lmul*k)%Q;
		}
		return;
	}
	int mid = (t[id][p].l+t[id][p].r)/2;
	if(l<=mid)change(id,ls,l,r,k,a);
	if(mid<r)change(id,rs,l,r,k,a);
	updata(id,p);
}


ll query(int id,int p,int L,int R)
{

	if(L<=t[id][p].l &&t[id][p].r<=R)
	{
		return t[id][p].sum%Q;
	}
    spread(id,p);
	ll ans = 0;
	int mid = (t[id][p].l+t[id][p].r)/2;
	if(L<=mid)	ans += query(id,ls,L,R);
	if(R>mid)	ans += query(id,rs,L,R);
	return ans%Q;
}


int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>q){
		for(int i=0;i<=3;i++) build(i,1,1,n);

		// cout<<"tree build: "<<endl;
		// for(int id=0;id<=3;id++){
		// 		cout<<"tree id is"<<id<<endl;
		// 		for(int i=1;i<=n;i++) { cout<<query(id,1,i,i)<<" ";}
		// 		cout<<endl;

		// }
		// cout<<"_____________"<<endl;
		// cout<<endl<<endl;
		bool has_mul=false;
		for(int i=1;i<=q;i++){
			string op;
			cin>>op;
			int l,r,x;
			cin>>l>>r;
			if(op[1]=='U') {
				cin>>x;
				has_mul = true;

 // 2    change(0,1,l,r,mici,2)
 //  3   change(1,1,l,r,mici,2)
 //   5  change(2,1,l,r,mici,2)
 //    7 change(3,1,l,r,mici,2)
				if(2==x) {
					change(0,1,l,r,1,2);
				} else if(3==x){
					change(1,1,l,r,1,2);
				} else if(4==x){
					change(0,1,l,r,2,2);
				} else if(5==x){
					change(2,1,l,r,1,2);
				} else if(6==x){
					change(0,1,l,r,1,2);
					change(1,1,l,r,1,2);
				} else if(7==x){
					change(3,1,l,r,1,2);
				} else if(8==x){
					change(0,1,l,r,3,2);
				} else if(9==x){
					change(1,1,l,r,2,2);
				} else if(10==x){
					change(0,1,l,r,1,2);
					change(2,1,l,r,1,2);
				}
				// cout<<"change "<<x<<endl;
				// for(int id=0;id<=3;id++){
				// 		cout<<"tree id is"<<id<<endl;
				// 		for(int i=1;i<=n;i++) { cout<<t[id][i].sum<<" ";}
				// 		cout<<endl;

				// }
				// cout<<"_____________"<<endl;
				// cout<<endl<<endl;
			}else{
				if(!has_mul ) {cout<<"ANSWER 1"<<endl; continue;}
				ll ans=-1;
				for(int i=0;i<=3;i++){
					for(int j=l;j<=r;j++)
					ans  = max(ans,query(i,1,j,j) );
					//cout<<"ans: "<<ans;
				}
				cout<<"ANSWER "<<ans<<endl;

			}



		}
	}

	return 0;
}
