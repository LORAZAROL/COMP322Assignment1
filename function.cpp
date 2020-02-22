#include "function.h"

/**
 * Q1
 */
void greetAndInstruct() {

	cout
			<< "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer."
			<< endl;
	cout << "The board is numbered from 1 to 27 as per the following:" << endl;

	char* a = (char*) malloc(28 * sizeof(char));
	a[0] = 'E';
	for (int i = 1; i < 28; i++) {
		a[i] = i;
	}
	displayBoard(a);

	cout
			<< "Player starts first. Simply input the number of the cell you want to occupy."
			<< endl;
	cout << "Player¡¯s move is marked with X." << endl;
	cout << "Computer¡¯s move is marked with O." << endl;
	cout << "Start? (y/n):" << endl;

}

/**
 * Q2/4 helper method
 */
char* updateBoard(char board[], Cell step) {
	char* updated = (char*) malloc(sizeof(char) * 28);

	// Fill up the board array
	// Define the 0th as empty
	updated[0] = 'E';
	for (int i = 1; i <= 27; i++) {
		updated[i] = board[i];
	}

	int id = step.id;
	char cont = step.content;

	updated[id] = cont;

	return updated;
}

/**
 * helper method Q3,Q4
 */

/**
 * Q2
 */
void displayBoard(char board[]) {

	for (int i = 1; i < 22; i++) {
		if ((i % 9) == 1) {
			if (board[i] != 'O' && board[i] != 'X') {
				printf("%d | ", board[i]);
			} else {
				if(i > 9) printf("%c  | ", board[i]);
				else printf("%c | ", board[i]);
			}
			if (board[i + 1] != 'O' && board[i + 1] != 'X') {
				printf("%d | ", board[i + 1]);
			} else {
				if(i > 9) printf("%c  | ", board[i+1]);
				else printf("%c | ", board[i+1]);
			}
			if (board[i + 2] != 'O' && board[i + 2] != 'X') {
				printf("%d", board[i + 2]);
			} else {
				if(i > 9) printf("%c ", board[i+2]);
				else printf("%c", board[i+2]);
			}
			cout << "          ";
		}
	}
	printf("\n");
	cout << "---------" << "          " << "------------" << "          "
			<< "------------" << endl;

	for (int i = 4; i < 25; i++) {
		if ((i % 9) == 4) {
			if (board[i] != 'O' && board[i] != 'X') {
				printf("%d | ", board[i]);
			} else {
				if(i > 9) printf("%c  | ", board[i]);
				else printf("%c | ", board[i]);
			}
			if (board[i + 1] != 'O' && board[i + 1] != 'X') {
				printf("%d | ", board[i + 1]);
			} else {
				if(i > 9) printf("%c  | ", board[i+1]);
				else printf("%c | ", board[i+1]);
			}
			if (board[i + 2] != 'O' && board[i + 2] != 'X') {
				printf("%d", board[i + 2]);
			} else {
				if(i > 9) printf("%c ", board[i+2]);
				else printf("%c", board[i+2]);
			}
			cout << "          ";
		}
	}
	printf("\n");
	cout << "---------" << "          " << "------------" << "          "
			<< "------------" << endl;

	for (int i = 7; i < 28; i++) {
		if ((i % 9) == 7) {
			if (board[i] != 'O' && board[i] != 'X') {
				printf("%d | ", board[i]);
			} else {
				if(i > 9) printf("%c  | ", board[i]);
				else printf("%c | ", board[i]);
			}
			if (board[i + 1] != 'O' && board[i + 1] != 'X') {
				printf("%d | ", board[i + 1]);
			} else {
				if(i > 9) printf("%c  | ", board[i+1]);
				else printf("%c | ", board[i+1]);
			}
			if (board[i + 2] != 'O' && board[i + 2] != 'X') {
				printf("%d", board[i + 2]);
			} else {
				if(i > 9) printf("%c ", board[i+2]);
				else printf("%c", board[i+2]);
			}
			cout << "          ";
		}
	}

	printf("\n");
}

/**
 * Q3.1
 */
bool checkIfLegal(int cellNbre, char board[]) {
	bool legal = false;

	if (cellNbre >= 1 && cellNbre <= 27) {
		if (board[cellNbre] == 'O' || board[cellNbre] == 'X') {
			legal = false;
		} else {
			legal = true;
		}
	}
	return legal;
}

/**
 * Q3 helper
 */
bool threeIdentical(char a, char b, char c) {
	return (a == b && b == c && a == c);
}

/**
 * Q3.2
 */
bool checkWinner(char board[]) {
	bool win = false;

	// across board diagonal
	bool w1 = threeIdentical(board[3], board[14], board[25]);
	bool w2 = threeIdentical(board[9], board[14], board[19]);
	bool w3 = threeIdentical(board[1], board[14], board[27]);
	bool w4 = threeIdentical(board[21], board[14], board[7]);

	if(w1 || w2 || w3 || w4){
		return true;
	}

	for (int i = 1; i < 28; i++) {
		// horizontal
		if ((i % 9) == 1 || (i % 9) == 4 || (i % 9) == 7) {
			win = threeIdentical(board[i], board[i + 1], board[i + 2]);
			if (win) {
				cout << "horizontal" << endl;
				return true;
			}
		}
		// vertical
		if (threeIdentical(board[i], board[i + 3], board[i + 6])) {
			cout << "vertical" << endl;
			return true;
		}
		// diagonal right
		if ((i % 9) == 1 ) {
			win = threeIdentical(board[i], board[i + 4], board[i + 8]);
			if (win) {
				cout << "diagonal right" << endl;
				return true;
			}
		}
		// diagonal left
		if ((i % 9) == 3 ) {
			win = threeIdentical(board[i], board[i + 2], board[i + 4]);
			if (win) {
				cout << "diagonal left" << endl;
				return true;
			}
		}

		// across board horizontal
		if (threeIdentical(board[i], board[i + 10], board[i + 20])) {
			cout << "across board horizontal" << endl;
			return true;
		}

		// across board vertical
		if(threeIdentical(board[i], board[i + 12], board[i + 24])){
			cout << "across board vertical" << endl;
			return true;
		}

		if(threeIdentical(board[i], board[i + 9], board[i + 18])){
			cout << "across board same position" << endl;
			return true;
		}
	}
	return win;
}

void computerMove(char board[]){

	char* updated = (char*) malloc(sizeof(char) * 28);
	char* mockPlayer = (char*) malloc(sizeof(char) * 28);

	Cell computer;
	computer.content = 'O';

	bool ableToWin = false;
	bool aboutToLose = false;

	for(int i=1; i<28; i++){
		computer.id = i;
		updated = updateBoard(board, computer);
		if(checkWinner(updated) && checkIfLegal(i,board)){
			board[computer.id] = 'O';
			ableToWin = true;
			break;
		}

		if(!ableToWin){
			Cell player;
			player.id = i;
			player.content = 'X';
			mockPlayer = updateBoard(board, player);
			if(checkWinner(mockPlayer) && checkIfLegal(i,board)){
				updated = updateBoard(board, computer);
				board[player.id] = 'O';
				aboutToLose = true;
				break;
			}
		}

	}

	int presetList[10] = {14, 5, 23, 3, 19, 7, 27, 9, 25, 1};

	if(!ableToWin && !aboutToLose){
		for(int i=0; i<10; i++){
			if(checkIfLegal(presetList[i],board)){
				int num = presetList[i];
				computer.id = num;
				updated = updateBoard(board, computer);
				board[computer.id] = 'O';
				break;
			}
		}
	}

	cout << " " << endl;
	cout << "Computer steps at " <<computer.id << endl;

}

