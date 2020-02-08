#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

const int maxn = 400010;

int n, x, num;
int ans = 0;
int c = 0;
int vis[maxn];

int main(){
	scanf("%d", &n);
	scanf("%d", &x);
	for(int i = 0; i < x; ++i)vis[i] = 0;
	while(n--){
		scanf("%d", &num);
		num = num%x;
		vis[num]++;
		while(vis[ans] > c){
			++ans;
			if(ans == x){
				++c;
				ans = 0;
			}
		}printf("%d\n", c*x+ans);
	}return 0;
}