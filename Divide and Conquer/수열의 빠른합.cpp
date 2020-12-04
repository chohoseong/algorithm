#include<iostream>
using namespace std;
/*
1+2+...+n -> 1+2+...+n/2 + (n/2+1)+(n/2+2)+...+n
(n/2+1)+(n/2+2)+...+(n/2+n/2) -> (n/2)*(n/2)+(1+2+...+n/2)

*/
int fastSum(int n) {
	if (n == 1) return 1;
	//홀수일 경우 n-1까지 합을 재귀호출하고 n을 더해서 답을 구함.
	if (n % 2 == 1) return fastSum(n - 1) + n; 
	return 2 * fastSum(n / 2) + (n / 2)*(n / 2);
}

//int main() {
//	cout << fastSum(10) << endl;
//	return 0;
//}