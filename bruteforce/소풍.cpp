#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool> check;
int cnt;
int countPair(vector<pair<int, int>> v, int chk_true, int n, int idx) {
	if (chk_true == n) {
		return 1;
	}

	int first, second;
	int ret = 0;
	for (int i = idx; i < v.size(); i++) {
		first = v[i].first;
		second = v[i].second;
		if (check[first] == false && check[second] == false) {
			check[first] = check[second] = true;
			ret += countPair(v, chk_true + 2, n, i + 1);
			check[first] = check[second] = false;
		}
	}
	return ret;
}

//int main() {
//	int C; //테스트케이스 갯수
//	cin >> C;
//
//	vector<pair<int, int>> v;
//	int n, m; //학생수, 친구 쌍의 수
//	int x, y;
//	for (int i = 0; i < C; i++) {
//		cin >> n >> m;
//		for (int j = 0; j < m; j++) {
//			cin >> x >> y;
//			v.push_back(make_pair(x, y));
//		}
//
//		check.assign(n, false);
//		sort(v.begin(), v.end());
//		cout<<countPair(v, 0, n, 0)<<endl;
//		check.clear();
//		v.clear();
//	}
//
//	return 0;
//}

/*
입력
3
2 1
0 1
4 6
0 1 1 2 2 3 3 0 0 2 1 3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5

출력
1
3
4
*/