#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1010;
int T;
char s[maxn];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        printf("%d\n", (int)(strlen(s)));
    }return 0;
}