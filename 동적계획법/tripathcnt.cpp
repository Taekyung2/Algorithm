#include <bits/stdc++.h>
using namespace std;


int TC, N, tri[100][100];
int dp[100][100], count_dp[100][100];


int path(int y, int x) {
	if(y == N-1) return tri[y][x];
	int& ret = dp[y][x];
	if(ret != -1) return ret;
	return ret = max(path(y+1, x), path(y+1, x+1)) + tri[y][x];
}


int cnt_path(int y, int x) {
	if(y == N-1) return 1;
	int& ret = count_dp[y][x];
	if(ret != -1) return ret;

	ret = 0;
	if(path(y + 1, x + 1) >= path(y + 1, x))	ret += cnt_path(y + 1, x + 1);
	if(path(y + 1, x + 1) <= path(y + 1, x))	ret += cnt_path(y + 1, x);
	return ret;
}
	

int main() {
	cin >> TC;
	for(int t = 0; t < TC; ++t) {
		cin >> N;
		memset(dp, -1, sizeof(dp));
		memset(count_dp, -1, sizeof(count_dp));
		for(int i = 0; i < N; ++i)
			for(int j = 0; j <= i; ++j)
				cin >> tri[i][j];
		cout << cnt_path(0, 0) << endl;
	}
}
