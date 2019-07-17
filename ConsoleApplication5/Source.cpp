#include<iostream>
#include<conio.h>
#include <windows.h>
#include<string.h>
using namespace std;
int main()
{
	char word[100];//arraye e ke character haye str ra joda joda daryaft mikonad
	int word_i = 0;//counter of word array cells
	int j = 0;//counter of num array
	double num[100];//array that contain numbers
	char str[100];//array that gets characters from user
	bool isx = false;//to check if there is x in the array str or not
	cout << "please enter an expression:" << endl;
	cin.getline(str, 100);
	
	for (int i = 0;i < strlen(str);i++) {
		if (str[i] != ' ') {
			word[word_i] = str[i];
			word_i++;
			if (i + 1 < strlen(str))
				continue;
		}
		word[word_i] = '\0';
		word_i = 0;
		if (strlen(word) == 1 && !(word[0] >= '0'&& word[0] <= '9')&& word[0]!='x') {
			if (word[0] == '+') {
				num[j - 2] = num[j-2] + num[j - 1];
				j=j--;
			}
			if (word[0] == '-')
			{
				num[j - 2] = num[j - 2] - num[j - 1];
				j=j--;
			}
			if (word[0] == '*')
			{
				num[j - 2] = num[j - 2] * num[j - 1];
				j=j--;
			}
			if (word[0] == '/')
			{
				num[j - 2] = num[j - 2] / num[j - 1];
				j=j--;
			}
		}
		if (word[0] == 'x') {
			cout << "please enter a value for x:" << endl;
			double a;//value of x
			cin >> a;
			num[j] = a;
			j++;
		    isx = true;

		}
		else if (!(strlen(word) == 1 && !(word[0] >= '0'&& word[0] <= '9') && word[0] != 'x')) {
			num[j] = atof(word);
			j++;
		}
	}
		cout << "result is:  "<<num[j-1]<<endl;



		while (isx) {
			cout << "do you want to enter another value? (enter y for yes and n for no)" << endl;
			char a;
			cin >> a;
			if (a == 'y') {
				for (int i = 0;i < strlen(str);i++) {
					if (str[i] != ' ') {
						word[word_i] = str[i];
						word_i++;
						if (i + 1 < strlen(str))
							continue;
					}
					word[word_i] = '\0';
					word_i = 0;
					if (strlen(word) == 1 && !(word[0] >= '0'&& word[0] <= '9') && word[0] != 'x') {
						if (word[0] == '+') {
							num[j - 2] = num[j - 2] + num[j - 1];
							j = j--;
						}
						if (word[0] == '-')
						{
							num[j - 2] = num[j - 2] - num[j - 1];
							j = j--;
						}
						if (word[0] == '*')
						{
							num[j - 2] = num[j - 2] * num[j - 1];
							j = j--;
						}
						if (word[0] == '/')
						{
							num[j - 2] = num[j - 2] / num[j - 1];
							j = j--;
						}
					}
					if (word[0] == 'x') {
						cout << "please enter a value for x:" << endl;
						double a;//value of x
						cin >> a;
						num[j] = a;
						j++;
						isx = true;

					}
					else if (!(strlen(word) == 1 && !(word[0] >= '0'&& word[0] <= '9') && word[0] != 'x')) {
						num[j] = atof(word);
						j++;
					}
				}
				cout << "result is:  " << num[j - 1] << endl;

			}
			else if (a == 'n') {
				isx = false;
			}

		}


		while (isx) {
			cout << "do you want to enter another value?(enter y for yes and n for no)" << endl;
			char a;
			cin >> a;
			if (a == 'y') {
				for (int i = 0;i < strlen(str);i++) {
					if (str[i] != ' ') {
						word[word_i] = str[i];
						word_i++;
						if (i + 1 < strlen(str))
							continue;
					}
					word[word_i] = '\0';
					word_i = 0;
					if (strlen(word) == 1 && !(word[0] >= '0'&& word[0] <= '9') && word[0] != 'x') {
						if (word[0] == '+') {
							num[j - 2] = num[j - 2] + num[j - 1];
							j = j--;
						}
						if (word[0] == '-')
						{
							num[j - 2] = num[j - 2] - num[j - 1];
							j = j--;
						}
						if (word[0] == '*')
						{
							num[j - 2] = num[j - 2] * num[j - 1];
							j = j--;
						}
						if (word[0] == '/')
						{
							num[j - 2] = num[j - 2] / num[j - 1];
							j = j--;
						}
					}
					if (word[0] == 'x') {
						cout << "please enter a value for x:" << endl;
						double a;//value of x
						cin >> a;
						num[j] = a;
						j++;
						isx = true;

					}
					else if (!(strlen(word) == 1 && !(word[0] >= '0'&& word[0] <= '9') && word[0] != 'x')) {
						num[j] = atof(word);
						j++;
					}
				}
				cout << "result is:  " << num[j - 1] << endl;

			}
			else if (a == 'n') {
				isx = false;
			}
			else {
				isx = false;
			}

		}
	_getch();
	return 0;
	
}