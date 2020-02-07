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

int n, k;
bool vis[maxn];
char ch[maxn];

void getPrint(int type, int x){
	if(type == 0)printf("R\n");
	else if(type == 1)printf("? %d\n", x);
	else printf("! %d\n", x);
	fflush(stdout);
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)vis[i] = false;
	if(k == 1){
		for(int i = 1; i <= n; ++i){
			if(vis[i])continue;
			for(int j = i+1; j <= n; ++j){
				if(vis[j])continue;
				getPrint(1, i);
				scanf("%s", ch);
				getPrint(1, j);
				scanf("%s", ch);
				if(ch[0] == 'Y')vis[j] = true;
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; ++i)if(!vis[i])++cnt;
		getPrint(2, cnt);
		return 0;
	}
	for(int i = 1; i <= n; ++i){
		getPrint(1, i);
		scanf("%s", ch);
		if(ch[0] == 'Y')vis[i] = true;
	}
	int blo = n/k;
	for(int i = 0; i < blo; ++i){
		int L = i*blo+1;
		int R = (i+1)*blo;
		int mid = L+(k>>1);
	}
	return 0;
}