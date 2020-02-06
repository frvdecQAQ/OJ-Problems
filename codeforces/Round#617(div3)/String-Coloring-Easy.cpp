#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

const int maxn = 210;
const int inf = 0x7fffffff;

int n;
char s[maxn];
int num[maxn];	
int dp[maxn][maxn];
int pre[maxn][maxn];
int color[maxn][maxn];
int Ans[maxn];

int main(){
	scanf("%d", &n);
	scanf("%s", s+1);
	for(int i = 1; i <= n; ++i){
		num[i] = (int)(s[i]-'a');
	}
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j < 26; ++j)dp[i][j] = inf;
	}
	dp[0][0] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 26; ++j){
			if(dp[i][j] == inf)continue;
			int cur = i+1;
			if(num[cur] >= j){
				if(dp[cur][num[cur]] > dp[i][j]){
					dp[cur][num[cur]] = dp[i][j];
					pre[cur][num[cur]] = j;
					color[cur][num[cur]] = 1;
				}
			}
			if(num[cur] >= dp[i][j]){
				if(dp[cur][j] > num[cur]){
					dp[cur][j] = num[cur];
					pre[cur][j] = j;
					color[cur][j] = 0;
				}
			}
		}
	}
	int ans = -1;
	for(int i = 0; i < 26; ++i){
		if(dp[n][i] != inf)ans = i;
	}
	if(ans != -1){
		printf("YES\n");
		for(int i = n; i >= 1; --i){
			Ans[i] = color[i][ans];
			ans = pre[i][ans];
		}
		for(int i = 1; i <= n; ++i)printf("%d", Ans[i]);
		printf("\n");
	}
	else printf("NO\n");
	return 0;
}