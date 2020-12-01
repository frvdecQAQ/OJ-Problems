#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 110;

int T, n;
char s[maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%s", s+1);
		n = strlen(s+1);
		int l = -1, r = -1;
		for(int i = 1; i <= n; ++i){
			if(s[i] == '1'){
				if(l == -1)l = i;
				r = i;
			}
		}
		if(l == -1){
			printf("0\n");
			continue;
		}
		int ans = 0;
		for(int i = l; i <= r; ++i){
			if(s[i] == '0')ans++;
		}printf("%d\n", ans);
	}return 0;
}