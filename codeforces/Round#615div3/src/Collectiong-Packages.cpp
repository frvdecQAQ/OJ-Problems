#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

const int maxn = 1010;

int T, n, cnt;
struct Package{
	int x, y;
}a[maxn];
char s[maxn << 1];

bool cmp(Package i, Package j){
	if(i.x == j.x)return i.y < j.y;
	return i.x < j.x;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)scanf("%d%d", &a[i].x, &a[i].y);
		sort(a+1, a+n+1, cmp);
		cnt = 0;
		int nx = 0, ny = 0;
		bool flag = true;
		for(int i = 1; i <= n; ++i){
			if(a[i].x > nx){
				for(int j = nx; j < a[i].x; ++j){
					s[++cnt] = 'R';
				}nx = a[i].x;
			}
			if(a[i].y >= ny){
				for(int j = ny; j < a[i].y; ++j){
					s[++cnt] = 'U';
				}ny = a[i].y;
			}else{
				flag = false;
				break;
			}
		}
		if(flag){
			printf("YES\n");
			for(int i = 1; i <= cnt; ++i)putchar(s[i]);
			printf("\n");
		}else printf("NO\n");
	}return 0;
}