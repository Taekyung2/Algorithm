#include <bits/stdc++.h>
using namespace std;


int TC, n, d, p, t;
int q[50];
vector<int> connected[50];
vector<int> path;
double cache[51][101];

/*
double search(veector<int>& path) {
	if(path.size() == d + 1) {
		if(path.back() != q) return 0.0;
		double ret = 1.0;
		for(int i = 0; i + 1 < path.size(); ++i) 
			ret /= connected[path[i]].size();	
		return ret;
	}
	double ret = 0.0;
	for(auto& next : connected[path.back()]) {
		path.push_back(next);
		ret += search(path);
		path.pop_back();
	}
	return ret;
}


double search2(int here, int days) {
	//기저사례 : d일이 지난 경우
	if(days == d) return (here == q ? 1.0 : 0.0);
	//메모이제이션
	double& ret = cache[here][days];
	if(ret > -0.5) return ret;
	ret = 0.0;
	for(auto& next : connected[here]) 
		ret += search2(next, days + 1) / connected[here].size();
	return ret;
}
*/


double search3(int here, int days) {
	//기저 사례 : 0일 째
	if(days == 0) return (here == p ? 1.0 : 0.0);
	//메모이제이션
	double& ret = cache[here][days];
	if(ret > -0.5) return ret;
	ret = 0.0;
	for(auto& next : connected[here])
		ret += search3(next, days - 1) / connected[next].size();
	return ret;
}


int main() {
	cin >> TC;
	while(TC--) {
		cin >> n >> d >> p;
		memset(cache, -1, sizeof(cache));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) {
				int tmp; cin >> tmp;
				if(tmp == 1) {
					connected[i].push_back(j);
					connected[j].push_back(i);
				}
			}
		cin >> t;
		for(int i = 0; i < t; ++i) {
			cin >> q[i];
			printf("%.8lf ",search3(q[i], d));
		}
		printf("\n");
		for(auto& i : connected) 
			i.clear();
	}
	return 0;
}
