//https://www.acwing.com/problem/content/801/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int q[N];
int s[N];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> q[i];
    int res = 0;
    for(int i = 1,j = 1; i <= n; i++)
    {
        s[q[i]]++;
        while(j <= i && s[q[i]] > 1)        //判断是否存在重复
        {
            s[q[j]]--;
            j++;
        }
        res = max(res,i-j+1);
    }
    cout << res << endl;
}