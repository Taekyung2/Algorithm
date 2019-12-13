#include <bits/stdc++.h>
using namespace std;


int TC, N;
string W, file_name[50];
int dp[101][101];
set<string> ret;


int matchMemoized(int w, int s, string S) {
    int& ret = dp[w][s];
    if(ret != -1) return ret;
    if(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) 
        return ret = matchMemoized(w + 1, s + 1, S);
    if(w == W.size()) return ret = (s == S.size());
    if(W[w] == '*') 
        if(matchMemoized(w+1, s, S) || (s < S.size() && matchMemoized(w, s + 1, S)))
            return 1;
    return 0;
}


int main() {
    cin >> TC;
    for(int t = 0; t < TC; ++t) {
        cin >> W;   cin >> N;
        ret.clear();
        for(int i = 0; i < N; ++i) {
            memset(dp, -1, sizeof(dp));
            cin >> file_name[i];
            if(matchMemoized(0, 0, file_name[i])) 
                ret.insert(file_name[i]);
        } 
        for(auto i : ret)
            cout << i << endl;
    }    
}