//https://www.acwing.com/problem/content/802/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N],b[N],n,m,x;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    for(int i = 1, j = m; i <= n; i++)
    {
        while( j > 1 && (a[i]+b[j]) > x) j--;
        if(a[i]+b[j] == x){
            cout << i - 1 << " " << j - 1<< endl;
            break;
        }
    }
}