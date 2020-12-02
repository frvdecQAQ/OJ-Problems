#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000010;
int T, n;

int main(){
    scanf("%d", &T);
    int ans;
    while(T--){
        scanf("%d", &n);
        int L = 1;
        int R = 2500;
        while(L < R){
            int mid = (L+R)>>1;
            int now = mid*(mid+1)/2;
            if(n <= now)R = mid;
            else L = mid+1;
        }
        //printf("%d\n", L);
        int ed = L*(L+1)/2;
        if(n == ed-1)ans = L+1;
        else ans = L;
        printf("%d\n", ans);
    }return 0;
}