#include <iostream>
#include <string>
#include <time.h>
using namespace std;

long long FactorialRec(int n) {
	if (n == 1)
		return 1;
	else
		return n * FactorialRec(n - 1);
}
long long FactorialTailRec(int n, int res) {
	if (n == 1)
		return res;
	return FactorialTailRec(n - 1, res*n);
}

long long FactorialTail(int n) {
	return FactorialTailRec(n, 1);
}


int main()
{

	cout << FactorialTail(1000)<<endl;

	return 0;
}