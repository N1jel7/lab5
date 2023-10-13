#include <iostream>
#include <Windows.h>

using namespace std;

const int X_INDEX = 0;
const int Y_INDEX = 1;

const char FIRST_PLAYER = 'X';
const char SECOND_PLAYER = 'Y';
const char EMPTY = ' ';

void display();
bool secondPlayer();
bool firstPlayer();
char findWinner();

char field[3][3] = {

	{EMPTY, EMPTY, EMPTY},
	{EMPTY, EMPTY, EMPTY},
	{EMPTY, EMPTY, EMPTY}

};

int* defineCord(int cellNumber) {
	int cord[2] = {0,0};
	switch (cellNumber) {
	case 1: {cord[X_INDEX] = 0; cord[Y_INDEX] = 0; break; }
		case 2: {cord[X_INDEX] = 0; cord[Y_INDEX] = 1; break; }
		case 3: {cord[X_INDEX] = 0; cord[Y_INDEX] = 2; break; }
		case 4: {cord[X_INDEX] = 1; cord[Y_INDEX] = 0; break; }
		case 5: {cord[X_INDEX] = 1; cord[Y_INDEX] = 1; break; }
		case 6: {cord[X_INDEX] = 1; cord[Y_INDEX] = 2; break; }
		case 7: {cord[X_INDEX] = 2; cord[Y_INDEX] = 0; break; }
		case 8: {cord[X_INDEX] = 2; cord[Y_INDEX] = 1; break; }
		case 9: {cord[X_INDEX] = 2; cord[Y_INDEX] = 2; break; }
		default: {cord[X_INDEX] = 0; cord[Y_INDEX] = 0; }
	}

	return cord;
}


int main(){
	system("color 8");
	char winner = EMPTY;

	while (winner == EMPTY) {
		display();

		while (!firstPlayer()) {}
		winner = findWinner();
		if (winner != EMPTY) break;

		display();

		while (!secondPlayer()) {}
		winner = findWinner();

		display();
	}

	system("cls");

	cout << "\n\tПобедил игрок c символом: " << winner << "\n";

}

bool firstPlayer() {
	cout << "\nНумерация игрового поля: \n \n" << "\t [1] [2] [3] \n\t [4] [5] [6] \n\t [7] [8] [9]\n \n";

	int cellNumber = 0;
	cout << "Ходит 1 игрок." << endl << "Введите номер ячейки: ";
	cin >> cellNumber;
	int* cord = defineCord(cellNumber);
	int x = cord[X_INDEX];
	int y = cord[Y_INDEX];

	if (field[x][y] == EMPTY) {
		field[x][y] = FIRST_PLAYER;
		return true;
	}
	else {
		return false;
	}
}

bool secondPlayer() {
	cout << "\nНумерация игрового поля: \n \n" << "\t [1] [2] [3] \n\t [4] [5] [6] \n\t [7] [8] [9]\n \n";

	int cellNumber = 0;
	cout << "Ходит 2 игрок." << endl << "Введите номер ячейки: ";
	cin >> cellNumber;
	int* cord = defineCord(cellNumber);
	int x = cord[X_INDEX];
	int y = cord[Y_INDEX];

	if (field[x][y] == EMPTY) {
		field[x][y] = SECOND_PLAYER;
		return true;
	}
	else {
		return false;
	}
}

char findWinner() {
	char winner = EMPTY;
	if (field[0][0] != EMPTY) {
		if (field[0][0] == field[0][1] && field[0][1] == field[0][2]) winner = field[0][0];
		if (field[0][0] == field[1][0] && field[1][0] == field[2][0]) winner = field[0][0];
	}
	if (field[1][1] != EMPTY) {
		if (field[1][0] == field[1][1] && field[1][1] == field[1][2]) winner = field[1][1];
		if (field[0][1] == field[1][1] && field[1][1] == field[2][1]) winner = field[1][1];

		if (field[0][2] == field[1][1] && field[1][1] == field[2][0]) winner = field[1][1];
		if (field[0][0] == field[1][1] && field[1][1] == field[2][2]) winner = field[1][1];
	}
	if (field[2][2] != EMPTY) {
		if (field[2][2] == field[1][2] && field[1][2] == field[0][2]) winner = field[2][2];
		if (field[2][2] == field[2][1] && field[2][1] == field[2][0]) winner = field[2][2];
	}
	return winner;;
}

void display()
{
	system("cls");
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout.width(3);
			cout << field[i][j];
			cout.width(3);
			cout << '|';
		}
		cout << '\n';
		cout << "------------------";
		cout << '\n';
	}
}
