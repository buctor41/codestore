//https://www.acwing.com/problem/content/794/
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
bool check(vector<int> &A,vector<int>& B)
{
    if(A.size() > B.size()) return true;
    if(A.size() < B.size()) return false;
    for(int i = A.size() - 1; i >= 0; i--)
    {
        if(A[i] > B[i]) return true;
        if(A[i] < B[i]) return false;
    }
    return true;
}
vector<int> Sub(vector<int> &A,vector<int>& B)
{
    vector<int> C;
    int t = 0;
    //A.size() >= B.size()
    for(int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if(i <B.size()) t-=B[i];
        C.pb((t+10)%10);
        if(t < 0) t = 1;
        else t = 0;
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
int main()
{
    string a,b;
    vector<int> A,B;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.pb(a[i] - '0');

    for(int i = b.size() - 1; i >= 0; i--) B.pb(b[i] - '0');
    if(check(A,B))
    {
        auto C = Sub(A,B);
        for(int i = C.size() - 1; i >= 0; i--) cout << C[i];
        cout << endl;        
    }else{
        cout << "-";
        auto C = Sub(B,A);
        for(int i = C.size() - 1; i >= 0; i--) cout << C[i];
        cout << endl;
    }
    

    return 0;
}