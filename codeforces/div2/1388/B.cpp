#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t,n,cnt;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        string s;
        if(n%4==0) cnt = n / 4;
        else cnt = n / 4 + 1;
        for(int i = 0; i < n - cnt; i++) s+="9";
        for(int i = 0; i < cnt; i++) s+="8";
        cout << s <<endl;
    }   
    return 0;
}

