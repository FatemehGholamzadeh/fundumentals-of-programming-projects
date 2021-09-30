//question 3:
#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	int a, b, c, d;//figures of hossein's number
	int m, n, o, p;//figures of mehdi's number
	int t;
	int x;//hossein's number
	int y;//Mehdi's number
	int i = 0;
	cout << "Hossein!please your number"<<endl ;
	cin >> x;
	cout <<endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	d = x % 10;
	c = x / 10 % 10;
	b = x / 100 % 10;
	a = x / 1000 % 10;
	while (i < 10) {
		t = 0;
		cout << "Mehdi!please your guess number" << endl;
		cin >> y;
		m = y % 10;
		n = y / 10 % 10;
		o = y / 100 % 10;
		p = y / 1000 % 10;
		if (a == p) {
			t = t + 1;
			cout << "*";
		}
		else if (p == b || p == c || p == d) {
			cout << "+";
		}
		else cout << "-";
		if (o == b) {
			t = t + 1;
			cout << "*";
		}
		else if (o == a || o == c || o == d) {
			cout << "+";
		}
		else cout << "-";
		if (n == c) {
			t = t + 1;
			cout << "*";
		}
		else if (n == a || n == b || n == d) {
			cout << "+";
		}
		else cout << "-";
		if (m == d) {
			t = t + 1;
			cout << "*" << endl;
		}
		else if (m == c || m == a || m == b) {
			cout << "+" << endl;
		}
		else cout << "-" << endl;


		if (t < 4) {
			i = i + 1;
		}
		else cout << "you win"<<endl;

	}
		_getch();
		return(0);









}
