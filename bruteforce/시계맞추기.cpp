#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 987654321

vector<vector<int>> Switch{
	{0,1,2},{3,7,9,11},{4,10,14,15},{0,4,5,6,7},{6,7,8,10,12},
	{0,2,14,15},{3,14,15},{4,5,7,14,15},{1,2,3,4,5},{3,4,5,9,13}
};

int ClockSync(vector<int>& clock, int num) {
	if (num == 10) {
		int idx;
		for (idx = 0; idx < clock.size(); idx++) {
			if (clock[idx] != 12) break;
		}
		if (idx == clock.size()) return 0;
		else return INF;
	}

	int result = INF;
	for (int i = 0; i < 4; i++) {
		result = min(result, i + ClockSync(clock, num + 1));
		for (int j = 0; j < Switch[num].size(); j++) {
			int index = Switch[num][j];
			clock[index] = clock[index] + 3 > 12 ? 3 : clock[index] + 3;
		}
	}
	return result;
}

//int main() {
//	int c;
//	cin >> c;
//
//	vector<int> clock(16);
//	for (int i = 0; i < c; i++) {
//		for (int j = 0; j < 16; j++) {
//			cin >> clock[j];
//		}
//		cout << ClockSync(clock, 0) << endl;
//	}
//	return 0;
//}

/*
입력
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6

출력
2
9
*/