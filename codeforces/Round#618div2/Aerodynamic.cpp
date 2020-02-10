#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100010;

int n;

struct Point{
	int x, y;
}p[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	if(n&1)printf("NO\n");
	else{
		int lim = (n>>1);
		int checkX = p[1].x+p[1+lim].x;
		int checkY = p[1].y+p[1+lim].y;
		bool flag = true;
		for(int i = 2; i <= lim; ++i){
			if(p[i].x+p[i+lim].x != checkX){flag = false; break;}
			if(p[i].y+p[i+lim].y != checkY){flag = false; break;}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}return 0;
}