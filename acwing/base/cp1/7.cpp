//https://www.acwing.com/problem/content/793/
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
vector<int> Add(vector<int> &A,vector<int>& B)
{
    vector<int> C;
    int t = 0;
    for(int i = 0, j = 0; i < A.size() || j < B.size() || t;i++,j++)
    {
        if(i < A.size()) t+=A[i];
        if(j < B.size()) t+=B[j];
        C.pb(t%10);
        t/=10;
    }
    return C;
}
int main()
{
    string a,b;
    vector<int> A,B;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.pb(a[i] - '0');

    for(int i = b.size() - 1; i >= 0; i--) B.pb(b[i] - '0');

    auto C = Add(A,B);
    
    for(int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << endl;
    return 0;
}