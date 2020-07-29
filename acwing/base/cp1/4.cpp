#include <iostream>
using namespace std;
const int N = 1e5 + 10;
long long res = 0;
int q[N],tmp[N],n;
void merge_sort(int l,int r)
{
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l,mid),merge_sort(mid+1,r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j]){
            tmp[k++] = q[i++];
        }else{
            tmp[k++] = q[j++];
            res += (mid - i + 1);
        }
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    for(i = 0, j =l; i < k; i++,j++) q[j] = tmp[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> q[i];
    merge_sort(1,n);
    cout << res << endl;
}