#include <bits/stdc++.h>
using namespace std;


int TC, n, capacity; 
int volume[100], need[100];
int cache[1001][100];
string name[100];


int pack(int capacity, int item) {
	if(item == n) return 0;
	int& ret = cache[capacity][item];
	if(ret != -1) return ret;
	//이 물건을 담지 않을 경우
	ret = pack(capacity, item + 1);
	//이 물건을 담을 경우
	if(capacity >= volume[item])
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	return ret;
}


void reconstruct(int capacity, int item, vector<string>& picked) {
	//기저 사례: 모든 물건을 다 고려했음
	if(item == n) return;
	if(pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}


int main() {
	cin >> TC;
	for(int t = 0; t < TC; ++t) {
		vector<string> picked;
		memset(cache, -1, sizeof(cache));
		cin >> n >> capacity;
		for(int i = 0; i < n; ++i) 
			cin >> name[i] >> volume[i] >> need[i];
		reconstruct(capacity, 0, picked);
		cout << pack(capacity, 0) << " " << picked.size() << endl;
		for(auto& name : picked)
			cout << name << endl;
	}
}
