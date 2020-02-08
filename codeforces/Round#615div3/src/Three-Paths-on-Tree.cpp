#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

const int maxn = 200010;
const int inf = 0x7fffffff;
int n, u, v, ans;
int a, b ,c;
int h[maxn], cnt = 0;
int to[maxn << 1], nxt[maxn << 1];
int fa[maxn];
int dp[maxn][3];
int plan[maxn][3];

void add(int u, int v){
	++cnt;
	to[cnt] = v; nxt[cnt] = h[u]; h[u] = cnt;
	++cnt;
	to[cnt] = u; nxt[cnt] = h[v]; h[v] = cnt;
}

void dfs(int u){
	int ch = 0;
	for(int i = h[u]; i; i = nxt[i]){
		int v = to[i];
		if(v == fa[u])continue;
		fa[v] = u; ++ch;
		dfs(v);
	}
	if(ch == 0){
		dp[u][1] = 0; 
		plan[u][0] = u;
		dp[u][2] = -inf;
		plan[u][1] = plan[u][2] = -1;
		return;
	}
	int t1 = -1, p1 = -1;
	int t2 = -1, p21 = -1, p22 = -1;
	int ct1 = -1, cp1 = -1;
	for(int i = h[u]; i; i = nxt[i]){
		int v = to[i];
		if(v == fa[u])continue;
		//1
		if(dp[v][1]+1 > dp[u][1]){
			dp[u][1] = dp[v][1]+1;
			plan[u][0] = plan[v][0];
		}
		//2
		if(dp[v][2]+1 > dp[u][2]){
			dp[u][2] = dp[v][2]+1;
			plan[u][1] = plan[v][1];
			plan[u][2] = plan[v][2];
		}
		if(dp[v][1]+1 > dp[u][2]){
			dp[u][2] = dp[v][1]+1;
			plan[u][1] = plan[v][0];
			plan[u][2] = u;
		}
		if(t1 != -1){
			if(t1+dp[v][1]+2 > dp[u][2]){
				dp[u][2] = t1+dp[v][1]+2;
				plan[u][1] = p1;
				plan[u][2] = plan[v][0];
			}
		}
		//3
		if(t1 != -1){
			if(t1+dp[v][2]+2 > ans){
				ans = t1+dp[v][2]+2;
				a = p1; b = plan[v][1]; c = plan[v][2];
			}
			if(t1+dp[v][1]+2 > ans){
				ans = t1+dp[v][1]+2;
				a = p1; b = plan[v][0]; c = u;
			}
			if(ct1 != -1){
				if(t1+ct1+dp[v][1]+3 > ans){
					ans = t1+ct1+dp[v][1]+3;
					a = p1; b = cp1; c = plan[v][0];
				}
			}
		}
		if(t2 != -1){
			if(t2+dp[v][1]+2 > ans){
				ans = t2+dp[v][1]+2;
				a = p21; b = p22; c = plan[v][0];
			}
		}
		if(dp[v][2]+1 > ans){
			ans = dp[v][2]+1;
			a = plan[v][1];
			b = plan[v][2];
			c = u;
		}
		//update
		if(dp[v][2] > t2){
			t2 = dp[v][2];
			p21 = plan[v][1];
			p22 = plan[v][2];
		}
		if(dp[v][1] > t1){
			if(t1 != -1){
				ct1 = t1;
				cp1 = p1;
			}
			t1 = dp[v][1];
			p1 = plan[v][0];
		}else if(dp[v][1] > ct1){
			ct1 = dp[v][1];
			cp1 = plan[v][0];
		}
	}
	return;
}


int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	ans = -1; a = -1; b = -1; c = -1;
	for(int i = 1; i <= n; ++i)dp[i][1] = dp[i][2] = 0;
	dfs(1);
	printf("%d\n", ans);
	printf("%d %d %d\n", a, b, c);
	return 0;
}