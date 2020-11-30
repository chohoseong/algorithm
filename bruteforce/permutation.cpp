#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> v;

	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(1);

	do {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));
}

// 첫번째 인자가 구하고자 하는 순열의 시작, 두번째 인자가 순열의 끝
//bool next_permutation(BidirectionalIterator first, BidirectionalIterator last);

// 아래처럼 직접 비교함수를 넣어줘도 됩니다.
//bool next_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp);

//next, prev 모두 sorting되어있어야 모든 경우의 수 가능.