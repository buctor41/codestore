#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
char s[N];
#define ll long long
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(s,0,sizeof(char)*N);
        int n;
        scanf("%d\n%s",&n,s);
        for(int i = 0; i < n; i++) a[i] = s[i] - '0' - 1;
        unordered_map<int,int> mp;
        mp[0] = 1;
        ll count = 0, pre = 0;
        for(int i = 0; i < n; i++){
            pre += a[i];
            if(mp.find(pre) != mp.end()) count += mp[pre];
            mp[pre]++;
        }
        cout << count << endl;
    }
}