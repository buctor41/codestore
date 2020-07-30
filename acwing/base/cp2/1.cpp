//https://www.acwing.com/problem/content/submission/828/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int e[N],ne[N],head,idx;
void init()
{
    head = -1,  idx = 0;
}
void add_to_head(int x)
{
    e[idx] = x, ne[idx] = head, head = idx,idx++;
}
void add(int k,int x)
{
    e[idx] = x, ne[idx] = ne[k],ne[k] = idx,idx++;
}
void del(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        int k,x;
        char op;
        cin >> op;
        if(op=='H'){
            scanf("%d",&x);
            add_to_head(x);
        }else if(op=='I'){
            scanf("%d%d",&k,&x);
            add(k-1,x);
        }else{
            cin >> k;
            if(k==0) head = ne[head];
            else del(k-1);
        }
    }
    for(int i = head;i!=-1;i=ne[i]) printf("%d ",e[i]);
    printf("\n");
}