#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int n;
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    unordered_map<int,int> hash;
    for(int i = 0; i < n; i++){
        int v = a[i];
        for(int j = 2; j <= v/j;j++){
            if(v%j) continue;
            hash[j]++;
            while(v%j==0) v/=j;
        }
        if(v > 1) hash[v]++;
    }
    int res,cnt = 0;
    for(auto t:hash){
        int x = t.first,y = t.second;
        if(y>cnt){
            cnt = y,res = x;
        }

    }
    cout << res << endl;
}
