#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(string &s)
{
    vector<int> score;
    for(int i = 0; i < s.size();i++){
        if(s[i]=='0') continue;
        int j = i;
        while(j < s.size() && s[j] == '1') j++;
        score.push_back(j-i);
        i = j - 1;
    }
    sort(score.begin(),score.end());
    reverse(score.begin(),score.end());
    int ret = 0;
    for(int i = 0; i < score.size(); i+=2) ret += score[i];
    return ret;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}