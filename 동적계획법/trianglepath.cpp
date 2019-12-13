#include <bits/stdc++.h>
using namespace std;


int TC, n;
vector<int> tri[100];
int dp[100][100];


int path(int y, int x) {
    if(y == n-1) return tri[y][x];

    int& ret = dp[y][x];
    if(ret != -1) return ret;
    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + tri[y][x];
}


int main() {
    cin >> TC;
    for(int t = 0; t < TC; ++t) {
        cin >> n;
        int tmp;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j <= i; ++j) {
                cin >> tmp;
                tri[i].push_back(tmp);
            }
        cout << path(0, 0) << endl;
        for(auto& i : tri)
            i.clear();  
    }
}