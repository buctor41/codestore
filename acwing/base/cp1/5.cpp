//二分
//https://www.acwing.com/problem/content/791/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int q[N],n,t,k;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> t;
    for(int i = 1; i <= n; i++) cin >> q[i];
    while(t--)
    {
        cin >> k;
        int l = 1, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(q[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if(q[l]!=k) cout << "-1 -1" << endl;
        else
        {
            cout << l - 1 << " ";
            int l = 1, r = n;
            while(l < r)
            {
                int mid = l + r + 1 >> 1;
                if(q[mid] <= k) l = mid;
                else r = mid - 1; 
            }
            cout << l - 1 << endl;
        }
        
    }
}