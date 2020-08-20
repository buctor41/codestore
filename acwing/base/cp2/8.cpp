#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N][26],cnt[N],idx;
void insert(string &s)
{
    int v = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        if(a[v][c]) v = a[v][c];
        else{
            idx++;
            a[v][c] = idx;
            v = a[v][c];
        }
    }
    cnt[v]++;
}
int find(string &s)
{
    int v = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        if(a[v][c]) v = a[v][c];
        else return 0;
    }
    return cnt[v];
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        char op[2];
        scanf("%s",op);
        if(op[0]=='I')
        {
            string s;
            cin >> s;
            insert(s);
        }else{
            string s;
            cin >> s;
            cout << find(s) << endl;
        }
    }
}