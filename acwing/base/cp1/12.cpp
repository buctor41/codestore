#include <iostream>
using namespace std;
const int N = 1010;
int s[N][N],n,m,t;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m ;j++)
        {
            cin >> s[i][j];
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }
    while(t--)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1] << endl;
    }
    return 0;
}