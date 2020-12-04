#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int solve(int left, int right) {
	if (left == right) return v[left];

	int mid = (left + right) / 2;

	int ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, hi = mid + 1;
	int height = min(v[lo], v[hi]);

	ret = max(ret, height * 2);

	while (left < lo || hi < right) {

		if (hi < right && (lo == left || v[lo - 1] < v[hi + 1])) {
			hi++;
			height = min(height, v[hi]);
		}
		else {
			lo--;
			height = min(height, v[lo]);
		}

		ret = max(ret, height*(hi - lo + 1));
	}
	return ret;
}

//int main() {
//	int c,n,x;
//	
//	cin >> c;
//	for (int i = 0; i < c; i++) {
//		cin >> n;
//		for (int j = 0; j < n; j++) {
//			cin >> x;
//			v.push_back(x);
//		}
//		cout << solve(0, v.size() - 1) << endl;
//		v.clear();
//	}
//	return 0;
//}