#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 410;

int T, n, tn;
char s[maxn];
char t[maxn];
int dp[maxn][maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%s", s+1);
		scanf("%s", t+1);
		n = strlen(s+1);
		tn = strlen(t+1);
		bool flag = false;
		for(int i = 0; i < tn; ++i){
			//切点
			int lsize = i;
			int rsize = tn-i;
			for(int j = 0; j <= n; ++j)for(int k = 0;k <= lsize; ++k)dp[j][k] = -1;
			dp[0][0] = 0;
			for(int j = 0; j < n; ++j){
				for(int k = 0; k <= lsize; ++k){
					//if(i == 3)printf("dp[%d][%d] = %d\n", j, k, dp[j][k]);
					if(dp[j][k] == -1)continue;
					int lp, rp;
					if(k == lsize)lp = -1;
					else lp = t[k+1];
					if(dp[j][k] == rsize)rp = -1;
					else rp = t[lsize+dp[j][k]+1];
					if(lp != -1 && s[j+1] == lp){
						dp[j+1][k+1] = max(dp[j+1][k+1], dp[j][k]);
					}
					if(rp != -1 && s[j+1] == rp){
						dp[j+1][k] = max(dp[j+1][k], dp[j][k]+1);
					}
					dp[j+1][k] = max(dp[j+1][k], dp[j][k]);
				}
			}
			if(dp[n][lsize] == rsize){
				flag = true;
				break;
			}
		}
		if(!flag)printf("NO\n");
		else printf("YES\n");
	}return 0;
}