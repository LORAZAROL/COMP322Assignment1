#include "function.h"

int main(){

	greetAndInstruct();

	// read in response
	char response;
	scanf("%c", &response);

	bool esc = false;

	char* board = (char*)malloc(sizeof(char)*28);
	board[0] = ' ';
	for(int i=1; i<28; i++){
		board[i] = i;
	}

	char player = 'X';
//	char computer = 'O';

	bool playerTurn = true;

	int overallStep = 27;

	while(!esc){
		if(response == 'N' || response == 'n'){
			esc = true;
		}
		if(response == 'y' || response == 'Y'){

			if(playerTurn){
				int stepID;
				cin >> stepID;
				if(checkIfLegal (stepID, board)){
					Cell step;
					step.id = stepID;
					step.content = player;
					board = updateBoard(board, step);
					displayBoard(board);
					overallStep--;
				}else{
					cout << "Please enter a number between 1 and 27" << endl;
				}
			}

			else{
				computerMove(board);
				overallStep--;
				displayBoard(board);
			}

			playerTurn = (!playerTurn);

			if(overallStep == 0){
				cout << "Tied!" << endl;
				esc = true;
			}

			if(checkWinner(board)){
				if(playerTurn){
					cout << "Computer wins!" << endl;
				}else{
					cout << "You win!!!!" << endl;
				}
				esc = true;
			}

		}



	}
}
