#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
int main() {
	srand((unsigned)time(0));
	int fullcells = 0;
	while (fullcells < 81) {
		char table[9][9] = {
		{ '5','3','4','6','7','8','9','1','2'},
		{'6','7','2','1','9','5','3','4','8'},
		{'1','9','8','3','4','2','5','6','7'},
		{'8','5','9','7','6','1','4','2','3'},
		{'4','2','6','8','5','3','7','9','1'},
		{'7','1','3','9','2','4','8','5','6'},
		{'9','6','1','5','3','7','2','8','4'},
		{'2','8','7','4','1','9','6','3','5'},
		{'3','4','5','2','8','6','1','7','9' }
		};
		cout << "please enter number of empty cells of the table:" << endl;
		int n;//number of empty cells of the table
		cin >> n;
		fullcells = 81 - n;
		int i = 0;//shomarande adad tasadofi
		while (i < n) {
			char c = 32;
			int k = rand() % 9;
			int p = rand() % 9;
			if (table[k][p] != c) {
				table[k][p] = c;
				i++;
			}

		}
		cout << endl << " -1-2-3-4-5-6-7-8-9-" << endl;
		char ch = 'a';
		for (int j = 0; j < 9; j++) {
			cout << ch++ << " ";
			char f = 179;
			for (int i = 0; i < 8; i++) {
				cout << table[j][i] << f;

			}
			cout << table[j][8] << endl;
			if (j != 8)
				cout << "  " << "-----+-----+-----" << endl;
		}


		char x;//harfe satre number
		char y;//shomareye sotun
		cout << "Enter position" << endl;
		cin >> x >> y;
		if (x != 'a'&& x != 'b'&&x != 'c'&& x != 'd'&& x != 'e'&& x != 'f'&& x != 'g'&& x != 'h'&& x != 'i') {
			cout << "character of row should be between a and i!";
		}
		if (y != '1' && y != '8' && y != '7' && y != '6' && y != '5' && y != '4' && y != '3' && y != ' 2' && y != '9') {
			cout << " you should enter a column number between 1 and 9!";
		}
		int px = x - 97, py = y - 48;
		bool gide[9][9][10];
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				for (int k = 0;k < 9;k++) {
					gide[i][j][k] = { true };
				}

			}

		}
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				char c = 32;
				if (table[i][j] == c) {
					for (int m = 0;m < 9;m++) {
						if (table[i][m] != c) {
							int f = table[i][m] - 48;
							gide[i][m][f] = false;

						}

					}
				}
			}
		}
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				char c = 32;
				if (table[i][j] == c) {
					for (int n = 0;n < 9;n++) {
						if (table[n][j] != c) {
							int l = table[n][j] - 48;
							gide[n][j][l] = false;
						}
					}
				}
			}
		}

		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				char c = 32;
				if (table[i][j] == c) {
					int blockNumberX = i / 3;
					int blockNumberY = j / 3;
					int StartBlockX = blockNumberX * 3;
					int startBlockY = blockNumberY * 3;
					for (int a = StartBlockX; a < StartBlockX + 3; a++) {
						for (int b = startBlockY; b < startBlockY + 3; b++)
						{
							if (table[a][b] != c) {
								int w = table[a][b];
								gide[a][b][w] = false;
							}
						}

					}
				}
			}
		}
		cout << "do you want any gide?enter y for yes and n for no" << endl;
		char h;
		cin >> h;
		int t = 0;
		int num = 0;
		int satr, sotun;
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				char c = 32;
				if (table[i][j] == c) {
					for (int k = 0;k < 9;k++) {
						if (gide[i][j][k] == true) {
							t++;
							num = k;
							satr = i;
							sotun = j;
						}
						if (t == 1 && h == 'y') {
							table[satr][sotun] = num;
							fullcells++;
							cout << satr << sotun << num;
						}
					}

				}
			}
		}
		



		char number;
		cout << "Enter Number:" << endl;
		cin >> number;
		if (number != '1' && number != '8' && number != '7' && number != '6' && number != '5' && number != '4' && number != '3' && number != ' 2' && number != '9') {
			cout << " you should enter a number between 1 and 9!";
		}
		bool flag = true;
		for (int i = 0;i < 9;i++) {
			if (table[px][i] == number) {
				cout << "number'" << number << "'has already written in the same Row" << " " << x << i + 1 << endl;
				flag = false;
			}
			if (table[i][py] == number) {
				char c = i + 97;
				cout << "number'" << number << "'has already written in the same Column" << " " << c << py << endl;
				flag = false;
			}
		}
		int blockNumberX = px / 3;
		int blockNumberY = py / 3;
		int StartBlockX = blockNumberX * 3;
		int startBlockY = blockNumberY * 3;
		for (int i = StartBlockX; i < StartBlockX + 3; i++)
			for (int j = startBlockY; j < startBlockY + 3; j++)
			{
				if (number == table[i][j]) {
					char c = i + 97;
					cout << "number'" << number << "'has already written in the same block" << " " << c << j + 1;
					flag = false;
				}
			}
		if (flag) {
			cout<< "correct"<< px<< " " <<py;
			table[px][py] = number;
			fullcells++;
		}
	}
		_getch();

		return (0);
	
}