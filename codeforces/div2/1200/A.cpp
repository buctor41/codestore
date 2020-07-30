#include <iostream>
using namespace std;
const int N = 1e5 + 10;
char s[N];
int n;
int rooms[10];
void addL(){
    for(int i = 0; i < 10; i++){
        if(rooms[i]==0){
            rooms[i] = 1;
            break;
        }
    }
}
void addR(){
    for(int i = 9; i >= 0; i--){
        if(rooms[i]==0){
            rooms[i] = 1;
            break;
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i]=='L'){
            addL();
        }else if(s[i]=='R'){
            addR();
        }else{
            rooms[s[i]-'0'] = 0;
        }
    }
    for(int i = 0 ;i < 10; i++) cout << rooms[i];
    cout << endl;
    return 0;
}