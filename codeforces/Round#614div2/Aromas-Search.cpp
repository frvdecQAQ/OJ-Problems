#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = 72;
const LL lim = 1e16;

LL x0, y0, ax, ay, bx, by;
LL xs, ys, t;

LL X[maxn];
LL Y[maxn];

int ans = 0;

LL getAbs(LL x){
	return x > 0?x : -x;
}

LL getDis(LL a, LL b, LL c, LL d){
	return getAbs(a-c)+getAbs(b-d);
}

int main(){
	scanf("%lld%lld", &x0, &y0);
	scanf("%lld%lld", &ax, &ay);
	scanf("%lld%lld", &bx, &by);
	scanf("%lld%lld", &xs, &ys);
	scanf("%lld", &t);
	int cnt = 0;
	while(x0 < lim && y0 < lim){
		X[cnt] = x0; Y[cnt] = y0;
		++cnt;
		x0 = ax*x0+bx;
		y0 = ay*y0+by;
	}
	X[cnt] = x0; Y[cnt] = y0;
	++cnt;
	for(int i = 0; i < cnt; ++i){
		int tmp = 0;
		LL T = t;
		T -= getDis(xs, ys, X[i], Y[i]);
		if(T < 0)continue;
		tmp++;
		LL nx = X[i], ny = Y[i];
		for(int j = i-1; j >= 0; --j){
			T -= getDis(nx, ny, X[j], Y[j]);
			if(T < 0)break;
			tmp++;
			nx = X[j]; ny = Y[j];
		}
		if(T < 0){
			ans = max(ans, tmp);
			continue;
		}
		for(int j = i+1; j < cnt; ++j){
			T -= getDis(nx, ny, X[j], Y[j]);
			if(T < 0)break;
			tmp++;
			nx = X[j]; ny = Y[j];
		}
		ans = max(ans, tmp);
	}printf("%d\n", ans);
	return 0;

}