#include <stdio.h>
#include <stdlib.h>

#define ASCIIVal 48
//Checks for valid position on board
int posCheck(int input, char* board) {
	if (input < 1 || input > 9) {
		printf("Out of range!\n");
		return 0;
	}
	else if (input + ASCIIVal != board[input]) {
		printf("Position taken!\n");
		return 0;
	}
	else return 1;
}
//Gets position on board from player
void getPosition(char* player, char* board) {
	int input;
	int inputCheck;
	do {
		printf("Player %c, enter position: ", *player);
		inputCheck = scanf("%d", &input);
		if (inputCheck != 1) {
			printf("Invalid entry!\n");
			scanf("%*[^\n]");	//read past invalid input
		}
		else { 
			inputCheck = posCheck(input, board); 
		}
	} while (inputCheck != 1);
	board[input] = *player;
}
//Displays board
void displayBoard(char* boardPos) {
	printf("\t %c | %c | %c \n", boardPos[1], boardPos[2], boardPos[3]);
	printf("\t---|---|---\n");
	printf("\t %c | %c | %c \n", boardPos[4], boardPos[5], boardPos[6]);
	printf("\t---|---|---\n");
	printf("\t %c | %c | %c \n", boardPos[7], boardPos[8], boardPos[9]);
}
//Checks if anyone has won
void winCheck(char* boardPos) {
	if (boardPos[1] == boardPos[2] && boardPos[2] == boardPos[3]) {
		if (boardPos[1] == 'X') {
			printf("Player X wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
		else if (boardPos[1] == 'O') {
			printf("Player O wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
	}
	else if (boardPos[4] == boardPos[5] && boardPos[5] == boardPos[6]) {
		if (boardPos[4] == 'X') {
			printf("Player X wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
		else if (boardPos[4] == 'O') {
			printf("Player O wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
	}
	else if (boardPos[7] == boardPos[8] && boardPos[8] == boardPos[9]) {
		if (boardPos[7] == 'X') {
			printf("Player X wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
		else if (boardPos[7] == 'O') {
			printf("Player O wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
	}
	else if (boardPos[1] == boardPos[4] && boardPos[4] == boardPos[7]) {
		if (boardPos[1] == 'X') {
			printf("Player X wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
		else if (boardPos[1] == 'O') {
			printf("Player O wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
	}
	else if (boardPos[2] == boardPos[5] && boardPos[5] == boardPos[8]) {
		if (boardPos[2] == 'X') {
			printf("Player X wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
		else if (boardPos[2] == 'O') {
			printf("Player O wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
	}
	else if (boardPos[3] == boardPos[6] && boardPos[6] == boardPos[9]) {
		if (boardPos[3] == 'X') {
			printf("Player X wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
		else if (boardPos[3] == 'O') {
			printf("Player O wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
	}
	else if (boardPos[1] == boardPos[5] && boardPos[5] == boardPos[9]) {
		if (boardPos[1] == 'X') {
			printf("Player X wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
		else if (boardPos[1] == 'O') {
			printf("Player O wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
	}
	else if (boardPos[3] == boardPos[5] && boardPos[5] == boardPos[7]) {
		if (boardPos[3] == 'X') {
			printf("Player X wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
		else if (boardPos[3] == 'O') {
			printf("Player O wins.\n");
			for (int i = 0; i <= 9; i++) {
				boardPos[i] = i + ASCIIVal;
			}
		}
	}
}
//Checks if the game is a draw
void drawCheck(char* board) {
	for (int i = 1; i <= 9; i++) {
		if (i + ASCIIVal == board[i]) {
			return;
		}
	}
	printf("Draw!\n");
	for (int i = 0; i <= 9; i++) {
		board[i] = i + ASCIIVal;
	}
}
int main() {
	char boardPos[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char p1Character = 'X', p2Character = 'O';
	
	while (1)
	{
		//Display board
		displayBoard(boardPos);
		//Get Player 1 position
		getPosition(&p1Character, boardPos);
		//Check for win
		winCheck(boardPos);
		//Check for draw
		drawCheck(boardPos);
		//Display board
		displayBoard(boardPos);
		//Get Player 2 position
		getPosition(&p2Character, boardPos);
		//Check for win
		winCheck(boardPos);
		//Check for draw
		drawCheck(boardPos);
	}
	system("pause");
	return 0;
}