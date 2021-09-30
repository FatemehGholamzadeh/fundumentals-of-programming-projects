#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	int n, x;
	cout << "please enter n & x:" << endl;
	cin >> n >> x;
	int s = 0;
	int i = 0;
	int a = 1;
	int k = 0;
	while (i <= n) {
		while (k < i) {
			a = x*a;
			s = s + a / i;
			k = k + 1;
		}
		i = i + 1;
	}
	cout << s;
	_getch();
	return(0);

}