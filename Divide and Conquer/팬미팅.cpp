#include<iostream>
#include<vector>
#include<string>
using namespace std;

extern vector<int> karatsuba(const vector<int>& a, const vector<int>& b);

int hugs(const string& member, const string& fan) {
	int N = member.size(), M = fan.size();
	vector<int> A(N), B(M);

	for (int i = 0; i < N; i++) 
		if (member[i] == 'M') A[i] = 1;

	for (int i = 0; i < M; i++)
		if (fan[i] == 'M') B[M-i-1] = 1;

	vector<int> C = karatsuba(A, B);
	int allHugs = 0;
	for (int i = N - 1; i < M; i++) 
		if (C[i] == 0) allHugs++;

	return allHugs;
}

int main() {
	int c,n,s;
	cin >> c;

	string member, fan;
	for (int i = 0; i < c; i++) {
		cin >> member >> fan;
		cout << hugs(member, fan) << endl;;
	}
	return 0;
}