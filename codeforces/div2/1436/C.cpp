#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n,x,pos;
//pos:0~n-1
//x: 1~n
//有x-1个小于x的数


//L: pos个数
//x 大于x
//n-pos+2个数
int main()
{
    scanf("%d%d%d",&n,&x,&pos);
    int SNum = x - 1,LSpace = pos;
    int BNum = n - x,RSpace = n - pos - 2;
    if(SNum < RSpace){
        cout << 0 << endl;
    }else{
        
    }
}
