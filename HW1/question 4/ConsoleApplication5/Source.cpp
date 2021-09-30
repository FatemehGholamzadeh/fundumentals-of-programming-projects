#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	int a, b;
	int s = 1;
	int i = 0;
	int k=1;
	int m = 1;
	int x;
	cout << "please enter the first number"<<endl;
	cin >> a;
	cout << "please enter the second number"<<endl;
	cin >> b;
	cout << "please enter number 1 or 2"<<endl;
	cin >> x;
	if (x == 1) {
		if (b < 0)
			cout << "you must enter a positive number for b !";
		else {
			while (i < b) {
				s = s*a;
				i++;
			}
			cout << "a^b is:" << s;
		}
	}
	else if (x == 2) {
			
		while (a > 1) {
			k = k*a;
			a--;

		}
		while (b > 1) {
			m = m*b;
			b--;

		}

		if (a <= 0 || b <= 0) {

			cout << "you must enter positive numbers!";
		}
		
		else if (a > 0 && b > 0)
		{
			cout << "a! / b! is:" << k / m;
		}
	}

	else cout << "you must enter number 1 or 2";
	_getch();
	return(0);


}