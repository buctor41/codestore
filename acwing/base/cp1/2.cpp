//kth
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int q[N],n,k;
int quick_sort(int l,int r,int k)
{
    if(l>=r) return q[l];        //now l==r k==1
    int i = l - 1,j = r + 1,x = q[l+r >> 1];
    while(i < j)
    {
        do ++i;while(q[i] < x);
        do --j;while(q[j] > x);
        if(i < j) swap(q[i],q[j]);
    }
    int sl = j - l + 1;
    if(sl >= k){
        return quick_sort(l,j,k);
    }else{
        return quick_sort(j+1,r,k-sl);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> q[i];
    cout << quick_sort(1,n,k) << endl;
}