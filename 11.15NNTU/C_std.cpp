/**
 * @Author: zjt
 * @Date:   16-Nov-2020
 * @Email:  jianting112358@gmail.com
 * @Filename: C_std.cpp
 * @Last modified by:   zjt
 * @Last modified time: 16-Nov-2020
 */
 constexpr auto Inf = 0X3F3F3F3F;
 	#include <bits/stdc++.h>

 typedef long long LL;
 using namespace std;

 namespace IO {
 	inline LL read() {
 		LL o = 0, f = 1; char c = getchar();
 		while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
 		while (c > '/' && c < ':') { o = o * 10 + c - '0'; c = getchar(); }
 		return o * f;
 	}
 	inline char recd() {
 		char o; while ((o = getchar()) < '0' || o > '9'); return o;
 	}
 	inline double reod() {
 		double o = read(), f = 1; char c;
 		while ((c = getchar()) > '/' && c < ':') o += (c - '0') / (f *= 10);
 		return o;
 	}
 }
 using namespace IO;

 const int SIZE = 1E5 + 7, Mod = (1E9 + 7, 998244353);

 LL N, BIT[SIZE << 6]; LL vec[SIZE << 6]; int Ind, Len;

 int disc(LL w) {
 	int L = 1, R = Ind, M;
 	while (L <= R) {
 		M = (L + R) >> 1; vec[M] > w ? R = M - 1 : L = M + 1;
 	} return R;
 }

 void Upd(LL pos, LL w) {
 	LL e = w;
 	while (pos <= N) BIT[disc(pos)] += w, pos += pos & -pos, w += e;
 }

 void push(LL pos, int o) {
 	if (!o)
 		while (pos <= N) vec[++Ind] = pos, pos += pos & -pos;
 	else
 		while (pos) vec[++Ind] = pos, pos -= pos & -pos;
 }

 LL Ask(LL pos) {
 	LL res = 0; while (pos) res += BIT[disc(pos)], pos -= pos & -pos; return res;
 }

 struct o {
 	int o; LL L, R;
 } a[SIZE];

 int main() {
 	N = read(); int M = read();
 	for (int pos = 1; pos <= M; pos++) {
 		scanf("%d %lld %lld", &a[pos].o, &a[pos].L, &a[pos].R);
 		if (a[pos].o == 1)
 			push(a[pos].L, 0);
 		else
 			push(a[pos].L - 1, 1), push(a[pos].R, 1);
 	}
 	sort(vec + 1, vec + 1 + Ind);
 	Len = unique(vec + 1, vec + 1 + Ind) - vec - 1;

 	for (int pos = 1; pos <= M; pos++) {
 		if (a[pos].o == 1)
 			Upd(a[pos].L, a[pos].R);
 		else
 			printf("%lld\n", Ask(a[pos].R) - Ask(a[pos].L - 1));
 	}
 }
