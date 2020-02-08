#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

const int maxn = 3010;

int T, n;
char s[maxn];

int main(){
	scanf("%d\n", &T);
	while(T--){
		scanf("%d", &n);
		scanf("%s", s+1);
		int pos1 = -1, pos2 = -1;
		for(int i = 1; i <= n; ++i){
			int num = s[i]-'0';
			if(num&1){
				if(pos1 == -1)pos1 = i;
				else if(pos2 == -1){
					pos2 = i;
					break;
				}
			}
		}
		if(pos2 == -1)printf("-1\n");
		else{
			for(int i = pos1; i <= pos2; ++i){
				if(i != pos1 && i != pos2){
					int num = s[i]-'0';
					if(num&1)continue;
				}putchar(s[i]);
			}printf("\n");
		}
	}return 0;
}