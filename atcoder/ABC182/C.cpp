#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r = 0,a = 0,b = 0;
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < s.size(); i++){
        int v = s[i] - '0';
        v = v % 3;
        r = (r+v) % 3;
        if(v==1) a++;
        else b++;
    }
    if(r==0){
        cout << 0 << endl;
        return 0;
    }
    if(r==1){
        if(a>=1 && n > 1){
            cout << 1 << endl;
            return 0;
        }
        if(b>=2 && n > 2){
            cout << 2 << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }else{
        if(b>=1 && n > 1){
            cout <<1 << endl;
            return 0;
        }
        if(a>=2 && n > 2){
            cout <<2 <<endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }
}
