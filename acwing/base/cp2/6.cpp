//https://www.acwing.com/problem/content/156/
//优先队列
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int q[N],hh,tt = -1;
int a[N];
int main()
{
    hh = 0,tt = -1;
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < n;i++){
        if(q[hh]+k-1 < i) hh++;
        while(hh <= tt && a[i] <= a[q[tt]]) --tt;
        q[++tt] = i;
        if(i >= k-1) cout << a[q[hh]] << " ";
    }
    cout << endl;
    tt = -1,hh = 0;
    for(int i = 0; i < n;i++){
        if(q[hh]+k-1 < i) hh++;
        while(hh <= tt && a[i] >= a[q[tt]]) --tt;
        q[++tt] = i;
        if(i >= k-1) cout << a[q[hh]] << " ";
    }
    cout << endl;
    return 0;
}