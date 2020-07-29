//https://www.acwing.com/problem/content/800/
#include <iostream>
using namespace std;
const int N = 1010;
int s[N][N],n,m,q;
void insert(int x1,int y1,int x2,int y2,int v)
{
    s[x1][y1] += v;
    s[x2+1][y1] -= v;
    s[x1][y2+1] -= v;
    s[x2+1][y2+1] += v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 1,v; i <= n; i++){
        for(int j = 1; j<= m; j++)
        {
            cin >> v;
            insert(i,j,i,j,v);
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2,v;
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        insert(x1,y1,x2,y2,v);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
            cout << s[i][j] << " "; 
        }
        cout << endl;
    }
}