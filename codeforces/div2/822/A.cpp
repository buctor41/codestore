#include <iostream>
#include <algorithm>
#define ll long long
#define pb push_back
#define pp pop_back
using namespace std;
int main()
{
    ll A,B;
    cin >> A >> B;
    ll val = min(A,B);
    ll res = 1;
    for(ll i = 1; i <= val; i++)
    {
        res *= i;
    }
    cout << res << endl;
}