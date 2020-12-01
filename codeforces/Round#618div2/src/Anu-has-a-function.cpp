#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100010;
std::vector<int>v;

int n;
int a[maxn];
int num[35];
int ans;
int st;

void fj(int x){
	int cur = 0;
	while(x){
		if(x&1)num[cur]++;
		cur++;
		x >>= 1;
	}return;
}

int main(){
	scanf("%d", &n);
	ans = -1; v.clear();
	for(int i = 1; i <= n; ++i)scanf("%d", &a[i]);
	for(int i = 0; i < 32; ++i)num[i] = 0;
	for(int i = 1; i <= n; ++i)fj(a[i]);
	for(int i = 0; i < 32; ++i)if(num[i] == 1)v.push_back(i);
	int sz = v.size();
	for(int i = 1; i <= n; ++i){
		int tmp = 0;
		for(int j = 0; j < sz; ++j){
			int cur = v[j];
			if((a[i]>>cur)&1)tmp += (1<<cur);
		}
		if(tmp > ans){
			ans = tmp;
			st = i;
		}
	}
	printf("%d", a[st]);
	for(int i = 1; i <= n; ++i){
		if(i == st)continue;
		printf(" %d", a[i]);
	}printf("\n");
	return 0;
}