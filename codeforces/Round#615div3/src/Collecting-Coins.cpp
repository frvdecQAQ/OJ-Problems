#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

int T;
int a, b, c, n;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d", &a, &b, &c, &n);
		int m = max(max(a, b), c);
		int k = 3*m-a-b-c;
		n -= k;
		if(n >= 0 && n%3 == 0)printf("YES\n");
		else printf("NO\n");
	}return 0;
}