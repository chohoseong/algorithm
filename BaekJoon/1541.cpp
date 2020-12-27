//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//
//	vector<int> v;
//	int idx = 0;
//	
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == '-' || s[i] == '+') {
//			v.push_back(stoi(s.substr(idx, i - idx)));
//			idx = i;
//		}
//		if (i == s.size() - 1) {
//			v.push_back(stoi(s.substr(idx)));
//		}
//	}
//	
//	int result = 0;
//	for (int i = 0; i < v.size()-1; i++) {
//		if (v[i] < 0 && v[i + 1]>0) {
//			v[i + 1] = -v[i + 1];
//		}
//		result += v[i];
//	}
//	result += v.back();
//	cout << result;
//
//	return 0;
//}