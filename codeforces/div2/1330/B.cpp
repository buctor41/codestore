/*
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int st[N];
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(st,0,sizeof(int)*n);
        for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
        set<int> pb;
        bool flag = true;
        int minV = a[1],maxV = a[1];
        for(int i = 1;i  < n; i++){
            int v = a[i];
            st[v]++;
            if(st[v] > 1) break;
            minV = min(v,minV);
            maxV = max(v,maxV);
            if(minV==1 && maxV==i){
                pb.insert(i);
            }
        }
        if(pb.size()){
            memset(st,0,sizeof(int)*n);
            vector<pair<int,int>> res;
            minV = a[n],maxV = a[n];
            for(int i = n; i > 1; i--){
                int v = a[i];
                st[v]++;
                if(st[v] > 1) break;
                minV = min(v,minV);
                maxV = max(v,maxV);
                if(minV==1 && maxV==(n-i+1)){
                    if(pb.count(i-1)==1){
                        flag = true;
                        res.push_back({i-1,n-i+1});
                    }
                }
            }
            if(flag){
                cout << res.size() <<endl;
                for(int i = 0; i < res.size(); i++){
                    int x = res[i].first,y = res[i].second;
                    cout << x << " " << y << endl;
                }
            }
        }
        if(!flag) puts("0");
    }
    return 0;
}
*/
#pragma GCC optimize(3)
#pragma G++ optimize(3)

#include <bits/stdc++.h>


#define int long long
#define LL long long
#define pii pair<LL, LL>
#define pdd pair<double, double>
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

// #define DEBUG 1  //调试开关
struct IO
{
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf) {}
    ~IO()
    {
        fwrite(pbuf, 1, pp - pbuf, stdout);
    }
#endif
    inline char gc()
    {
#if DEBUG  //调试，可显示字符
        return getchar();
#endif
        if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }
    inline bool blank(char ch)
    {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    template <class T>
    inline void read(T &x)
    {
        double tmp = 1;
        bool sign = 0;
        x = 0;
        char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign) x = -x;
    }
    inline void read(char *s)
    {
        char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
    }
    inline void read(char &c)
    {
        for (c = gc(); blank(c); c = gc())
            ;
    }
    inline void push(const char &c)
    {
#if DEBUG  //调试，可显示字符
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }
    template <class T>
    inline void write(T x)
    {
        if (x < 0) x = -x, push('-');  // 负数输出
        static T sta[35];
        T top = 0;
        do
        {
            sta[top++] = x % 10, x /= 10;
        }
        while (x);
        while (top) push(sta[--top] + '0');
    }
    template <class T>
    inline void write(T x, char lastChar)
    {
        write(x), push(lastChar);
    }
} io;

constexpr int N = 2e5+5;
constexpr int M = 998244353;
constexpr double eps = 1e-6;

int t, n, x;
int a[N];
int sum[N];
int vis[N];

signed main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum[i] = sum[i-1] + a[i];
            vis[i] = 0;
        }
        int lmax = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[a[i]]) break;
            vis[a[i]] = 1;
            lmax = i;
        }
        for (int i = 1; i <= n; i++) vis[i] = 0;
        int rmax = 0;
        for (int i = n; i>= 1; i--)
        {
            if (vis[a[i]]) break;
            vis[a[i]] = 1;
            rmax = n+1-i;
        }
        vector<pii> ans;
        for (int l1 = 1; l1 < n && l1 <= lmax; l1++)
        {
            int l2 = n - l1;
            //cout << sum[l1] << "  " << sum[n] - sum[l1] << endl;
            if (sum[l1] == (l1+1) * l1 / 2 && sum[n] - sum[l1] == (l2+1) * l2 / 2 && l2 <= rmax)
                ans.push_back({l1, l2});
        }
        cout << ans.size() << endl;
        for (auto& p: ans)
        {
            cout << p.fi << " " << p.se << endl;
        }
    }
    return 0;
}
