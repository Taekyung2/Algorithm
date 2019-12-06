/*
	서로 친구인 학생들끼리 짝 짓기
*/

#include <bits/stdc++.h>
using namespace std;

int TC, N, M;
bool areFriends[10][10];


int countPairings(bool taken[10]) {
	int firstFree = -1;
	for(int i=0; i<N; i++) {
		if(!taken[i]) {
			firstFree = i;
			break;
		}
	}
	//모든 학생이 짝을 찾았으면 종료한다
	if(firstFree == -1) return 1;
	int ret = 0;
	for(int pairWith = firstFree+1; pairWith < N; pairWith++) {
		if(!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}


int main() {
	cin >> TC;
	while(TC--) {
		cin >> N >> M;
		bool taken[10] = {false};
		memset(areFriends, false, sizeof(areFriends));
		for(int i=0; i<M; ++i) {
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		cout << countPairings(taken) << endl;
	}
}
	
