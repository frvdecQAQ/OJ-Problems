#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

const int maxm = 100010;

priority_queue<LL>Q;

int T;
int m;
LL n;
int a[maxm];

int getCount(LL tmp){
	for(int i = 0; i <= 60; ++i){
		if((tmp >> i)&1LL)return i;
	}return 0;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld%d", &n, &m);
		while(!Q.empty())Q.pop();
		for(int i = 1; i <= m; ++i){
			scanf("%d", &a[i]);
			Q.push(-a[i]);
		}
		int ans = 0;
		int cur = 0;
		bool flag = true;
		for(int i = 0; i <= 60; ++i){
			if((n>>i)&1LL){
				if(i < cur)continue;
				if(Q.empty()){
					flag = false;
					break;
				}
				LL tmp = Q.top(); Q.pop();
				tmp = -tmp;
				int now = getCount(tmp);
				ans += now-i;
				cur = now;
			}
			int cnt = 0;
			while(!Q.empty() && Q.top() == -(1LL<<i)){
				++cnt;
				Q.pop();
			}
			cnt >>= 1;
			while(cnt--)Q.push(-(1LL<<(i+1)));
		}
		if(!flag)printf("-1\n");
		else printf("%d\n", ans);
	}return 0;
}