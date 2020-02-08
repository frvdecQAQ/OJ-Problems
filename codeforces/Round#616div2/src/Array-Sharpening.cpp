#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

const int maxn = 300010;

int T, n;
int a[maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)scanf("%d", &a[i]);
		bool ansFlag = true;
		int l = 1, r = n;
		for(int i = 1; i <= n; ++i){
			int Lmin = n-i;
			int Rmin = i-1;
			if(Lmin <= Rmin){
				if(a[i] < Lmin){ansFlag = false; break;}
				if(a[i] < Rmin){r = i-1;}
			}else{
				if(a[i] < Rmin){ansFlag = false; break;}
				if(a[i] < Lmin){l = i+1;}
			}
			if(l > r){ansFlag = false; break;}
		}
		if(ansFlag)printf("YES\n");
		else printf("NO\n");
	}return 0;
}