#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 2010;

int t, n;
int a[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int oddSum = 0, evenSum = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
			if(a[i]&1)oddSum++;
			else evenSum++;
		}
		if(oddSum == 0)printf("NO\n");
		else if(evenSum == 0){
			if(n&1)printf("YES\n");
			else printf("NO\n");
		}else printf("YES\n");
	}return 0;
}