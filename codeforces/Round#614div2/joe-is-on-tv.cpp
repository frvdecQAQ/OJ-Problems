#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int n;

int main(){
	scanf("%d", &n);
	double ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += ((double)(1)/(double)(i));
	}
	printf("%.12lf\n", ans);
	return 0;

}