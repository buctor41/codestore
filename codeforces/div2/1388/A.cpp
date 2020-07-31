#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*HEADFILE*/
#define CYE cout<<"YES"<<endl
#define CNE cout<<"NO"<<endl
/*DEFINE*/
int t,n;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        if(n==36){
            CYE;
            cout << "5 6 10 15" << endl;
            continue;
        }else if(n==40){
            CYE;
            cout << "6 10 15 9" << endl;
            continue;
        }else if(n==44){
            CYE;
            cout << "6 7 10 21" << endl;
            continue;
        }
        if(n > 30){
            CYE;
            cout << "6 10 14 " << n - 30 << endl;           
        }else CNE;
    }
    return 0;
}