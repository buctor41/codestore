#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
char a[N],b[N];
char gl[26];
int sa,sb,sc;
int idx = -1;
bool isG(char c)
{
    for(int i = 0; i < sc; i++){
        if(gl[i]==c) return true;
    }
    return false;
}
bool check()
{
    if(idx==-1){
        if(sa!=sb) return false;
        for(int i = 0; i < sa;i++){
            if(a[i]==b[i]) continue;
            if(a[i]=='?'){
                if(!isG(b[i])){
                    return false;
                }
            }else{
                return false;
            }
        }
    }else{
        if(sa > sb + 1) return false;
        for(int i = 0; i < idx; i++){
            if(a[i]==b[i]) continue;
            if(a[i]=='?'){
                if(!isG(b[i])) return false;
            }else return false;
        }
        int i = sa - 1,j = sb - 1;
        for(;i > idx; i--,j--){
            if(a[i]==b[j]) continue;
            if(a[i]=='?'){
                if(!isG(b[j])) return false;
            }
            else return false;
        }
        for(;i <= j; i++){
            if(isG(b[i])) return false;
        }
    }
    return true;
}

int main()
{
    scanf("%s%s%d",gl,a,&n);
    sa = strlen(a);
    sc = strlen(gl);
    for(int i = 0; i < sa; i++){
        if(a[i]=='*') idx = i;
    }   
    while(n--){
        memset(b,0,sizeof(char)*N);
        scanf("%s",b);
        sb = strlen(b);
        bool v = check();
        if(v) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
