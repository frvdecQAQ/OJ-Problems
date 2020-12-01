#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

int T, n, x;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		int ans = 0;
		int sum = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%d", &x);
			if(x == 0){
				++ans;
				x = 1;
			}
			sum += x;
		}
		if(sum != 0)printf("%d\n", ans);
		else printf("%d\n", ans+1);
	}return 0;
}