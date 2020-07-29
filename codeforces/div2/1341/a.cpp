#include <iostream>
using namespace std;
void solve()
{
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    int vmin = (a - b) * n;
    int vmax = (a + b) * n;
    int fmin = c - d;
    int fmax = c + d;
    if(vmax < fmin || vmin > fmax)
    {
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
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