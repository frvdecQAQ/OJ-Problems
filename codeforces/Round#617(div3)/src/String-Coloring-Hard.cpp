#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

const int maxn = 200010;

int n;
char s[maxn];

int cnt = 0;
int num[maxn];	
int color[maxn];

void add(int x, int index){
	if(cnt == 0 || num[cnt] > x){
		num[++cnt] = x;
		color[index] = cnt;
		return;
	}
	int l = 1, r = cnt;
	while(l < r){
		int mid = (l+r) >> 1;
		if(num[mid] <= x)r = mid;
		else l = mid+1;
	}
	num[r] = x;
	color[index] = r;
	return;
}

int main(){
	scanf("%d", &n);
	scanf("%s", s+1);
	for(int i = 1; i <= n; ++i)add(s[i]-'a', i);
	printf("%d\n", cnt);
	for(int i = 1; i <= n; ++i)printf("%d ", color[i]);
	printf("\n");
	return 0;
}