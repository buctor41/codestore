#include <bits/stdc++.h>
using namespace std;
int len(int n)
{
    int cnt = 0;
    while(n){
        n = n >> 1;
        cnt++;
    }
    return cnt;
}
int findZero(int n)
{
    int sl = len(n);
    for(int i = sl - 1; i >= 0; i--){
        if(((n>>i)&1)==0) return i + 1;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> res;
    if(findZero(n)==-1){
        cout << 0 << endl;
    }else{
        while(cnt <= 40)
        {
            if(cnt%2==0)
            {
                int v = findZero(n);
                n  = n ^ (int)(pow(2,v)-1);
                res.push_back(v);
            }else{
                n += 1;
            }
            int v = findZero(n);
            cnt++;
            if(v==-1){
                break;
            }
        }
        cout << cnt << endl;
        for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
}
