//question 2:
#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	int n;
	int m;
	int a;
	int k = 1;
	int i;
	int f = 0;
	bool flag = false;
	cout << "enter your number" << endl;
	cin >> n;
	while (n >= 1) {
		m = n % 10;
		n = n / 10;
		f = f * 10 + m;
		
	}
	while (k<= f) {
		a = f/ k % 10;
		k = k * 10;
		i = 0;
		while (i < a) {
			cout << a;
			i++;
		}
	}



	_getch();
	return(0);








}