#include <string>
#include <iostream>
#include<conio.h>
#include<fstream>
#include <windows.h>
#include<time.h>
using namespace std;
int strongnumber = 0;
int last_power = 0;
void action();
void makepowers();
void printpowers();
void tankHitpower();
void shoottotank();
void printMap();
void follow();
void save();
void load();
void loadMap(char *);
void placeTanks();
void gotoxy(int x, int y);
void printTanks(bool);
void printShoots(bool);
bool tankHittank(int);
bool hitTank(int);
bool hitBlock(int);
bool bordFinished(int);
void shootDestroy(int);
void cleanMap();
void drawMap();
void move();
void moveTanks();
void moveShoots();
char map[30][120];
struct power {
	int x;
	int y;
	int type;
	bool isachive = true;
};
power powers[1000];
struct shoot {
	int x;
	int y;
	int bord = 20;
	int direction;
	int distance = 0;
};
struct tank {
	int x;
	int y;
	int direction;
	int color;
	shoot shoot;
	bool shooted = false;
	int health = 100;
	bool isLive = true;
};
tank tanks[4];
int main() {
	srand(time(0));
	loadMap("map1.txt");
	placeTanks();
	printMap();
	while (tanks[0].isLive) {
		cleanMap();
		action();
		follow();
		drawMap();
		tankHitpower();
		makepowers();
		printpowers();
		Sleep(100);
	}
	if (!(tanks[0].isLive)) {
		gotoxy(60, 15);
		Sleep(500);
		cout << "YOU LOST!";
	}
	if (!(tanks[1].isLive) && !(tanks[2].isLive) && !(tanks[3].isLive)) {
		gotoxy(60, 15);
		Sleep(500);
		cout << "YOU WIN!";
	}
	_getch();
	return 0;
}

void printMap() {
	for (int i = 0;i < 30;i++) {
		for (int j = 0;j < 120;j++) {
			char c = ' ';
			switch (map[i][j])
			{
			case '2':
				c = 178;
				break;

			case '1':
				c = 176;
				break;

			case '0':
				c = 32;

			}
			cout << c;
		}
	}
}



void printTanks(bool shouldremove) {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 4; i++) {
		if (tanks[i].isLive) {
			if (shouldremove) {
				SetConsoleTextAttribute(hstdout, 0);
			}
			else {
				SetConsoleTextAttribute(hstdout, tanks[i].color);
			}
			switch (tanks[i].direction) {
			case 77:
				gotoxy(tanks[i].x, tanks[i].y);
				cout << (char)219;
				gotoxy(tanks[i].x, tanks[i].y - 1);
				cout << (char)219;
				gotoxy(tanks[i].x, tanks[i].y + 1);
				cout << (char)219;
				gotoxy(tanks[i].x + 1, tanks[i].y);
				cout << (char)219;
				gotoxy(tanks[i].x - 1, tanks[i].y - 1);
				cout << (char)219;
				gotoxy(tanks[i].x - 1, tanks[i].y + 1);
				cout << (char)219;
				break;

			case 72:

				gotoxy(tanks[i].x, tanks[i].y);
				cout << (char)219;
				gotoxy(tanks[i].x - 1, tanks[i].y + 1);
				cout << (char)219;
				gotoxy(tanks[i].x + 1, tanks[i].y + 1);
				cout << (char)219;
				gotoxy(tanks[i].x, tanks[i].y - 1);
				cout << (char)219;
				gotoxy(tanks[i].x - 1, tanks[i].y);
				cout << (char)219;
				gotoxy(tanks[i].x + 1, tanks[i].y);
				cout << (char)219;
				break;

			case 80:

				gotoxy(tanks[i].x, tanks[i].y);
				cout << (char)219;
				gotoxy(tanks[i].x - 1, tanks[i].y - 1);
				cout << (char)219;
				gotoxy(tanks[i].x + 1, tanks[i].y - 1);
				cout << (char)219;
				gotoxy(tanks[i].x, tanks[i].y + 1);
				cout << (char)219;
				gotoxy(tanks[i].x - 1, tanks[i].y);
				cout << (char)219;
				gotoxy(tanks[i].x + 1, tanks[i].y);
				cout << (char)219;
				break;

			case 75:

				gotoxy(tanks[i].x, tanks[i].y);
				cout << (char)219;
				gotoxy(tanks[i].x, tanks[i].y + 1);
				cout << (char)219;
				gotoxy(tanks[i].x, tanks[i].y - 1);
				cout << (char)219;
				gotoxy(tanks[i].x - 1, tanks[i].y);
				cout << (char)219;
				gotoxy(tanks[i].x + 1, tanks[i].y + 1);
				cout << (char)219;
				gotoxy(tanks[i].x + 1, tanks[i].y - 1);
				cout << (char)219;
				break;
			}
			SetConsoleTextAttribute(hstdout, 0x0F);
		}
	}
}



void loadMap(char *file_name) {
	ifstream myReadFile;
	myReadFile.open(file_name);
	if (myReadFile.is_open()) {
		string line;
		int i = 0;
		while (!myReadFile.eof()) {
			getline(myReadFile, line);
			for (int j = 0; j < 120; j++) {
				map[i][j] = line[j];
			}
			i++;
		}
	}
	myReadFile.close();
}

void placeTanks() {

	tanks[0].x = 10;
	tanks[0].y = 10;
	tanks[0].color = 2;
	tanks[1].x = 100;
	tanks[1].y = 15;
	tanks[1].color = 3;
	tanks[2].x = 25;
	tanks[2].y = 25;
	tanks[2].color = 4;
	tanks[3].x = 100;
	tanks[3].y = 20;
	tanks[3].color = 5;
	tanks[0].direction = 77;
	tanks[1].direction = 75;
	tanks[2].direction = 77;
	tanks[3].direction = 75;

}
void action() {
	if (_kbhit()) {
		char c;//character that user enters
		c = _getch();
		if ((int)c < 0)
		{
			c = _getch();
		}
		if (c == 72 || c == 77 || c == 75 || c == 80) {
			tanks[0].direction = c;
		}



		if (c == ' ' && tanks[0].shooted == false) {

			tanks[0].shoot.direction = tanks[0].direction;
			tanks[0].shooted = true;
			tanks[0].shoot.x = tanks[0].x;
			tanks[0].shoot.y = tanks[0].y;


		}
		if (c == 's') {
			save();
		}

		if (c == 'l') {
			load();
		}

	}
	move();

   
}
void printShoots(bool shouldremove) {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 4; i++) {
		if(tanks[i].isLive)
		if (tanks[i].shooted) {
			gotoxy(tanks[i].shoot.x, tanks[i].shoot.y);
			SetConsoleTextAttribute(hstdout, shouldremove ? 0 : tanks[i].color);
			cout << (char)219;
			SetConsoleTextAttribute(hstdout, 0x0F);
		}
	}
}

bool hitBlock(int i) {
	if (map[tanks[i].shoot.y][tanks[i].shoot.x] == '1') {
		map[tanks[i].shoot.y][tanks[i].shoot.x] = '0';
		gotoxy(tanks[i].shoot.x, tanks[i].shoot.y);
		cout << ' ';
		shootDestroy(i);
		return true;
	}
	if (map[tanks[i].shoot.y][tanks[i].shoot.x] == '2') {
		shootDestroy(i);
		return true;
	}
	return false;
}


bool hitTank(int i)
{

	if (i == 0) {
		for (int k = 1;k < 4;k++) {
			switch (tanks[k].direction) {
			case 77:
				if (tanks[0].shoot.x == tanks[k].x &&  tanks[0].shoot.y == tanks[k].y
					|| tanks[0].shoot.x == tanks[k].x + 1 && tanks[0].shoot.y == tanks[k].y
					|| tanks[0].shoot.x == tanks[k].x &&  tanks[0].shoot.y == tanks[k].y + 1
					|| tanks[0].shoot.x == tanks[k].x &&  tanks[0].shoot.y == tanks[k].y - 1
					|| tanks[0].shoot.x == tanks[k].x - 1 && tanks[0].shoot.y == tanks[k].y + 1
					|| tanks[0].shoot.x == tanks[k].x - 1 && tanks[0].shoot.y == tanks[k].y - 1
					) {
					tanks[k].health = tanks[k].health - 40;
					if (tanks[k].health <= 0) {
						tanks[k].isLive = false;

					}
					shootDestroy(0);
					return true;

				}

			case 72:
				if (tanks[0].shoot.x == tanks[k].x &&  tanks[0].shoot.y == tanks[k].y
					|| tanks[0].shoot.x == tanks[k].x + 1 && tanks[0].shoot.y == tanks[k].y
					|| tanks[0].shoot.x == tanks[k].x + 1 && tanks[0].shoot.y == tanks[k].y + 1
					|| tanks[0].shoot.x == tanks[k].x &&  tanks[0].shoot.y == tanks[k].y - 1
					|| tanks[0].shoot.x == tanks[k].x - 1 && tanks[0].shoot.y == tanks[k].y
					|| tanks[0].shoot.x == tanks[k].x - 1 && tanks[0].shoot.y == tanks[k].y + 1

					) {
					tanks[k].health = tanks[k].health - 40;
					if (tanks[k].health <= 0) {
						tanks[k].isLive = false;

					}
					shootDestroy(0);
					return true;

				}

			case 80:
				if (tanks[0].shoot.x == tanks[k].x &&  tanks[0].shoot.y == tanks[k].y
					|| tanks[0].shoot.x == tanks[k].x + 1 && tanks[0].shoot.y == tanks[k].y
					|| tanks[0].shoot.x == tanks[k].x + 1 && tanks[0].shoot.y == tanks[k].y - 1
					|| tanks[0].shoot.x == tanks[k].x &&  tanks[0].shoot.y == tanks[k].y + 1
					|| tanks[0].shoot.x == tanks[k].x - 1 && tanks[0].shoot.y == tanks[k].y
					|| tanks[0].shoot.x == tanks[k].x - 1 && tanks[0].shoot.y == tanks[k].y - 1

					) {
					tanks[k].health = tanks[k].health - 40;
					if (tanks[k].health <= 0) {
						tanks[k].isLive = false;

					}
					shootDestroy(0);
					return true;

				}
			case 75:
				if (tanks[0].shoot.x == tanks[k].x &&  tanks[0].shoot.y == tanks[k].y
					|| tanks[0].shoot.x == tanks[k].x + 1 && tanks[0].shoot.y == tanks[k].y - 1
					|| tanks[0].shoot.x == tanks[k].x + 1 && tanks[0].shoot.y == tanks[k].y + 1
					|| tanks[0].shoot.x == tanks[k].x &&  tanks[0].shoot.y == tanks[k].y - 1
					|| tanks[0].shoot.x == tanks[k].x - 1 && tanks[0].shoot.y == tanks[k].y
					|| tanks[0].shoot.x == tanks[k].x  && tanks[0].shoot.y == tanks[k].y + 1

					) {
					tanks[k].health = tanks[k].health - 40;
					if (tanks[k].health <= 0) {
						tanks[k].isLive = false;

					}
					shootDestroy(0);
					return true;

				}

			}

		}
	}









	if (i != 0) {
		for (int k = 1;k < 4;k++) {
			switch (tanks[k].direction) {
			case 77:
				if (tanks[k].shoot.x == tanks[0].x &&  tanks[0].shoot.y == tanks[k].y
					|| tanks[k].shoot.x == tanks[0].x + 1 && tanks[0].shoot.y == tanks[k].y
					|| tanks[k].shoot.x == tanks[0].x &&  tanks[0].shoot.y == tanks[k].y + 1
					|| tanks[k].shoot.x == tanks[0].x &&  tanks[0].shoot.y == tanks[k].y - 1
					|| tanks[k].shoot.x == tanks[0].x - 1 && tanks[0].shoot.y == tanks[k].y + 1
					|| tanks[k].shoot.x == tanks[0].x - 1 && tanks[0].shoot.y == tanks[k].y - 1
					) {
					tanks[k].health = tanks[k].health - 40;
					if (tanks[0].health <= 0) {
						tanks[0].isLive = false;

					}
					shootDestroy(k);
					return true;

				}

			case 72:
				if (tanks[k].shoot.x == tanks[0].x &&  tanks[0].shoot.y == tanks[0].y
					|| tanks[k].shoot.x == tanks[0].x + 1 && tanks[k].shoot.y == tanks[0].y
					|| tanks[k].shoot.x == tanks[0].x + 1 && tanks[k].shoot.y == tanks[0].y + 1
					|| tanks[k].shoot.x == tanks[0].x &&  tanks[k].shoot.y == tanks[0].y - 1
					|| tanks[k].shoot.x == tanks[0].x - 1 && tanks[k].shoot.y == tanks[0].y
					|| tanks[k].shoot.x == tanks[0].x - 1 && tanks[k].shoot.y == tanks[0].y + 1

					) {
					tanks[0].health = tanks[0].health - 40;
					if (tanks[0].health <= 0) {
						tanks[0].isLive = false;

					}
					shootDestroy(k);
					return true;

				}

			case 80:
				if (tanks[0].shoot.x == tanks[k].x &&  tanks[k].shoot.y == tanks[0].y
					|| tanks[k].shoot.x == tanks[0].x + 1 && tanks[k].shoot.y == tanks[0].y
					|| tanks[k].shoot.x == tanks[0].x + 1 && tanks[k].shoot.y == tanks[0].y - 1
					|| tanks[k].shoot.x == tanks[0].x &&  tanks[k].shoot.y == tanks[0].y + 1
					|| tanks[k].shoot.x == tanks[0].x - 1 && tanks[k].shoot.y == tanks[0].y
					|| tanks[k].shoot.x == tanks[0].x - 1 && tanks[k].shoot.y == tanks[0].y - 1

					) {
					tanks[0].health = tanks[0].health - 40;
					if (tanks[0].health <= 0) {
						tanks[0].isLive = false;

					}
					shootDestroy(k);
					return true;

				}
			case 75:
				if (tanks[k].shoot.x == tanks[0].x &&  tanks[0].shoot.y == tanks[k].y
					|| tanks[k].shoot.x == tanks[0].x + 1 && tanks[k].shoot.y == tanks[0].y - 1
					|| tanks[k].shoot.x == tanks[0].x + 1 && tanks[k].shoot.y == tanks[0].y + 1
					|| tanks[k].shoot.x == tanks[0].x &&  tanks[k].shoot.y == tanks[0].y - 1
					|| tanks[k].shoot.x == tanks[0].x - 1 && tanks[k].shoot.y == tanks[0].y
					|| tanks[k].shoot.x == tanks[0].x  && tanks[k].shoot.y == tanks[0].y + 1

					) {
					tanks[0].health = tanks[0].health - 40;
					if (tanks[0].health <= 0) {
						tanks[0].isLive = false;

					}
					shootDestroy(k);
					return true;

				}

			}

		}
	}
	return false;
}
void move() {

	moveTanks();
	moveShoots();

}

void moveTanks() {
	for (int i = 0;i < 4;i++) {
		switch (tanks[i].direction) {
		case 77:
			if (map[tanks[i].y][tanks[i].x + 2] == '0'
				&& map[tanks[i].y + 1][tanks[i].x + 2] == '0'
				&& map[tanks[i].y - 1][tanks[i].x + 2] == '0'
				&& !(tankHittank(i)))
			{
				tanks[i].x++;
			}

			break;

		case 72:
			if (map[tanks[i].y - 2][tanks[i].x] == '0'
				&& map[tanks[i].y - 2][tanks[i].x + 1] == '0'
				&& map[tanks[i].y - 2][tanks[i].x - 1] == '0'
				&& !(tankHittank(i))

				) {
				tanks[i].y--;

			}

			break;

		case 80:
			if (map[tanks[i].y + 2][tanks[i].x] == '0'
				&& map[tanks[i].y + 2][tanks[i].x + 1] == '0'
				&& map[tanks[i].y + 2][tanks[i].x - 1] == '0'
				&& !(tankHittank(i))

				) {
				tanks[i].y++;

			}

			break;

		case 75:
			if (map[tanks[i].y][tanks[i].x - 2] == '0'
				&& map[tanks[i].y + 1][tanks[i].x - 2] == '0'
				&& map[tanks[i].y - 1][tanks[i].x - 2] == '0'
				&& !(tankHittank(i))
				) {
				tanks[i].x--;

			}

			break;
		}
	}
}




void moveShoots() {
	for (int i = 0;i < 4;i++) {
		if (tanks[i].shooted) {
			for (int j = 0; j < 4; j++) {
				switch (tanks[i].shoot.direction) {
				case 77:
					tanks[i].shoot.x++;
					break;
				case 72:
					tanks[i].shoot.y--;
					break;
				case 75:
					tanks[i].shoot.x--;;
					break;
				case 80:
					tanks[i].shoot.y++;
					break;
				}
				tanks[i].shoot.distance++;
				if (hitBlock(i) || hitTank(i) || bordFinished(i)) {
					break;
				}
			}
		}
	}
}

void cleanMap() {
	gotoxy(0, 0);
	printShoots(true);
	printTanks(true);
}
void drawMap() {
	printShoots(false);
	printTanks(false);
}
void gotoxy(int x, int y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

bool bordFinished(int i) {
	if (tanks[i].shoot.distance >= tanks[i].shoot.bord) {
		shootDestroy(i);
		return true;
	}
	return false;
}

void shootDestroy(int i) {
	tanks[i].shooted = false;
	tanks[i].shoot.distance = 0;
}
bool tankHittank(int j) {
	int arr[4][6][2];
	int x, y;
	for (int i = 0;i < 4;i++) {


		switch (tanks[i].direction) {
		case 72:
			y = tanks[i].y;
			if (i == j)
			{
				y--;
			}
			arr[i][0][0] = tanks[i].x;
			arr[i][0][1] = y;
			arr[i][1][0] = tanks[i].x;
			arr[i][1][1] = y - 1;
			arr[i][2][0] = tanks[i].x + 1;
			arr[i][2][1] = y;
			arr[i][3][0] = tanks[i].x + 1;
			arr[i][3][1] = y + 1;
			arr[i][4][0] = tanks[i].x - 1;
			arr[i][4][1] = y;
			arr[i][5][0] = tanks[i].x - 1;
			arr[i][5][1] = y + 1;
			break;
		case 80:
			y = tanks[i].y;
			if (i == j)
			{
				y++;
			}
			arr[i][0][0] = tanks[i].x;
			arr[i][0][1] = y;
			arr[i][1][0] = tanks[i].x;
			arr[i][1][1] = y + 1;
			arr[i][2][0] = tanks[i].x + 1;
			arr[i][2][1] = y;
			arr[i][3][0] = tanks[i].x + 1;
			arr[i][3][1] = y - 1;
			arr[i][4][0] = tanks[i].x - 1;
			arr[i][4][1] = y;
			arr[i][5][0] = tanks[i].x - 1;
			arr[i][5][1] = y + 1;
			break;
		case 75:
			x = tanks[i].x;
			if (i == j)
			{
				x--;
			}
			arr[i][0][0] = x;
			arr[i][0][1] = tanks[i].y;
			arr[i][1][0] = x - 1;
			arr[i][1][1] = tanks[i].y;
			arr[i][2][0] = x;
			arr[i][2][1] = tanks[i].y - 1;
			arr[i][3][0] = x + 1;
			arr[i][3][1] = tanks[i].y - 1;
			arr[i][4][0] = x;
			arr[i][4][1] = tanks[i].y + 1;
			arr[i][5][0] = x + 1;
			arr[i][5][1] = tanks[i].y + 1;
			break;
		case 77:
			x = tanks[i].x;
			if (i == j)
			{
				x++;
			}
			arr[i][0][0] = x;
			arr[i][0][1] = tanks[i].y;
			arr[i][1][0] = x + 1;
			arr[i][1][1] = tanks[i].y;
			arr[i][2][0] = x;
			arr[i][2][1] = tanks[i].y - 1;
			arr[i][3][0] = x - 1;
			arr[i][3][1] = tanks[i].y - 1;
			arr[i][4][0] = x;
			arr[i][4][1] = tanks[i].y + 1;
			arr[i][5][0] = x - 1;
			arr[i][5][1] = tanks[i].y + 1;
			break;
		}
	}
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 6;j++) {
			for (int m = 0;m < 4;m++) {
				for (int n = 0;n < 6;n++) {
					if (i == m)
						continue;
					if(m==0 || i==0){
						if (arr[i][j][0] == arr[m][n][0]
							&&
							arr[i][j][1] == arr[m][n][1]
							) {
							return true;

						}
					}
				}
			}
		}
	}
	return false;

}

void makepowers() {
	if (strongnumber < 2) {
		powers[last_power].x = rand() % 115 + 2;
		powers[last_power].y = rand() % 25 + 2;
		powers[last_power].type = rand() % 4 + 1;
		powers[last_power].isachive = false;
		strongnumber++;
		last_power++;
	}
}

void printpowers() {

	for (int i = 0;i < last_power;i++) {
		if (!(powers[i].isachive)) {
			gotoxy(powers[i].x, powers[i].y);
			cout << powers[i].type;
		}
	}

}


void tankHitpower() {
	for (int j = 0;j < last_power;j++) {
		for (int i = 0;i < 4;i++) {
			if (tanks[i].x == powers[j].x
				&& tanks[i].y == powers[j].y)
			{
				powers[j].isachive = true;
				switch (powers[j].type) {
				case 1:
					if (i == 0)
						tanks[0].health += 100;
				case 2:
					tanks[i].health += 50;
				case 4:
					tanks[i].shoot.bord += 5;

				}
				strongnumber--;
			}
		}
	}
}

void save() 
{
	fstream mywriteFile;
	mywriteFile.open("save.txt");
	if (mywriteFile.is_open()) {
		for (int i = 0;i < 30;i++) {
			for (int j = 0;j < 120;j++) {
				mywriteFile << map[i][j];
			}
			mywriteFile << endl;
		}
		for (int i = 0;i < 4;i++) {
			mywriteFile << tanks[i].x<<endl;
			mywriteFile << tanks[i].y<<endl;
			mywriteFile << tanks[i].direction << endl;
			mywriteFile << tanks[i].color << endl;
			mywriteFile << tanks[i].health << endl;
			mywriteFile << tanks[i].isLive << endl;
			mywriteFile << tanks[i].shooted << endl;



		}
	}
	mywriteFile.close();
}
void load() {
	ifstream myReadFile;
	myReadFile.open("save.txt");
	
	if (myReadFile.is_open()) {
		string line = "";
		//while (!myReadFile.eof()) {
			
			for (int k = 0;k < 30;k++) {
				myReadFile >> line;
				for (int j = 0; j < 120; j++) {
					map[k][j] = line[j];
				}
			}
			for (int i = 0;i < 4;i++) {
				myReadFile >> tanks[i].x;
				myReadFile >> tanks[i].y;
				myReadFile >> tanks[i].direction;
				myReadFile >> tanks[i].color;
				myReadFile >> tanks[i].health;
				myReadFile >> tanks[i].isLive;
				myReadFile >> tanks[i].shooted;
			}
		//}
	}
	myReadFile.close();

}


void shoottotank() {
	for (int i = 1;i < 4;i++) {
		int deltax = tanks[0].x - tanks[i].x;
		int deltay = tanks[0].y - tanks[i].y;
		if (deltax <= 0 && deltay <= 0) {
			if (deltax <= deltay) {
				while (deltax <= 0) {
					tanks[i].direction = 75;
				}
				tanks[i].direction = 72;
			}
			if (deltax >= deltay) {
				while (deltay <= 0) {
					tanks[i].direction = 72;
				}
				tanks[i].direction = 75;
			}
		}
	}
}





void follow() {
	for (int i = 1;i < 4;i++) {
		int deltax = tanks[0].x - tanks[i].x;
		int deltay = tanks[0].y - tanks[i].y;
		if (deltax < 0) {
			tanks[i].direction = 75;
		}
		if (deltax == 0 && deltay<0) {
			tanks[i].direction = 72;
			tanks[i].shoot.direction = tanks[i].direction;
			tanks[i].shooted = true;
			tanks[i].shoot.x = tanks[i].x;
			tanks[i].shoot.y = tanks[i].y;
			printShoots(1);
		}
		if (deltax == 0 && deltay>0) {
			tanks[i].direction = 80;
			tanks[i].shoot.direction = tanks[i].direction;
			tanks[i].shooted = true;
			tanks[i].shoot.x = tanks[i].x;
			tanks[i].shoot.y = tanks[i].y;
			printShoots(1);

		}
		
		
		if (deltax == 0 && deltay < 0) {
			tanks[i].direction = 72;
			tanks[i].shoot.direction = tanks[i].direction;
			tanks[i].shooted = true;
			tanks[i].shoot.x = tanks[i].x;
			tanks[i].shoot.y = tanks[i].y;
			printShoots(1);

		}
		if (deltax == 0 && deltay > 0) {
			tanks[i].direction = 80;
			tanks[i].shoot.direction = tanks[i].direction;
			tanks[i].shooted = true;
			tanks[i].shoot.x = tanks[i].x;
			tanks[i].shoot.y = tanks[i].y;
			printShoots(1);

		}
		if (deltay == 0 && deltax > 0) {
			tanks[i].direction = 77;
			tanks[i].shoot.direction = tanks[i].direction;
			tanks[i].shooted = true;
			tanks[i].shoot.x = tanks[i].x;
			tanks[i].shoot.y = tanks[i].y;
			printShoots(1);

		}
		if (deltay == 0 && deltax < 0) {
			tanks[i].direction = 75;
			tanks[i].shoot.direction = tanks[i].direction;
			tanks[i].shooted = true;
			tanks[i].shoot.x = tanks[i].x;
			tanks[i].shoot.y = tanks[i].y;
			printShoots(1);

		}

	}
}