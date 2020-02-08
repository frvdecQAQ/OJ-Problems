#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

const int maxn = 200010;

int n, a, b, k;
int h[maxn];
priority_queue<int>Q;
int ans = 0;

int main(){
	scanf("%d%d%d%d", &n, &a, &b, &k);
	int mod = a+b;
	for(int i = 0; i < n; ++i)scanf("%d", &h[i]);
	for(int i = 0; i < n; ++i){
		int tmp = h[i]%mod;
		if(tmp == 0)tmp = mod;
		if(tmp <= a){ans++; continue;}
		if(tmp%a == 0)tmp = tmp/a-1;
		else tmp = tmp/a;
		Q.push(-tmp);
	}
	while(!Q.empty()){
		int top = Q.top();
		Q.pop();
		if(k+top >= 0){
			ans++;
			k += top;
		}
		else {break;}
	}
	printf("%d\n", ans);
	return 0;
}