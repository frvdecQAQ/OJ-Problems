#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 2000010;
const int maxf = 90010;
const int maxm = 310;

int n, m, q;
struct query{
	int x, y, c;
	int add, del;
}a[maxn];
int f[maxf];
int c[maxm][maxm];

int getId(int x, int y){
	return x*m+y;
}

int getFa(int x){
	return f[x] == x?x: f[x]=getFa(f[x]);
}

int getMerge(int x, int y, int xx, int yy){
	if(c[x][y] != c[xx][yy])return 0;
	int uf = getFa(getId(x, y));
	int vf = getFa(getId(xx, yy));
	if(uf == vf)return 0;
	f[uf] = vf;
	return 1;
}

int main(){
	scanf("%d%d%d", &n, &m, &q);	
	for(int i = 1; i <= q; ++i){
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
		a[i].add = -1;
		a[i].del = -1;
		a[i].x--;
		a[i].y--;
	}
	for(int i = 0; i < n*m; ++i)f[i] = i;
	for(int i = 0; i < n; ++i)for(int j = 0; j < m; ++j)c[i][j] = 0;
	for(int i = 1; i <= q; ++i){
		int x = a[i].x;
		int y = a[i].y;
		int val = a[i].c;
		if(a[i].c != c[x][y])a[i].c = c[x][y];
		else a[i].c = -1;
		if(a[i].c == -1)continue;
		c[x][y] = val;
		f[getId(x, y)] = getId(x, y);
		if(x > 0)a[i].del += getMerge(x, y, x-1, y);
		if(y > 0)a[i].del += getMerge(x, y, x, y-1);
		if(x < n-1)a[i].del += getMerge(x, y, x+1, y);
		if(y < m-1)a[i].del += getMerge(x, y, x, y+1);
	}
	for(int i = 0; i < n*m; ++i)f[i] = i;
	for(int i = 0; i < n; ++i)for(int j = 0; j < m; ++j){
		if(i > 0)getMerge(i, j, i-1, j);
		if(j > 0)getMerge(i, j, i, j-1);
		if(i < n-1)getMerge(i, j, i+1, j);
		if(j < m-1)getMerge(i, j, i, j+1);
	}
	for(int i = q; i >= 1; --i){
		if(a[i].c == -1)continue;
		int x = a[i].x;
		int y = a[i].y;
		int val = a[i].c;
		c[x][y] = val;
		f[getId(x, y)] = getId(x, y);
		if(x > 0)a[i].add += getMerge(x, y, x-1, y);
		if(y > 0)a[i].add += getMerge(x, y, x, y-1);
		if(x < n-1)a[i].add += getMerge(x, y, x+1, y);
		if(y < m-1)a[i].add += getMerge(x, y, x, y+1);
	}
	int ans = 1;
	for(int i = 1; i <= q; ++i){
		ans = ans-a[i].del;
		ans = ans+a[i].add;
		printf("%d\n", ans);
	}
	return 0;
}