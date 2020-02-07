#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 300010;

struct Edge{
	int u, v;
	void set(int x){
		if(u == -1)u = x;
		else v = x;
	}
}e[maxn];

int n, k, num, x;
char s[maxn];
int fa[maxn];
int color[maxn];
int flag[maxn];
bool canChange[maxn];
int sz[maxn], bsz[maxn];
int ans = 0;

int getFather(int u){
	if(fa[u] == u)return u;
	int f = getFather(fa[u]);
	if(fa[u] != f){
		color[u] ^= flag[fa[u]];
		flag[u] ^= flag[fa[u]];
	}
	fa[u] = f;
	return f;
}

void ansDel(int f){
	if(!canChange[f])ans -= (sz[f]-bsz[f]);
	else ans -= min(bsz[f], sz[f]-bsz[f]);
}

void ansAdd(int f){
	if(!canChange[f])ans += (sz[f]-bsz[f]);
	else ans += min(bsz[f], sz[f]-bsz[f]);
}

void flip(int f){
	flag[f] ^= 1;
	bsz[f] = sz[f]-bsz[f];
	return;
}

void merge(int u, int v, int x, int uf, int vf){
	int uc = color[u]^flag[uf];
	int vc = color[v]^flag[vf];
	//printf("%d %d %d %d %d\n", u, v, x, uf, vf);
	ansDel(uf); ansDel(vf);
	if((uc^vc) != x){
		if(canChange[uf])flip(uf);
		else flip(vf);
	}
	flag[vf] ^= flag[uf];
	color[vf] ^= flag[vf];
	fa[vf] = uf;
	sz[uf] += sz[vf];
	bsz[uf] += bsz[vf];
	canChange[uf] = canChange[vf] = (canChange[vf] && canChange[uf]);
	ansAdd(uf);
}

int main(){
	scanf("%d%d", &n, &k);
	scanf("%s", s+1);
	for(int i = 1; i <= n; ++i)e[i].u = e[i].v = -1;
	for(int i = 1; i <= k; ++i)fa[i] = i;
	for(int i = 1; i <= k; ++i)color[i] = 0;
	for(int i = 1; i <= k; ++i)flag[i] = 0;
	for(int i = 1; i <= k; ++i)canChange[i] = true;
	for(int i = 1; i <= k; ++i)sz[i] = 1;
	for(int i = 1; i <= k; ++i)bsz[i] = 1;
	for(int i = 1; i <= k; ++i){
		scanf("%d", &num);
		for(int j = 1; j <= num; ++j){
			scanf("%d", &x);
			e[x].set(i);
		}
	}
	/*for(int j = 1; j <= k; ++j){
		int f = getFather(j);
		printf("%d ", color[j]^flag[f]);
	}printf("\n");*/
	for(int i = 1; i <= n; ++i){
		int u = e[i].u;
		int v = e[i].v;
		//printf("i = %d, u = %d, v = %d\n", i, u, v);
		x = (int)(s[i]-'0');
		x ^= 1;
		if(u == -1){
			printf("%d\n", ans);
			continue;
		}
		if(v == -1){
			int f = getFather(u);
			int nowColor = color[u]^flag[f];
			ansDel(f);
			canChange[f] = false;
			if(nowColor != x)flip(f);
			ansAdd(f);
		}else{
			int uf = getFather(u);
			int vf = getFather(v);
			if(uf != vf)merge(u, v, x, uf, vf);
		}
		/*for(int j = 1; j <= k; ++j){
			int f = getFather(j);
			printf("%d ", color[j]^flag[f]);
		}printf("\n");*/
		printf("%d\n", ans);
	}return 0;
}