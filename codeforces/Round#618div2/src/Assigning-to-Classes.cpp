#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 200010;

int T, n;
int a[maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		n <<= 1;
		for(int i = 1; i <= n; ++i)scanf("%d", &a[i]);
		sort(a+1, a+n+1);
		printf("%d\n", a[(n>>1)+1]-a[n>>1]);
	}return 0;
}