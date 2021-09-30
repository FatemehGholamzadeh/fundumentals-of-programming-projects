#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	int n, x;
	cout<<"enter n "<<endl;
	cin >> n;
	cout<<"enter x"<<endl;
	cin>>x;
	int a = x;
	int s = x;
	int i = 3;
	while(i<=2*n-1) {

		a = a*x*x*(-1);
		s = s + a / i;
		i = i + 2;

	}
	cout<<"the answer is:"<<s;
	_getch();
	return(0);
}