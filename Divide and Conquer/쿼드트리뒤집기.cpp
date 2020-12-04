#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<vector<char>> decompressed(16, vector<char>(16));
void decompress(string::iterator &it,int x,int y,int size) {
	//�� ���ڸ� �˻��Ҷ����� �ݺ��ڸ� �� ĭ ������ �ű��.
	char head = *(it++);

	if (head == 'b' || head == 'w') {
		for (int dx = 0; dx < size; dx++)
			for (int dy = 0; dy < size; dy++)
				decompressed[x + dx][y + dy] = head;
	}
	else {
		int half = size / 2;
		decompress(it, x, y, half);
		decompress(it, x, y+half, half);
		decompress(it, x+half, y, half);
		decompress(it, x+half, y+half, half);
	}
}

string reverse(string::iterator& it) {
	char head = *(it++);
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	//���� ���� �Ʒ� �������� ��ġ�� �ٲ۴�.
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

//int main() {
//	int c;
//	cin >> c;
//
//	vector<vector<char>> board;
//	string s;
//	for (int i = 0; i < c; i++) {
//		cin >> s;
//		
//		/*decompress(s.begin(), 0, 0, 16);
//		for (int j = 0; j < decompressed.size(); j++) {
//			for (int k = 0; k < decompressed[j].size(); k++) {
//				cout << decompressed[j][k] << " ";
//			}
//			cout << endl;
//		}*/
//		reverse(s.begin());
//	}
//	return 0;
//}