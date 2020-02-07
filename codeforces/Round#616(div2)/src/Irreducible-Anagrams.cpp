#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

map<int, int>M;
map<int, int>::iterator iter;

const int maxn = 200010;

char s[maxn];
int L[maxn];
int q, l, r;
int cnt = 0;

void add(int v){
	iter = M.find(v);
	if(iter == M.end() || iter->second == 0){
		++cnt;
		M[v] = 1;
	}else M[v]++;
}

void del(int v){
	iter = M.find(v);
	if(iter->second == 1){
		--cnt;
		M[v] = 0;
	}else M[v]--;
}

int main(){
	scanf("%s", s+1);
	int n = strlen(s+1);
	int lPos = 1;
	for(int i = 1; i <= n; ++i){
		add(s[i]);
		while(cnt > 2 && lPos <= i){
			del(s[lPos]);
			lPos++;
		}
		L[i] = lPos;
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &l, &r);
		if(l == r)printf("Yes\n");
		else if(s[l] != s[r])printf("Yes\n");
		else if(l < L[r])printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}