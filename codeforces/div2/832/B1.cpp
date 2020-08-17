#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char s[N];
char q[N];
string gl;
int sl,ql;
int idx = -1;
bool isIs(char c)
{
    for(int i = 0; i < gl.size(); i++){
        if(gl[i]==c) return true;
    }
    return false;
}
bool check()
{
    bool flag = true;
    if(idx==-1){
        if(sl!=ql) return false;
        for(int i = 0; i < sl; i++)
        {
            if(s[i]==q[i]) continue;
            if(s[i]=='?'){
                if(!isIs(q[i])){
                    flag = false;
                    break;
                }
            }else{
                flag = false;
                break;
            }
        }
    }else{
        if(ql < sl - 1) return false;
        for(int i = 0; i < idx; i++){
            if(s[i]==q[i]) continue;
            if(s[i]=='?'){
                if(!isIs(q[i])){
                    flag = false;
                    break;
                }
            }else{
                flag = false;
                break;
            }
        }
        int i,j;
        for(i = sl - 1,j = ql - 1; i > idx; i--,j--){
            if(s[i]==q[j]) continue;
            if(s[i]=='?'){
                if(!isIs(q[j])){
                    flag = false;
                    break;
                }
            }else{
                flag = false;
                break;
            }
        }
        for(i = idx;i <= j; i++){
            if(isIs(q[i])) flag = false;
        }
    }
    return flag;
}
int main()
{
    int t;
    memset(s,0,sizeof(char)*N);
    cin >> gl;
    scanf("%s",s);
    for(int i = 0; s[i]; i++){
        if(s[i]=='*'){
            idx = i;
            break;
        }
    }
    cin >> t;
    while(t--){
        memset(q,0,sizeof(char)*N);
        scanf("%s",q);
        sl = strlen(s);
        ql = strlen(q);

        bool flag = check();
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}