#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==1){
            cout << "FastestFinger" << endl;
            continue;
        }
        if(n==2){
            cout << "Ashishgup" << endl;
            continue;
        }
        if(n%2==1){
            cout << "Ashishgup" << endl;
        }else{
            int a = 0, b = 0;
            for(int i = 2; i <= n / i; i++){
                int cnt = 0;
                while(n!=0&&n%i==0)
                {
                    n /= i;
                    cnt++;
                }
                if(i==2) a = cnt;
                else b += cnt;
            }
            if(n>1) b++;
            if(a==1){
                if(b==1) cout << "FastestFinger" << endl;
                else cout << "Ashishgup" << endl;
            }else{
                if(b >= 1)  cout << "Ashishgup" << endl;
                else    cout << "FastestFinger" << endl; 
            }
        }
    }
    return 0;
}