#include <bits/stdc++.h>
using namespace std;


const int MOD = 10 * 1000 * 1000;
int TC, N;
int cache[101][101];


int poly(int n, int first) {
	if(n == first) return 1;
	int& ret = cache[n][first];
	if(ret != -1) return ret;
	ret = 0;
	for(int second = 1; second <= n - first; ++second) {
		int add = second + first - 1;
		add *= poly(n- first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}


int main() {
	cin >> TC;
	while(TC--) {
		cin >> N;
		int sum = 0;
		memset(cache, -1, sizeof(cache));
		for(int i = 1; i <= N; ++i) {
			sum += poly(N, i);
			sum %= MOD;
		}
		cout << sum << endl;
	}
}
	
