/*
	ㄴ모양 블럭으로 H*W 크기 게임판을 덮자
*/
#include <bits/stdc++.h>
using namespace std;

int TC, H, W;
const int cover[4][3][2] = {
	{ {0,0}, {1,0}, {0,1} },
	{ {0,0}, {0,1}, {1,1} },
	{ {0,0}, {1,0}, {1,1} },
	{ {0,0}, {1,0}, {1,-1}}
};

bool Set(vector<vector<int> >& board, int y, int x, int type, int delta) {
	bool ok = true;
	for(int i=0; i<3; ++i) {
		const int ny = y + cover[type][i][0];
		const int nx = x + cover[type][i][1];
	if(ny<0 || ny>=board.size() || nx<0 || nx>=board[0].size())
		ok = false;
	else if((board[ny][nx] += delta) > 1)
		ok = false;
	}
	return ok;
}


int cover_board(vector<vector<int> >& board) {
	int y = -1, x = -1;
	for(int i=0; i<board.size(); ++i) {
		for(int j=0; j<board[0].size(); ++j)
			if(board[i][j] == 0) {
				y=i; x=j;
				break;
			}
		if(y!=-1) break;
	}
	if(y == -1) return 1; 
	int ret = 0;
	for(int type=0; type<4; ++type) {
		if(Set(board, y, x, type, 1))
			ret += cover_board(board);
		Set(board, y, x, type, -1);
	}
	return ret;
}


int main() {
	cin >> TC;
	while(TC--) {
		cin >> H >> W;
		vector<vector<int>> board;
		for(int i=0; i<H; ++i) {
			vector<int> tmp;
			for(int j=0; j<W; ++j) {
				char c; cin >> c;
				if(c=='#') tmp.push_back(1);
				else	tmp.push_back(0);
			}
			board.push_back(tmp);
		}
		cout << cover_board(board) << endl;
	}
}


