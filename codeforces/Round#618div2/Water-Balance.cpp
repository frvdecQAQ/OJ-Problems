#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 1000010;

int n, x;
stack< pair<int,double> >S;
double ans[maxn];
double tmp;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		tmp = x;
		if(S.empty() || S.top().second < tmp){
			S.push(make_pair(i, x)); 
			continue;
		}
		double sum = 0;
		int la = i;
		while(true){
			pair<int,double>cur = S.top(); S.pop();
			sum = sum+(la-cur.first)*cur.second;
			double ave = (tmp+sum)/(i-cur.first+1);
			la = cur.first;
			if(S.empty() || S.top().second < ave){
				S.push(make_pair(cur.first, ave));
				break;
			}
		}
	}
	int la = n+1;
	while(!S.empty()){
		pair<int,double>cur = S.top(); S.pop();
		for(int i = cur.first; i < la; ++i)ans[i] = cur.second;
		la = cur.first;
	}
	for(int i = 1; i <= n; ++i){
		printf("%.9lf\n", ans[i]);
	}return 0;

}