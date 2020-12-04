#include<iostream>
using namespace std;
/*
1+2+...+n -> 1+2+...+n/2 + (n/2+1)+(n/2+2)+...+n
(n/2+1)+(n/2+2)+...+(n/2+n/2) -> (n/2)*(n/2)+(1+2+...+n/2)

*/
int fastSum(int n) {
	if (n == 1) return 1;
	//Ȧ���� ��� n-1���� ���� ���ȣ���ϰ� n�� ���ؼ� ���� ����.
	if (n % 2 == 1) return fastSum(n - 1) + n; 
	return 2 * fastSum(n / 2) + (n / 2)*(n / 2);
}

//int main() {
//	cout << fastSum(10) << endl;
//	return 0;
//}