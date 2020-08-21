#include <bits/stdc++.h>
using namespace std;
#define REP(x,l,u) for(int x = l,x < u; x++)
#define ll long long
const int INF = 1e9 + 10;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int v = INF;
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
            v = min(v,a[i]);
        } 
        vector<int> q;
        for(int i = 0; i < n; i++){
            if(a[i]%v==0){
                q.push_back(a[i]);
                a[i] = -1;
            }
        }
        sort(q.begin(),q.end());
        int idx = 0;
        for(int i = 0;i < n; i++){
            if(a[i]==-1){
                a[i] = q[idx];
                idx++;
            }
        }
        bool flag = true;
        for(int i = 0; i < n - 1; i++){
            if(a[i] > a[i+1]){
                flag = false;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}