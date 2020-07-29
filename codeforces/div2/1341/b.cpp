#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int maxn[N];
int flag[N];
void solve()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> maxn[i];
    flag[1] = 0,flag[n] = 0;
    for(int i = 2; i < n; i++)
    {
        if(maxn[i] > maxn[i-1] && maxn[i] > maxn[i+1])
        {
            flag[i] = 1;
        }else{
            flag[i] = 0;
        }
    }
    int resIdx = 1,resVal = 0;
    int curVal = 0;
    for(int i = 1; i <= k; i++) curVal += flag[i];
    if(flag[k]==1) curVal--;
    resVal = curVal;
    for(int i = 2; i + k - 1 <= n; i++)
    {
        if(flag[i]) curVal--;
        if(flag[i+k-2]) curVal++;
        if(resVal < curVal)
        {
            resVal = curVal;
            resIdx = i;
        }
    }
    cout << resVal + 1 << " " << resIdx<< endl;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}