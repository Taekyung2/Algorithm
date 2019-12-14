#include <bits/stdc++.h>
using namespace std;


int TC, N, M, A[100], B[100];
int dp[101][101];
const long long NEGINF = numeric_limits<long long>::min();


int jlis(int pos_a, int pos_b) {
	int& ret = dp[pos_a + 1][pos_b + 1];
	if(ret != -1) return ret;
	ret = 0;
	long long a = (pos_a == -1 ? NEGINF : A[pos_a]);
	long long b = (pos_b == -1 ? NEGINF : B[pos_b]);
	long long max_num = max(a, b);
	for(int nextA = pos_a + 1; nextA < N; ++nextA) 
		if(max_num < A[nextA])
			ret = max(ret, jlis(nextA, pos_b) + 1);
	for(int nextB = pos_b + 1; nextB < M; ++nextB) 
		if(max_num < B[nextB])
			ret = max(ret, jlis(pos_a, nextB) + 1);
	return ret;
}


int main() {
	cin >> TC;
	for(int t = 0; t < TC; ++t) {
		cin >> N >> M;
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < N; ++i)
			cin >> A[i];
		for(int i = 0; i < M; ++i)
			cin >> B[i];
		cout << jlis(-1, -1) << endl;
	}
}
