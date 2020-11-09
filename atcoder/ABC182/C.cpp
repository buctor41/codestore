#include <bits/stdc++.h>
using namespace std;
int lg[3];
int main()
{
    int r = 0;
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        int v = s[i] - '0';
        r += v;
        r %= 3;
        v %= 3;
        lg[v]++;
    }
    if(r==0){
        cout << "0" << endl;
        return 0;
    }
    if(n>=3){
        if(lg[r]>=1) cout << "1" << endl;
        else cout << "2" << endl;
        return 0;
    }else{
        if(n==1){
            cout << "-1" <<endl;
            return 0;
        }
        if(lg[r]>=1) cout << "1" << endl;
        else cout << "-1" << endl;
    }
    return 0;
}
