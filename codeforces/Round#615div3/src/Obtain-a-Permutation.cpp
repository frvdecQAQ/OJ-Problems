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

int n, m;
int a[maxn];
int dis[maxn];
int ans = 0;

int getId(int x, int y){
	return x*m+y;
}

int main(){
	scanf("%d%d", &n, &m);
	int lim = n*m;
	for(int i = 0; i < lim; ++i)scanf("%d", &a[i]);
	for(int i = 0; i < m; ++i){
		int judge = (i+1)%m;
		for(int j = 0; j < n; ++j)dis[j] = 0;
		for(int j = 0; j < n; ++j){
			int cur = getId(j, i);
			if(a[cur]%m != judge)continue;
			else{
				int k = (a[cur]-i-1)/m;
				if(k >= n)continue;
				int d = j-k;
				if(d < 0)d += n;
				dis[d]++;
			}
		}
		int minAns = n;
		for(int j = 0; j < n; ++j){
			int tmp = n-dis[j]+j;
			if(tmp < minAns)minAns = tmp;
		}
		ans += minAns;
	}printf("%d\n", ans);
	return 0;
}