#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> PIII;
const int N = 1e5 + 10,M = 2 * N;
PIII s[M];
int p[N];
int n,m;
//思路:对所有边进行排序，然后从小到大进行遍历，如果边的两点不在同一个集合则将两点连起来(并查集)
//最后判断是否连接了n个点，即n-1条边
int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0,a,b,c; i < m; i++){
        scanf("%d%d%d",&a,&b,&c);
        s[i] = {c,{a,b}};
    }
    sort(s,s+m);
    for(int i = 1; i <= n; i++) p[i] = i;
    int res = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        auto t = s[i];
        int a = t.second.first,b = t.second.second,c = t.first;
        a = find(a),b = find(b);
        if(a!=b){
            p[a] = b;
            res += c;
            cnt++;
        }
    }
    if(cnt < n - 1) puts("impossible");
    else cout << res << endl;
    return 0;
}