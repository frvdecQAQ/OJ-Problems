#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 2010;

int n, k, blo;
bool vis[maxn];
int nxt[maxn];
char ch[maxn];
int cnt = 0;

void getPrint(int type, int x){
	if(type == 0)printf("R\n");
	else if(type == 1)printf("? %d\n", x);
	else printf("! %d\n", x);
	fflush(stdout);
}

void dfs(int bloNum){
	int L = bloNum*k+1;
	int R = (bloNum+1)*k;
	for(int i = L; i <= R; ++i){
		if(vis[i])continue;
		getPrint(1, i);
		scanf("%s", ch);
		if(ch[0] == 'Y')vis[i] = true;
	}
	if(nxt[bloNum] < blo){
		dfs(nxt[bloNum]);
		nxt[bloNum]++;
		++cnt;
	}return;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)vis[i] = false;
	if(k > 1)k >>= 1;
	for(int i = 1; i <= n; ++i){
		getPrint(1, i);
		scanf("%s", ch);
		if(ch[0] == 'Y')vis[i] = true;
	}
	blo = n/k;
	for(int i = 0; i < blo; ++i){
		nxt[i] = i+2;
	}
	int lim = blo*(blo-1)/2-(blo-1);
	while(cnt < lim){
		getPrint(0, 0);
		for(int i = 0; i < blo; ++i){
			if(nxt[i] < blo){
				dfs(i);
				break;
			}
		}
	}
	cnt = 0;
	for(int i = 1; i <= n; ++i)if(!vis[i])++cnt;
	getPrint(2, cnt);
	return 0;
}