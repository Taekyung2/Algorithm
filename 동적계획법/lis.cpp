#include <bits/stdc++.h>
using namespace std;


int TC, N, lis[500], dp[500];


int get_lis(int start) {
	int& ret = dp[start];
	if(ret != -1) return ret;
	ret = 1;
	for(int next = start + 1; next < N; ++next) 
		if(lis[start] < lis[next])
			ret = max(ret, get_lis(next) + 1);
	return ret;
}


int main() {
	cin >> TC;
	for(int t = 0; t < TC; ++t) {
		cin >> N;
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < N; ++i)
			cin >> lis[i];
		int ret = 0;
		for(int begin = 0; begin < N; ++begin)
			ret = max(ret, get_lis(begin)); 
		cout << ret << endl;
	}
}

