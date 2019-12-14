#include <bits/stdc++.h>
using namespace std;


const int MOD = 1000000007;
int TC, N;
int dp[100];


int tile(int width) {
	if(width <= 0) return 1;
	int& ret = dp[width];
	if(ret != -1) return ret;
	return ret = (tile(width - 1) + tile(width - 2)) % MOD;
}


int main() {
	cin >> TC;
	while(TC--) {
		cin >> N;
		memset(dp, -1, sizeof(dp));
		cout << tile(N - 1) << endl;
	}
}
