#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 210;
const int maxm = 26;

int T, n, cnt;
char s[maxn];
char final_ans[maxm];
bool vis[maxm];
bool Map[maxm][maxm];
int d[maxm];
vector<int>v[maxm];

bool dfs(int pos, int cur){
	vis[cur] = true;
	final_ans[cnt++] = cur+'a';
	if(pos == 0)return dfs(pos+1, v[cur][0]);
	else{
		if(d[cur] == 1)return true;
		if(d[cur] > 2)return false;
		if(vis[v[cur][0]]){
			return dfs(pos+1, v[cur][1]);
		}else{
			return dfs(pos+1, v[cur][0]);
		}
	}return true;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%s", s+1);
		n = strlen(s+1);
		memset(vis, false, sizeof(vis));
		for(int i = 0; i < 26; ++i){
			d[i] = 0;
			v[i].clear();
			vis[i] = false;
		}
		for(int i = 0; i < 26; ++i)for(int j = 0; j < 26; ++j)Map[i][j] = Map[j][i] = false;
		for(int i = 1; i < n; ++i){
			int a = s[i]-'a';
			int b = s[i+1]-'a';
			if(Map[a][b])continue;
			Map[a][b] = Map[b][a] = true;
			d[a]++; d[b]++;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		bool flag = true;
		cnt = 0;
		for(int i = 0; i < 26; ++i){
			if(vis[i])continue;
			if(d[i] == 0){
				vis[i] = true;
				final_ans[cnt++] = i+'a';
			}
			else if(d[i] == 1){
				if(!dfs(0, i)){
					flag = false;
					break;
				}
				//for(int i = 0; i < cnt; ++i)putchar(final_ans[i]);
				//printf("i = %d\n", i);
			}
			else if(d[i] > 2){
				flag = false;
				break;
			}
		}
		//for(int i = 0; i < cnt; ++i)putchar(final_ans[i]);
		//printf("\n");
		if(cnt != 26)flag = false;
		
		if(!flag)printf("NO\n");
		else{
			printf("YES\n");
			for(int i = 0; i < 26; ++i)putchar(final_ans[i]);
			printf("\n");
		}
	}return 0;
}