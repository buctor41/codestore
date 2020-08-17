#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define CYL cout << "YES" << endl;
#define CNL cout << "NO" << endl;
const int N = 2e5 + 10;
char s[N];
int t;
bool check(int n,int w){
    int st = n + 1;
    while(1){
        bool v = false;
        int nx;
        for(int i = st - 1; i >= st - w && i >= 1; i--){
            if(s[i]=='R'){
                v = true;
                nx = i;
            }
        }
        if(v){
            if(nx-w <= 0) return true;
            st = nx;
        }else break;
    }
    return false;
}
int main()
{
    fastio;
    cin >> t;
    while(t--){
        memset(s,'\0',sizeof(char)*N);
        cin >> s+1;
        int n = strlen(s+1);
        int l = 1, r = n + 1;
        while(l < r){
            int mid = l + r >> 1;
            if(check(n,mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
}