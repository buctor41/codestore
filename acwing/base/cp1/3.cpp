//merge sort
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
#define INF 0x3f3f3f3f
int q[N],tmp[N],n;
void merge_sort(int l,int r)
{
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r)
    {
        if(q[i] < q[j])
            tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    for(int i = 0, j = l; i < k; i++)
    {
        q[j++] = tmp[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> q[i];
    merge_sort(1,n);
    for(int i = 1; i <= n; i++) cout << q[i] << " ";
    return 0; 
}