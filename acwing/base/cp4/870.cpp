#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
bool st[N];
int primes[N],cnt;
// void get_primes(int n)               //朴素筛法
// {
//     for(int i = 2; i <= n; i++){
//         if(!st[i])
//         {
//             primes[cnt++] = i;
//         }
//         for(int j = i + i ; j <= n; j+=i) st[j] = true;
//     }
// }
// void get_primes(int n)        //埃筛
// {
//     for(int i = 2; i <= n; i++)
//     {
//         if(!st[i]){
//             primes[cnt++] = i;
//             for(int j  = i + i; j <= n; j+=i) st[j] = true;
//         }
//     }
// }
void get_primes(int n)              //线性筛法
{
    for(int i = 2; i <= n; i++)
    {
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j]*i] = true;
            if(i%primes[j]==0) break;
        }
    }
    
}
int main()
{
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
}