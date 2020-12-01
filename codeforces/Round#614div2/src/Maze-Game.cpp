#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100010;

int n, q, x, y;

bool c[2][maxn];
int c1 = 0, c2 = 0, c3 = 0;

int main(){
	scanf("%d", &n);
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &x, &y);
		--x;
		if(c[x][y]){
			c[x][y] = false;
			if(c[x^1][y]){
				c2--;
			}
			if(y > 1 && c[x^1][y-1]){
				if(x == 1)c1--;
				else c3--;
			}
			if(y < n && c[x^1][y+1]){
				if(x == 1)c3--;
				else c1--;
			}
		}else{
			c[x][y] = true;
			if(c[x^1][y]){
				c2++;
			}
			if(y > 1 && c[x^1][y-1]){
				if(x == 1)c1++;
				else c3++;
			}
			if(y < n && c[x^1][y+1]){
				if(x == 1)c3++;
				else c1++;
			}
		}
		if(c1 || c2 || c3)printf("NO\n");
		else printf("YES\n");
	}return 0;
}