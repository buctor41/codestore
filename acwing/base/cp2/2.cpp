//https://www.acwing.com/problem/content/829/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int e[N],l[N],r[N];
int head,tail,idx;
void init()
{
    r[0] = 1, l[1] = 0, idx = 2;
}
void addX(int k,int x)
{
    e[idx] = x;
    l[idx] = k,r[idx] = r[k];
    r[k] = idx,l[r[idx]] = idx;
    idx++;
}
void removeX(int k)
{
    int pre = l[k],next = r[k];
    r[pre] = next;
    l[next] = pre;
}
int main()
{
    init();
    int n;
    cin >> n;
    while(n--){
        string s;
        int k, x;
        cin >> s;
        if(s=="L"){
            cin >> x;
            addX(0,x);
        }else if(s=="R"){
            cin >> x;
            addX(l[1],x);
        }else if(s=="IR"){
            cin >> k >> x;
            addX(k+1,x);
        }else if(s=="IL"){
            cin >> k >> x;
            addX(l[k+1],x);
        }else{
            cin >> k;
            removeX(k+1);
        }
    }
    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
}