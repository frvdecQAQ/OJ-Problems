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

priority_queue<int>Q;

int T;
int m;
LL n, cnt;
int a[maxm];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld%d", &n, &m);
		cnt = 0;
		for(int i = 1; i <= m; ++i){
			scanf("%d", &a[i]);
			cnt += a[i];
		}
		if(cnt < n)printf("-1\n");
		else{
			while(!Q.empty())Q.pop();
			for(int i = 1; i <= m; ++i)Q.push(a[i]);
			cnt = cnt-n;
			int ans = 0;
			while(!Q.empty() && cnt > 0){
				int cur = Q.top(); Q.pop();
				if(cur == 1)continue;
				cur >>= 1;
				if(cnt-cur >= 0){
					cnt -= cur;
					Q.push(cur);
					++ans;
				}
			}
			if(cnt == 0)printf("%d\n", ans);
			else printf("-1\n");
		}
	}return 0;
}