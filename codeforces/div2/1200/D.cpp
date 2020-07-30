#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize(2)
#pragma G++ optimize(2)

/*  Even though these might be more useful as long doubles, POSIX requires
    that they be double-precision literals.                                   */
#define M_E         2.71828182845904523536028747135266250   /* e              */
#define M_LOG2E     1.44269504088896340735992468100189214   /* log2(e)        */
#define M_LOG10E    0.434294481903251827651128918916605082  /* log10(e)       */
#define M_LN2       0.693147180559945309417232121458176568  /* loge(2)        */
#define M_LN10      2.30258509299404568401799145468436421   /* loge(10)       */
#define M_PI        3.14159265358979323846264338327950288   /* pi             */
#define M_PI_2      1.57079632679489661923132169163975144   /* pi/2           */
#define M_PI_4      0.785398163397448309615660845819875721  /* pi/4           */
#define M_1_PI      0.318309886183790671537767526745028724  /* 1/pi           */
#define M_2_PI      0.636619772367581343075535053490057448  /* 2/pi           */
#define M_2_SQRTPI  1.12837916709551257389615890312154517   /* 2/sqrt(pi)     */
#define M_SQRT2     1.41421356237309504880168872420969808   /* sqrt(2)        */
#define M_SQRT1_2   0.707106781186547524400844362104849039  /* 1/sqrt(2)      */

#define MAXFLOAT    0x1.fffffep+127f

#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>

#define LL long long
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<LL, LL>
#define pdd pair<double, double>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define length(p1, p2) ((p1.fi-p2.fi)*(p1.fi-p2.fi)+(p1.se-p2.se)*(p1.se-p2.se))
#define ith(state, i) (state & (1 << i)) 

using namespace std;

class PrimeSelector {public: bool* prime; set<int> primes; int n; PrimeSelector(bool* prime, int n): n(n), prime(prime) { memset(prime, 1, sizeof(bool)*(n+1)); prime[0] = prime[1] = false; for (int i = 1; i * i <= n; i++) { if (!prime[i]) continue; for (int j = i * i; j <= n; j += i) prime[j] = false; } for (int i = 2; i <= n; i++) if (prime[i]) primes.insert(i); } };
LL kpow(LL a, LL b) { LL c = 1; while (b) { if (b & 1) c = c * a; a = a * a; b >>= 1; } return c;}
LL kpow(LL a, LL b, LL mod) { LL c = 1 % mod; while (b) { if (b & 1) c = c * a % mod; a = a * a % mod; } return c;}
LL rev(LL a, LL mod) { return kpow(a, mod-2, mod); }
map<LL, LL> splitPrime(LL x, bool* prime) { map<LL, LL> res; for (int i = 2; i * i <= x; i++) { if (!prime[i]) continue; while (x % i == 0) res[i]++, x /= i; if (res[i] == 0) res.erase(i); } if (x > 1) res[x] = 1; return res; }
map<LL, LL> splitPrime(LL x, set<int>& prime) { map<LL, LL> res; for (auto i: prime) { if (i * i > x) break; while (x % i == 0) res[i]++, x /= i; if (res[i] == 0) res.erase(i); } if (x > 1) res[x] = 1; return res; }
map<LL, LL> mul(const map<LL, LL>& m1, const map<LL, LL>& m2) { map<LL, LL> res; for (auto& p: m1) res[p.fi] = p.se; for (auto& p: m2) { res[p.fi] += p.se; if (res[p.fi] == 0) res.erase(p.fi); } return res; }
map<LL, LL> rev(map<LL, LL> m) { map<LL, LL> res; for (auto& p: m) res[p.fi] = -p.se; return res; }
LL m2L(map<LL, LL> m) { LL res = 1; for (auto& p: m) res *= kpow(p.fi, p.se); return res; }
#define W 1000000000LL
vector<LL> n2B(LL n) { vector<LL> res; if (n == 0) return {0LL};  while (n) { res.push_back(n % W); n /= W; } reverse(res.begin(), res.end()); return res; }
void simple(vector<LL>& res) { while (!res.empty() && res.back() == 0LL) res.pop_back(); if (res.empty()) res.push_back(0LL); }
vector<LL> add(const vector<LL>& b1, const vector<LL>& b2) { vector<LL> res; res.reserve(max(b1.size(), b1.size())+1); LL up = 0LL; int i = b1.size()-1, j = b2.size()-1; while (i >= 0 && j >= 0) { LL b = b1[i--] + b2[j--] + up; res.push_back(b % W); up = b / W; } while (i >= 0) { LL b = b1[i--] + up; res.push_back(b % W); up = b / W; } while (j >= 0) { LL b = b2[j--] + up; res.push_back(b % W); up = b / W; } if (up) res.push_back(up); simple(res); reverse(res.begin(), res.end()); return res; }
vector<LL> mul(const vector<LL>& b1, LL i) { vector<LL> res; res.reserve(b1.size()+1); LL up = 0; for (int j = b1.size()-1; j >= 0; j--) { LL b = b1[j] * i + up; res.push_back(b % W); up = b / W; } if (up) res.push_back(up); simple(res); reverse(res.begin(), res.end()); return res; }
void shift(vector<LL>& b1, LL i) { if (b1.size() == 1 && b1[0] == 0LL) return; while (i--) { b1.push_back(0); } }
vector<LL> mul(const vector<LL>& b1, const vector<LL>& b2) { if (b1.size() < b2.size()) return mul(b2, b1); vector<LL> res; res.reserve(b1.size()+b2.size()+1); res.push_back(0); if (b2.size() == 1 && b2[0] == 0) return res; int shi = 0; for (int j = b2.size()-1; j >= 0; j--) { vector<LL> r = mul(b1, b2[j]); shift(r, shi++); res = add(res, r); } return res; }
vector<LL> m2B(const map<LL, LL>& m) { if (m.empty()) return {1}; vector<LL> res; res.reserve(100); res.push_back(1); for (auto& p: m) { vector<LL> r = n2B(p.fi); for (int i = 0; i < p.se-1; i++) r = mul(r, n2B(p.fi)); res = mul(res, r); } return res; }
struct DSU { vector<int> par; vector<int> sz; int n; DSU(int n) : par(n+1), sz(n+1), n(n) { for (int i = 0; i <= n; i++) sz[i] = 1, par[i] = i; } int find(int x) { if (x == par[x]) return x; return par[x] = find(par[x]); } void uni(int x, int y) { int px = find(x), py = find(y); if (px == py) return; if (sz[px] < sz[py]) return uni(py, px); par[py] = px, sz[px] += sz[py]; } };
template <class T> struct VHash { size_t operator () (const vector<T>& v) const { size_t res = 0; for (T i: v) res ^= i; return res; } };
struct SHash { LL* presum; LL* po; LL seed; LL mod; SHash(LL seed, LL mod, LL* presum, LL* po): seed(seed), mod(mod), presum(presum), po(po) {} void load(const string& s) { po[0] = 1; for (int i = 1; i <= (int)s.size(); i++) { presum[i] = (presum[i-1] * seed + s[i-1]) % mod; po[i] = po[i-1] * seed % mod; } } LL get(int i, int j) { if (i > j) return 0; return (presum[j] - presum[i-1] * po[j-i+1] % mod + mod) % mod; } };
struct SHash2 { LL* presum; LL* po; LL seed; SHash2(LL seed, LL* presum, LL* po): seed(seed), presum(presum), po(po) {} void load(const string& s) { po[0] = 1; for (int i = 1; i <= (int)s.size(); i++) { presum[i] = (presum[i-1] * seed + s[i-1]) & 0xFFFFFFFF; po[i] = (po[i-1] * seed) & 0xFFFFFFFF; } } LL get(int i, int j) { if (i > j) return 0; return (presum[j] - ((presum[i-1] * po[j-i+1]) & 0xFFFFFFFF) + 0xFFFFFFFF) & 0xFFFFFFFF; } };
struct TrieNode { int next[26]; int done; };
struct TrieTree { TrieNode* nodes; int cnt = 0; char base; TrieTree(TrieNode* nodes, char base='a') : nodes(nodes), cnt(0), base(base) {} void add(const string& s) { int p = 0; for (char c: s) { if (!nodes[p].next[c-base]) nodes[p].next[c-base] = ++cnt; p = nodes[p].next[c-base]; } nodes[p].done++; } int count(const string& s) { int res = 0, p = 0; for (char c: s) { res += nodes[p].done; if (!nodes[p].next[c-base]) return res; p = nodes[p].next[c-base]; } res += nodes[p].done; return res; } };
struct BinNode { int next[2]; int done; };
struct BinTree { BinNode* nodes; int maxn = 31; int cnt = 0; BinTree(BinNode* nodes, int maxn) : nodes(nodes), maxn(maxn), cnt(0) {} void add(LL l) { LL p = 0; for (int j = maxn; j >= 0; j--) { int b = (l >> j) & 1; if (!nodes[p].next[b]) nodes[p].next[b] = ++cnt; p = nodes[p].next[b]; } } LL maxXor(LL x) { LL res = 0; int p = 0; for (int j = maxn; j >= 0; j--) { res <<= 1; LL b = (x >> j) & 1; if (nodes[p].next[1^b]) p = nodes[p].next[1^b], res |= 1^b; else p = nodes[p].next[b], res |= b;  } return res; } } ;
int minResp(const string& s) { int n = s.size(); string ss = s + s; int i = 0, j = 1; while (i < n && j < n) { int k = 0; while (k < n) { if (ss[i+k] != ss[j+k]) break; k++; } if (k == n) break; if (ss[i+k] < ss[j+k]) { j = j+k+1; if (i == j) j++; } else { i = i+k+1; if (i == j) i++; } } return min(i, j); }
struct BIT { LL* c; int n; BIT(LL* c, int n): c(c), n(n) {} int lowbit(int x) { return x&-x; } void add(int x, LL v) { for (int i = x; i <= n; i += lowbit(i)) c[i] += v; } LL sum(int x) { LL res = 0; for (int i = x; i; i -= lowbit(i)) res += c[i]; return res; } };
struct BIT2 { LL* C; int n, m; BIT2(LL* C, int n, int m): C(C), n(n), m(m) {} int lowbit(int x) { return x&-x; } void add(int r, int c, LL v) { for (int i = r; i <= n; i += lowbit(i)) for (int j = c; j <= m; j += lowbit(j)) C[i*(m+1)+j] += v; } LL sum(int r, int c) { LL res = 0; for (int i = r; i; i -= lowbit(i)) for (int j = c; j; j -= lowbit(j)) res += C[i*(m+1)+j]; return res; } };


#define MAXN 2005
#define eps 1e-10

int a[MAXN][MAXN];
int n, k;
LL C[MAXN*MAXN];

int main() {
    fastio;
    cin >> n >> k;
    BIT2 bit(C, n+1, n+1);
    char c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (c == 'B') a[i][j] = 1;
        }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = n+1, r = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j])
                l = min(l, j), r = max(r, j);
        }
        //cout << l << " " << r << endl;
        if (r - l + 1 <= k && r - l + 1 > 0) {
            // r: [max(1, i-k+1), i] c: [max(1, r-k+1), l]
            int r1 = max(1, i-k+1), r2 = i;
            int c1 = max(1, r-k+1), c2 = l;
            //cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
            bit.add(r1, c1, 1);
            bit.add(r1, c2+1, -1);
            bit.add(r2+1, c1, -1);
            bit.add(r2+1, c2+1, 1);
        }
        if (r < l) ans++;
    }
    for (int j = 1; j <= n; j++) {
        int u = n+1, d = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i][j])
                u = min(u, i), d = max(d, i);
        }
        if (d - u + 1 <= k && d - u + 1 > 0) {
            // r: [max(1, d-k+1), u] c: [max(1, j-k+1), j]
            int r1 = max(1, d-k+1), r2 = u;
            int c1 = max(1, j-k+1), c2 = j;
            //cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
            bit.add(r1, c1, 1);
            bit.add(r1, c2+1, -1);
            bit.add(r2+1, c1, -1);
            bit.add(r2+1, c2+1, 1);
        }
        if (d < u) ans++;
    }
    LL maxi = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            maxi = max(maxi, bit.sum(i, j));
        }
    }
    cout << ans + maxi << endl;
    return 0;
}