#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool hasWord(vector<vector<char>> v, string target, int i, int j) {

	if (i >= v.size() || j >= v.size()) return false;
	if (v[i][j] != target[0]) return false;
	if (target.size()==1) return true;

	vector<pair<int, int>> direction{ make_pair(i + 1,j),make_pair(i + 1,j + 1),make_pair(i ,j + 1) ,make_pair(i - 1,j + 1) ,make_pair(i - 1,j) ,make_pair(i - 1,j - 1) ,make_pair(i ,j - 1) ,make_pair(i + 1,j - 1) };
	for (int k = 0; k < direction.size(); k++) {
		if (hasWord(v, target.substr(1), direction[k].first, direction[k].second))
			return true;
	}
	return false;
}

//int main() {
//	vector<vector<char>> v{ {'U','R','L','P','M'},{'X','P','R','E','T'},{'G','I','A','E','T'},{'X','T','N','Z','Y'},{'X','O','Q','R','S'} };
//	vector<string> target{ "PRETTY","GIRL","REPEAT" };
//	
//	bool check;
//	for (int k = 0; k < target.size(); k++) {
//		for (int i = 0; i < v.size(); i++) {
//			for (int j = 0; j < v[i].size(); j++) {
//				if (v[i][j] == target[k][0]) {
//					check = hasWord(v, target[k], i, j);
//					if (check) goto nxt;
//				}
//			}
//		}
//	nxt:
//		if (check)
//			cout << target[k] << ": YES" << endl;
//		else
//			cout << target[k] << ": NO" << endl;
//	}
//	hasWord(v,"PRETTY",0,0);
//	return 0;
//}