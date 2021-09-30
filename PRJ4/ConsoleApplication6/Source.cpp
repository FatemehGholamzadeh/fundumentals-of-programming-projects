#include<iostream>
#include<conio.h>
#include<time.h>
#include<Windows.h>
using namespace std;
char gride1[10][10] = { ' ' };
char gride2[10][10] = { ' ' };
char gride3[10][10] = { ' ' };
char gride4[10][10] = { ' ' };
void shoot(int, int, char gride[10][10],char map[10][10]);
int getx();
int gety();
int randx();
int randy();
void printMap(char gride[10][10]);
void makeMap(char map[10][10]);
void getName(int);
bool endgame(char map[10][10]);
void makeMap4(char map[10][10],char gride[10][10]);
int main() {
	srand((unsigned)time(0));
	int a = rand() % 2;
	getName(a);
	Sleep(200);
 	makeMap(gride1);
	makeMap(gride2);
	makeMap4(gride1, gride4);
	Sleep(200);
	printMap(gride3);
	printMap(gride4);
	if (a) {
		while (endgame(gride1) && endgame(gride2)) {
			shoot(getx(), gety(), gride3, gride2);
			system("cls");
			printMap(gride3);
			printMap(gride4);
			Sleep(3000);
			shoot(randx(), randy(), gride4, gride1);
			system("cls");
			printMap(gride3);
			printMap(gride4);
		}
	}
	if (!(a)) {
		while (endgame(gride1) && endgame(gride2)) {
			shoot(randx(), randy(), gride4, gride1);
			system("cls");
			printMap(gride3);
			printMap(gride4);
			Sleep(3000);
			shoot(getx(), gety(), gride3, gride2);
			system("cls");
			printMap(gride3);
			printMap(gride4);
		}
	}


	if (!(endgame(gride1))) {
		cout << "you lose!" << endl;
	}
	else if (!(endgame(gride2))) {
		cout << "you win!" << endl;
	}
	_getch();
	return 0;

}
void printMap(char map[10][10]) {
	cout << endl << "    a b c d e f g h i j " << endl;
	int a = 0;
	char f = 179;
	for (int j = 0; j < 10; j++) {

		cout << a << ' ' << f;
		a++;

		for (int i = 0; i <9; i++) {

			cout << map[j][i] << f;

		}
		cout << map[j][9] << f << endl;

		if (j != 9)
			cout << "  " << "---------------------" << endl;

	}
}
void makeMap(char gride[10][10]) {
	int l = 0;//counter
	int direction = rand() % 2;
	while (l < 1) {
		int x = (rand() % 8) + 1;
		int y = (rand() % 8) + 1;
		if (direction) {

			if (gride[x][y] != '#'
				&&  gride[x][y + 1] != '#'
				&& gride[x][y + 2] != '#'
				&& gride[x][y + 3] != '#'
				&& y + 3 < 9
				&& gride[x][y] != '~'
				&&  gride[x][y + 1] != '~'
				&& gride[x][y + 2] != '~'
				&& gride[x][y + 3] != '~'
				) {
				gride[x][y] = '#';
				gride[x][y + 1] = '#';
				gride[x][y + 2] = '#';
				gride[x][y + 3] = '#';

				for (int m = -1;m < 5;m++) {
					gride[x - 1][y + m] = '~';
				}
				for (int m = -1;m < 5;m++) {
					gride[x + 1][y + m] = '~';
				}
				gride[x][y - 1] = '~';
				gride[x][y + 4] = '~';

				l++;
			}
		}

		else if (!(direction)) {
			if (gride[x][y] != '#'
				&& gride[x + 1][y] != '#'
				&& gride[x + 2][y] != '#'
				&& gride[x + 3][y] != '#'
				&& x + 3 < 9
				&& gride[x][y] != '~'
				&& gride[x + 1][y] != '~'
				&& gride[x + 2][y] != '~'
				&& gride[x + 3][y] != '~'
				) {
				gride[x][y] = '#';
				gride[x + 1][y] = '#';
				gride[x + 2][y] = '#';
				gride[x + 3][y] = '#';
				for (int m = -1;m < 5;m++) {
					gride[x + m][y - 1] = '~';
				}
				for (int m = -1;m < 5;m++) {
					gride[x + m][y + 1] = '~';
				}
				gride[x - 1][y] = '~';
				gride[x + 4][y] = '~';


				l++;

			}
		}
	}




	int k = 0;//counter
	for (int i = 0;i < 4;i++) {
		while (k < 4) {
			int x = (rand() % 8) + 1;
			int y = (rand() % 8) + 1;
			if (gride[x][y] != '#' && gride[x][y] != '~') {
				gride[x][y] = '#';
				gride[x][y + 1] = '~';
				gride[x][y - 1] = '~';
				gride[x - 1][y] = '~';
				gride[x + 1][y] = '~';
				gride[x + 1][y + 1] = '~';
				gride[x + 1][y - 1] = '~';
				gride[x - 1][y - 1] = '~';
				gride[x - 1][y + 1] = '~';
				k++;
			}
		}
	}



	int n = 0;//counter
	int direction2 = rand() % 2;
	while (n < 1) {
		int x = (rand() % 8) + 1;
		int y = (rand() % 8) + 1;
		if (direction2) {
			if (gride[x][y] != '#'
				&& gride[x][y + 1] != '#'
				&& gride[x][y + 2] != '#'
				&& y + 2 < 9
				&& gride[x][y] != '~'
				&& gride[x][y + 1] != '~'
				&& gride[x][y + 2] != '~'
				) {
				gride[x][y] = '#';
				gride[x][y + 1] = '#';
				gride[x][y + 2] = '#';
				for (int m = -1;m < 4;m++) {
					gride[x - 1][y + m] = '~';
				}
				for (int m = -1;m < 4;m++) {
					gride[x + 1][y + m] = '~';
				}
				gride[x][y - 1] = '~';
				gride[x][y + 3] = '~';

				n++;
			}
		}

		else {
			if (gride[x][y] != '#'
				&& gride[x + 1][y] != '#'
				&& gride[x + 2][y] != '#'
				&& x + 2 < 9
				&& gride[x][y] != '~'
				&& gride[x + 1][y] != '~'
				&& gride[x + 2][y] != '~'
				) {
				gride[x][y] = '#';
				gride[x + 1][y] = '#';
				gride[x + 2][y] = '#';
				for (int m = -1;m < 4;m++) {
					gride[x + m][y - 1] = '~';
				}
				for (int m = -1;m < 4;m++) {
					gride[x + m][y + 1] = '~';
				}
				gride[x - 1][y] = '~';
				gride[x + 3][y] = '~';


				n++;
			}
		}
	}


	int o = 0;//counter
	int direction3 = rand() % 2;
	while (o < 2) {
		int x = (rand() % 8) + 1;
		int y = (rand() % 8) + 1;
		if (direction3) {
			if (gride[x][y] != '#'
				&& gride[x][y + 1] != '#'
				&& y + 1 < 9
				&& gride[x][y] != '~'
				&& gride[x][y + 1] != '~'
				) {
				gride[x][y] = '#';
				gride[x][y + 1] = '#';
				for (int m = -1;m < 3;m++) {
					gride[x - 1][y + m] = '~';
				}
				for (int m = -1;m < 3;m++) {
					gride[x + 1][y + m] = '~';
				}
				gride[x][y - 1] = '~';
				gride[x][y + 2] = '~';

				o++;
			}
		}

		else {
			if (gride[x][y] != '#'
				&& gride[x + 1][y] != '#'
				&& x + 1 < 9
				&& gride[x][y] != '~'
				&& gride[x + 1][y] != '~'
				) {
				gride[x][y] = '#';
				gride[x + 1][y] = '#';

				for (int m = -1;m < 3;m++) {
					gride[x + m][y - 1] = '~';
				}
				for (int m = -1;m < 3;m++) {
					gride[x + m][y + 1] = '~';
				}
				gride[x - 1][y] = '~';
				gride[x + 2][y] = '~';


				o++;
			}
		}
	}
}





void makeMap4(char map[10][10], char gride[10][10]) {
	for (int i = 0; i < 10; i++)
		for (int j = 0;j < 10;j++)
			if (map[i][j] == '#') {
				gride[i][j] = '#';
			}
}

void shoot(int x, int y, char gride[10][10], char map[10][10]) {
	if (map[x][y] == '#') {
		map[x][y] = '@';
		gride[x][y] = '@';
		gride[x+1][y-1] = '~';
		gride[x+1][y+1] = '~';
		gride[x-1][y-1] = '~';
		gride[x-1][y+1] = '~';

	}
	if (map[x][y] == '~') {
		map[x][y] = '.';
		gride[x][y] = '.';
		}
	if (map[x][y] == ' ') {
		map[x][y] = '.';
		gride[x][y] = '.';
	}
}








void getName(int a) {
	cout << "please enter your name:" << endl;
	char username[100];
	cin >> username;
	cout << "please enter your computer's name" << endl;
	char computername[100];
	cin >> computername;
	if (a) {
		cout << username << " should start the game!" << endl;		
	}
	else {
		cout << computername << " should start the game!" << endl;
		}

}

int getx() {
	int x;
	cout << "please enter x for shooting:" << endl;
	cin >> x;
	return x;
}
int gety() {
	int y;
	cout << "please enter y for shooting:" << endl;
	cin >> y;
	return y;
}
int randx() {
	int x;
	x = rand() % 10;
	return x;
}
int randy() {
	int y;
	y = rand() % 10;
	return y;
}
bool endgame(char map[10][10]) {
	for (int i = 0; i < 10; i++)
		for (int j = 0;j < 10;j++)
			if (map[i][j] == '#') 
				return true;
				return false;
}