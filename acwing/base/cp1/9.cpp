#include <iostream>
#include <vector>
using namespace std;
vector<int> Mul(vector<int> &A,int b)
{
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size() || t; i++)
    {
        if(i < A.size()) t = A[i] * b + t;
        C.push_back(t%10);
        t/=10;
    }
    while(C.size() > 1 && C.back()==0) C.pop_back();      //delete front 0
    return C;
}
int main()
{
    ios::sync_with_stdio(false);
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    auto C = Mul(A,b);
    for(int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << endl;
}