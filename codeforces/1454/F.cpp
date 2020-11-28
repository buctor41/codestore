#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define int ll

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int maxn = 1e5 + 10;
int logn = 21;
int f1[maxn][logn+1],f2[maxn][logn+1],Logn[logn+1];
void Pre()
{
    Logn[1] = 0;
    Logn[2] = 1;
    for(int i = 3; i < maxn; i++){
        Logn[i] = Logn[i/2] + 1;
    }
}
signed main()
{
    int t = read();
    Pre();
    while(t--){
        int n = read();
        for(int i = 1; i <= n; i++){
            f1[i][0] = read();
            f2[i][0] = f1[i][0];
        }
        for(int j = 1; j <= logn; j++){
            for(int i = 1; i + (1 << j) - 1 <= n; i++){
                f1[i][j] = max(f1[i][j-1],f1[i+(1 << (j-1))][j-1]);
            }
        }
        for(int j = 1; j <= logn; j++){
            for(int i = 1; i + (1 << j) - 1 <= n; i++){
                f2[i][j] = min(f2[i][j-1],f2[i+(1 << (j-1))][j-1]);
            }
        }
        int x,y,z,l=1,r=n;
        bool flag = false;
        while(r-l >= 2){
            //[1,l]   [r,n]  max值
            int s = Logn[l];
            int v1 = max(f1[1][s],f1[l-(1<<s)+1][s]);
            s = Logn[n-r+1];
            int v2 = max(f1[r][s],f1[n-(1<<s)+1][s]);
            if(v1>v2){
                r--;
            }else if(v1 < v2){
                l++;
            }else{
                //l+1   r-1
                //
                int s = Logn[r-l-1];
                int v = min(f[l+1][s],f[r-(1<<s)][s]);

            }
        }
        if(flag){
            printf("YES\n%d %d %d\n",x,y,z);
        }else{
            printf("NO\n");
        }
    }
}



#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define LL long long
#define int long long
#define ull unsigned long long
#define fi first
#define se second
#define pll pair<LL, LL>
#define pii pair<int, int>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define SZ(x) ((int)(x.size()))
#define LC (id<<1)
#define RC (id<<1|1)

constexpr int N = 3e5+9;
constexpr int M =998244353;
#ifdef int
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int INF2 = 0xcfcfcfcfcfcfcfcf;
#else
constexpr int INF = 0x3f3f3f3f;
constexpr int INF2 = 0xcfcfcfcf;
#endif

int t, n;
int a[N];

template<int N, int LOGN> struct ST {

    int f[N][LOGN], Logn[N];

    void init(int* a) {
        Logn[1] = 0;
        Logn[2] = 1;
        for (int i = 3; i <= n; i++)
            Logn[i] = Logn[i / 2] + 1;
        for (int i = 1; i <= n; i++)
            f[i][0] = a[i];
        for (int j = 1; j <= LOGN; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }

    int get(int x, int y) {
        int s = Logn[y - x + 1];
        return min(f[x][s], f[y - (1 << s) + 1][s]);
    }
};
ST<N, 20> st;
int maxi[N];

int check(int s, int l, int r, int x) {
    while (l <= r) {
        int m = (l+r)>>1;
        int v = st.get(s, m);
        if (v == x) return m;
        if (v > x) l = m+1;
        else r = m-1;
    }
    return 0;
}

signed main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        st.init(a);
        for (int i = n; i >= 1; i--) maxi[i] = max(maxi[i+1], a[i]);
        bool flag = false;
        int l = n+1, r = n+1;
        int maxL = 0, maxR = 0;
        for (int i = 1; i <= n-2; i++) {
            maxL = max(maxL, a[i]);
            while (r-1 > i && a[r-1] < maxL) r--;
            while (l-1 > i && a[l-1] <= maxL) {
                maxR = max(maxR, a[l - 1]), l--;
            }
            if (maxR != maxL) continue;
            int m = check(i+1, max(i+1, l-1), r-2, maxL);
            if (m) {
                cout << "YES\n";
                cout << i << " " << m-i << " " << n-m << "\n";
                flag = true;
                break;
            }
        }
        if (!flag) cout << "NO\n";
    }
    return 0;
}