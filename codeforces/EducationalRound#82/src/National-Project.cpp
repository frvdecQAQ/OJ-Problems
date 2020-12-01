#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

int T;
LL n, g, b;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld%lld", &n, &g, &b);
		LL lim = ((n+1)>>1);
		LL cnt = 0;
		if(lim%g == 0)cnt = (lim/g)*(g+b)-b;
		else{
			cnt = (lim/g)*(g+b)+(lim%g);
		}
		if(cnt < n)cnt = n;
		printf("%lld\n" ,cnt);
	}return 0;
}