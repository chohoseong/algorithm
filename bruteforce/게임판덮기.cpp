#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<pair<int, int>>> direction{ {{0,0},{1,0},{0,1}},
										  {{0,0},{0,1},{1,1}},
										  {{0,0},{1,0},{1,1}},
										  {{0,0},{1,0},{1,-1}} };

bool set(vector<vector<int>>& board, int i, int j, int type, int delta) {
	bool ok = true;
	for (int k = 0; k < 3; k++) {
		const int x = i + direction[type][k].first;
		const int y = j + direction[type][k].second;

		if (x < 0 || x >= board.size() || y < 0 || y >= board[i].size())
			ok=false;

		else if ((board[x][y] += delta) > 1)
			ok=false;
	}
	return ok;
}

int cover(vector<vector<int>>& board) {
	int i=-1, j=-1;
	for (int idx = 0;  idx < board.size(); idx++) {
		for (int jdx = 0; jdx < board[idx].size(); jdx++) {
			if (board[idx][jdx] == 0) {
				i = idx; j = jdx;
				break;
			}
		}
		if (i != -1) break;
	}

	//흰색이 없다면 1 리턴
	if (i == -1) return 1;

	int result = 0;

	//4가지 타입에 따라서 흰색을 채울 수 있는지
	for (int type = 0; type < 4; type++) {
		if (set(board, i, j, type, 1)) {
			result += cover(board);
		}
		set(board, i, j, type, -1);	
	}
	return result;
}

void Pretreatment(vector<vector<char>> sample, int H, int W) {
	int white_count = 0;
	vector<vector<int>> board(H, vector<int>(W, 0));

	for (int i = 0; i < sample.size(); i++) {
		for (int j = 0; j < sample[i].size(); j++)
			if (sample[i][j] == '.') {
				white_count++;
			}
			else
				board[i][j] = 1;
	}

	if (white_count % 3 != 0) return ; //흰색이 3의배수가 아니면

	cout << cover(board) << endl;
}


//int main() {
//	int c; //test case
//	cin >> c;
//	vector<vector<char>> board;
//	int H, W;
//	
//	string s;
//	for (int i = 0; i < c; i++) {
//		cin >> H >> W;  //행 열
//		board.assign(H, vector<char>(W));
//		for (int j = 0; j < H; j++) {
//			cin >> s;
//			for (int k = 0; k < W; k++) {
//				board[j][k] = s[k];
//
//			}
//		}
//		Pretreatment(board, H, W);
//		board.clear();
//	}
//	return 0;
//}


/*
입력
3
3 7
#.....#
#.....#
##...##
3 7
#.....#
#.....#
##..###
8 10
##########
#........#
#........#
#........#
#........#
#........#
#........#
##########

출력
0
2
1514
*/