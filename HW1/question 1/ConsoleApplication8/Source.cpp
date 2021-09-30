//question 1:
#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	int n;
	int m;
	bool flag = false;
	cout << "enter your number"<<endl;
	cin >> n;
	while (n >= 1) {
		m = n % 10;
		n = n / 10;
		if (m == 0 && flag == false) {

		}

		else {
			flag = true;
			cout << m;

		}
	}
	_getch();
	return(0);




}