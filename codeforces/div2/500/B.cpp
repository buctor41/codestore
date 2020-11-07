#include <bits/stdc++.h>
using namespace std;
const int N = 330;
int a[N];
int p[N];
int find(int x)
{
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}
int n;
int main()
{

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= n;j++){
            char t;
            cin >> t;
            if(t=='1'){
                int a = find(i);
                int b = find(j);
                if(a!=b) p[a] = b;
            }
        }
    }
    set<int> s;
    for(int i = 1;i <= n; i++){
        int f = find(i);
        if(s.count(f)==0){
            s.insert(f);
            vector<int> idx;
            vector<int> data;
            for(int j = i;j<=n;j++){
                int fg = find(j);
                if(fg==f){
                    data.push_back(a[j]);
                    idx.push_back(j);
                }
            }
            sort(data.begin(),data.end());
            for(int j = 0; j < data.size(); j++){
                a[idx[j]] = data[j];
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout <<endl;
    return 0;
}
