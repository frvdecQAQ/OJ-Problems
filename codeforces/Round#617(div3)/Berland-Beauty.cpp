#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 5010;
const int inf = 0x7fffffff;

int n, u, v, m;

int cnt = 1;
int h[maxn];
int fa[maxn], faEdge[maxn];
int nxt[maxn << 1];
int to[maxn << 1];
int edgeValue[maxn];
int depth[maxn];

struct Passengers{
	int u, v, w;
}tmp[maxn];

bool cmp(Passengers i, Passengers j){
	return i.w > j.w;
}

void add(int u, int v){
	++cnt;
	nxt[cnt] = h[u]; to[cnt] = v; h[u] = cnt;
	++cnt;
	nxt[cnt] = h[v]; to[cnt] = u; h[v] = cnt;
}

void getDepth(int u, int d){
	depth[u] = d;
	for(int i = h[u]; i; i = nxt[i]){
		int v = to[i];
		if(v == fa[u])continue;
		fa[v] = u; faEdge[v] = i;
		getDepth(v, d+1);
	}return;
}

bool getJump(int u, int v, int w){
	bool flag = false;
	if(depth[u] < depth[v])swap(u, v);
	while(depth[u] > depth[v]){
		if(edgeValue[faEdge[u] >> 1] <= w){
			edgeValue[faEdge[u] >> 1] = w;
			flag = true;
		}
		u = fa[u];
	}
	while(u != v){
		if(edgeValue[faEdge[u] >> 1] <= w){
			edgeValue[faEdge[u] >> 1] = w;
			flag = true;
		}
		u = fa[u];
		if(edgeValue[faEdge[v] >> 1] <= w){
			edgeValue[faEdge[v] >> 1] = w;
			flag = true;
		}
		v = fa[v];
	}return flag;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		edgeValue[i] = 1;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	getDepth(1, 0);
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		scanf("%d%d%d", &tmp[i].u, &tmp[i].v, &tmp[i].w);
	}
	sort(tmp, tmp+m, cmp);
	bool ansFlag = true;
	for(int i = 0; i < m; ++i){
		if(!getJump(tmp[i].u, tmp[i].v, tmp[i].w)){
			ansFlag = false;
		}
	}
	if(ansFlag){
		for(int i = 1; i < n; ++i)printf("%d ",edgeValue[i]);
		printf("\n");
	}else printf("-1\n");
	return 0;

}