//https://www.acwing.com/problem/content/803/
#include <iostream>
using namespace std;
int lowbit(int x)
{
    return x & -x;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,x;
    cin >> n;
    while(n--)
    {
        cin >> x;
        int cnt = 0;
        while(x) x -= lowbit(x),cnt++;
        cout << cnt << " ";
    }
    cout << endl;
}