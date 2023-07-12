//============================================================================
// Name        : Tic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define SIZE 3

bool checkgameover = false;
bool checkwin = false;
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
int player = 1;

void printboard(){
	cout <<"------------" << endl;
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			cout << "| " << board[i][j] << " ";
		}
		cout <<"|" << endl;
		cout <<"------------" << endl;
	}
}

void update(){
	if(player % 2 != 0){
		player = 1;
	}
	else player = 2;
	char dau;
	if(player == 1){
		dau = 'X';
	}
	else dau = 'O';

	int x, y;
	do{
		cout << "\nNguoi choi " << player <<" hay chon o de di: ";
		cin >> x >> y;
	}
	while(x > 2 || y > 2 || board[x][y] != ' ');

	if(board[x][y] == ' '){
		board[x][y] = dau;
	}
	player++;
}

bool check()
{
	if (board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2])
		return true;
	else if (board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2])
		return true;
	else if (board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2])
		return true;
	else if (board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0])
		return true;
	else if (board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] == board[2][1])
		return true;
	else if (board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2])
		return true;
	else if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return true;
	else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return true;
	else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
		board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
		board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
	{
		checkwin = true;
		return true;
	}
	return false;
}

int main() {
	cout << "\t TIC TAC TOE" << endl;
	cout << "Nguoi choi 1 = [X] \t Nguoi choi 2 = [O]\n" << endl;

	while (!checkgameover)
	{
		update();
		printboard();
		checkgameover = check();

		if (checkgameover)
		{
			if (checkwin)
				cout << "----- HOA NHAU -----";
			else
				cout << "-----Nguoi choi " << --player << " la nguoi chien thang-----" << endl;
		}
	}
	return 0;
}


