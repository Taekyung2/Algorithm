#include <bits/stdc++.h>
using namespace std;


int N;
int board[100][100];
int dp[100][100];


int jump(int y, int x) {
   if(y >= N || x >= N) return 0;
   if(y == N - 1 && x == N - 1) return 1;

   int& ret = dp[y][x];
   if(ret != -1) return ret;
   int jumpSize = board[y][x];
   return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}


int main() {
    int TC;
    cin >> TC;
    for(int t = 0; t < TC; ++t) {
        cin >> N;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j) 
                cin >> board[i][j];

        if(jump(0, 0))  cout << "YES" << endl;
        else            cout << "NO" << endl;
    }
}