#include<iostream>
#include<vector>
using namespace std;

void pick(int n, vector<int>& v, int toPick) {
	if (toPick == 0) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
		return;
	}

	int smallest = v.empty() ? 0 : v.back() + 1;

	for (int i = smallest; i < n; i++) {
		v.push_back(i);
		pick(n, v, toPick - 1);
		v.pop_back();
	}
}

//int main() {
//	int n = 7;
//	int topick = 4;
//	vector<int> v;
//	pick(n, v, topick);
//}