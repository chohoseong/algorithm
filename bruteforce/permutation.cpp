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

// ù��° ���ڰ� ���ϰ��� �ϴ� ������ ����, �ι�° ���ڰ� ������ ��
//bool next_permutation(BidirectionalIterator first, BidirectionalIterator last);

// �Ʒ�ó�� ���� ���Լ��� �־��൵ �˴ϴ�.
//bool next_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp);

//next, prev ��� sorting�Ǿ��־�� ��� ����� �� ����.