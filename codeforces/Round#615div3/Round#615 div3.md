# Round#615 div3

#### Collecting Coins:

签到题，不妨假设a<b<c，那么至少需要(c-a)+(c-b)个硬币才可以使三者相等，同时n-(c-a)-(c-b)一定要是3的倍数才满足条件。

#### Collecting Packages：

签到题，由于R比U字典序小，次序显然是每次向R走一步，然后把这一列的包裹都拿了，然后再向R走一步……，将包裹按照x排序，然后模拟以上步骤即可，有拿不到的包裹就不存在合法方案

#### Product of Three Numbers：

签到题，不妨设a<b<c，显然a<b<sqrt(n)，根据本题的数据范围，只需要暴力枚举1……sqrt(n)试除即可

#### MEX maximizing：

签到题，考虑x的完全剩余系{0, 1, ……, x-1}，每个$a_i$实际上对应着完全剩余系的一个元素，对于这个完全剩余系的每个元素k记录有多少个$a_i$对应即可，这若干个$a_i$的取值最优情况下显然是k，k+x，k+2x……，在这种情况，可以快速询问某个数字是否存在。令ans表示当前的mex值，由于mex值随着给的元素数量是单调递增的，每次更新后查询当前ans是否存在，然后ans++直到当前的ans不存在即可

#### Obtain a Permutation：

签到题，可以发现每一列都是独立的。对于某一列，设f[i]表示有多少个数可以通过向上循环移动i次到达正确的位置，而这一列的最小操作次数就是min(n, min{n-f[i]+i})。

#### Three Paths on a Tree：

我采用的DP的做法，比较容易想到，而且转移也是显然的，不再赘述。

题解中用的是另一种做法，这种做法的核心结论是一定存在一组最优解的两个端点是树的直径，剩下的做法就比较显然了，下面证明这个核心结论：

假设选了a，b，c三个点，用dis(i, j)表示i到j的长度，用path(i, j)表示i到j的路径，显然path(a, b)，path(b, c)，path(a, c)三条路径交点有且只有一个，不妨设其为u，**考虑以u为根的树**，显然a，b，c两两之间的LCA都为u，此时答案为dis(a, u)+dis(b, u)+dis(c, u)

考虑树的直径，假设两个端点为x，y，下面分情况讨论：

- path(x, y)经过u，则有dis(x, u)+dis(y, u) = dis(x, y)，又因为dis(a, u)+dis(b, u) = dis(a, b)，由于树的直径的条件可以得到dis(x, y) >= dis(a, b)，则dis(x, u)+dis(y, u)+dis(c, u) >= dis(a, u)+dis(b, u)+dis(c, u)，可以知道选择点集{x, y, c}不会比选择{a, b, c}差
- path(x, y)不经过u，不妨设LCA(x, y) = v，则dis(x, u)+dis(y, u)-2dis(u, v) = dis(x, y)，显然{a, b, c}中至少有两个点和x，y的LCA均为u，不妨设其为a和b，考虑选择点集{x, y, a}，则答案为dis(a, u)+dis(x, u)+dis(y, u)-dis(u, v) = dis(a, u)+dis(x, y)+dis(u, v)，而原答案为dis(a, u)+dis(b, u)+dis(c, u) = dis(a, u)+dis(b, c)，而由树的直径性质可知dis(x, y) >= dis(b, c)，可以得到选择点集{x, y, a}比选择{a, b, c}要更优

综上，可以证明一定存在一个最优解的其中两个点是树的直径端点



