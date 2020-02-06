#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

const int maxn = 3510;

int T, n, m, k;
int a[maxn];

struct Tmp{
	int num;
	int first;
}ans[maxn];

bool cmp(Tmp a, Tmp b){
	return a.num < b.num;
}


int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &m, &k);
		--m; k = min(k, m);
		for(int i = 1; i <= n; ++i)scanf("%d", &a[i]);
		for(int i = 0; i <= m; ++i){
			ans[i].first = i;
			ans[i].num = max(a[1+i], a[n-(m-i)]);
		}
		sort(ans, ans+m+1, cmp);
		int Ans = -1;
		for(int i = 0; i <= k; ++i){
			for(int j = 0; j <= m; ++j){
				int first = ans[j].first+1;
				int last = m-ans[j].first+1;
				if(first <= i)continue;
				if(last <= k-i)continue;
				if(ans[j].num > Ans){
					Ans = ans[j].num;
				}
				break;
			}
		}
		printf("%d\n", Ans);
	}return 0;
}