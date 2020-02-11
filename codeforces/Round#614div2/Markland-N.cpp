#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1010;

int T, x;
int n, s, k;
int upAns, downAns;
int up[maxn];
int down[maxn];


int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &s, &k);
		memset(up, 0, sizeof(up));
		memset(down, 0, sizeof(down));
		upAns = 0; downAns = 0;
		for(int i = 1; i <= k; ++i){
			scanf("%d", &x);
			x -= s;
			if(x >= 0 && x <= 1000){
				up[x] = 1;
				while(up[upAns] && s+upAns <= n)upAns++;
			}
			if(x <= 0 && x >= -1000){
				down[-x] = 1;
				while(down[downAns] && s-downAns >= 1)downAns++;
			}
		}
		if(s-downAns < 1)printf("%d\n", upAns);
		else if(s+upAns > n)printf("%d\n", downAns);
		else printf("%d\n", min(upAns, downAns));
	}return 0;
}