//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//	int N;
//	cin >> N;
//
//	vector<int> line;
//	int left_count;
//	for (int i = 0; i < N; i++) {
//		cin >> left_count;
//		line.push_back(left_count);
//	}
//
//	int idx;
//	vector<int> result;
//	for (int i = line.size() - 1; i >= 0; i--) {
//		idx = 0;
//		for (int j = 0; j < result.size(); j++) {
//			if (result[j] > i+1) {
//				line[i]--;
//			}
//			if (line[i] == 0) {
//				idx = j+1;
//				break;
//			}
//		}
//		result.insert(result.begin()+idx,i+1);
//	}
//
//	for (int i = 0; i < result.size(); i++) {
//		cout << result[i] << " ";
//	}
//	return 0;
//}