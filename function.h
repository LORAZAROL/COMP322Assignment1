#include <iostream>

using namespace std;

#ifndef FUNCTION_H_
#define FUNCTION_H_


/**
 * A struct that maps each cell
 */
typedef struct box{
	int id;			//number indicating each cell
	char content;	//O X
} Cell;

void greetAndInstruct();

void displayBoard (char board[]);

char* updateBoard(char board[], Cell step);

bool checkIfLegal (int cellNbre, char board[]);

bool checkWinner(char board[]);

void computerMove(char board[]);

#endif /* FUNCTION_H_ */
