#include <bits/stdc++.h>
using namespace std;

string board[100];
const int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

inline bool inRange(int y, int x) { return ( y<=100 && x<=100 && y>=0 && x>=0 ); }


bool hasWord(int y, int x, const string&word) {
	if(!inRange(y, x)) return false;

	if(board[y][x] != word[0]) return false;
	if(word.length() == 1) return true;
	for(int dir=0; dir<8; ++dir) {
		int next_y = y + dy[dir], next_x = x + dx[dir];
		if(hasWord(next_y, next_x, word.substr(1)))
			return true;
		}
	return false;
}

int main() {
	string word; cin >> word;
	int Y, X; cin >> Y >> X;
	cout << hasWord(Y, X, word) << endl;
	return 0;
}
