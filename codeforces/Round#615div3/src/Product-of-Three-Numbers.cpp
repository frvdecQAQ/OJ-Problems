#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int T, n;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		int sqr = (int)(sqrt(n));
		int a = -1, b = -1;
		for(int i = 2; i <= sqr; ++i){
			if(n%i == 0){
				n /= i;
				if(a == -1)a = i;
				else if(b == -1){
					b = i;
					break;
				}
			}
		}
		if(a == n || b == n || a == -1 || b == -1)printf("NO\n");
		else{
			printf("YES\n");
			printf("%d %d %d\n", a, b, n);
		}
	}return 0;
}