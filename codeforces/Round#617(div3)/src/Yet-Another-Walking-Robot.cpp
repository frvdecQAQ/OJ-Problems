#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 200010;
int T, n;
char s[maxn];
int lr[maxn], ud[maxn];
map<pair<int,int>, int>M;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		scanf("%s", s+1);
		lr[0] = 0; ud[0] = 0;
		M.clear();
		for(int i = 1; i <= n; ++i){
			lr[i] = lr[i-1] + (s[i] == 'L') - (s[i] == 'R');
			ud[i] = ud[i-1] + (s[i] == 'U') - (s[i] == 'D');
		}
		M[make_pair(lr[0], ud[0])] = 1;
		int ans = -1;
		int ansl = -1, ansr = -1;
		for(int i = 2; i <= n+1; ++i){
			int askLr = lr[i-1];
			int askUd = ud[i-1];
			pair<int,int>tmp = make_pair(askLr, askUd);
			map<pair<int,int>, int>::iterator iter = M.find(tmp);
			if(iter != M.end()){
				int l = iter->second;
				int len = i-l;
				if(ans == -1 || len < ans){
					ans = len;
					ansl = l; ansr = i-1;
				}
			}
			tmp = make_pair(lr[i-1], ud[i-1]);
			M[tmp] = i;
		}
		if(ans == -1)printf("-1\n");
		else printf("%d %d\n", ansl, ansr);
	}return 0;
}