#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void enqueue(int data);
void dequeue(int *data);
int * peek();
bool isEmpty();
bool isFull();
int *tail;
int *head;
int Q[10];
int main()
{
	
	tail = &Q[0];
	head = &Q[0];
	char str[10];
		cin >> str;
		while ((strcmp(str, "quit"))) {
			if (!(strcmp(str, "isempty"))) {
				isEmpty();
			}
			else if (!(strcmp(str, "enqueue"))) {
				int x;//number that must be entered to the queue
				cout << "please enter the number you wanna enqueue:" << endl;
				cin >> x;
				enqueue(x);
				cout << "OK,adding" << x << "to the queue..." << endl;
			}
			else if (!(strcmp(str, "dequeue"))) {
				int x;//number that must be out of the queue
				cout << "please enter the number you wanna dequeue:" << endl;
				cin >> x;
				dequeue(&x);
				cout << "OK,dequeued" << x << "from the queue" << endl;
			}
			else if (!(strcmp(str, "isfull"))) {
				if (isFull()) {
					cout << "the queue is full" << endl;
				}
				else {
					cout << "the queue is not full" << endl;

				}
			}
			else if (!(strcmp(str, "isempty"))) {
				if (isEmpty()) {
					cout << "the queue is empty" << endl;
				}
				else {
					cout << "the queue is not empty" << endl;

				}
			}
			else 
				cout<<"please enter one of these(quite,enqueue,dequeue,...)"<<endl;
				cout<<"please enter your next choice"<<endl;
			cin >>str;

		
		}
	_getch();
	return 0;
}
void enqueue(int data) {
	if (isFull()) {
		cout << "the queue is Full!";
	}
	else {
		*head = data;
		head++;
	}
}
void dequeue(int *data) {
	if (isEmpty()) {
		cout << "the queue is empty";
	}
	else {
		*data = *tail;
		tail++;
	}
}
bool isEmpty() {
	if (tail == head) {
		cout << "the queue is empty" << endl;
		return true;
	}
	else { 
		cout << "queue is not empty"<<endl;
		return false;
	}
}
int * peek() {
	if (isEmpty())
		return NULL;
	cout << *tail;
	return tail;
}
bool isFull() {
	if (head == & Q[9] || head < tail)
		return true;
	else return false;
}