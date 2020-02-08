#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

int T, n;

int getAns(int n){
	if(n < 10)return n;
	int tmp = (int)(n/10);
	return tmp*10+getAns(n-tmp*9);
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		int ans = getAns(n);
		printf("%d\n", ans);
	}return 0;
}