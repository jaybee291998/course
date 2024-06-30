#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

char *clrEscChr = "\033[2J";        /* Clear the screen */
char *cnrLfEscChr = "\033[H";
char block[] = {0xE2, 0x96, 0x88};
char space[] = {0xE2, 0x96, 0x91};

#define WIDTH 50
#define HEIGHT 50

unsigned short UTF_8_LENGTH = 3;

void printBoard(char board[HEIGHT][WIDTH]);
void step(char board[HEIGHT][WIDTH], char newBoard[HEIGHT][WIDTH]);
unsigned short getNumOfNeighbors(char board[HEIGHT][WIDTH], unsigned short i, unsigned short j);
void generateBoard(char board[HEIGHT][WIDTH]);

int main() {
	srand(time(NULL));
//	char board[HEIGHT][WIDTH] = {
//		{0, 0, 0, 0, 0},
//		{0, 0, 1, 0, 0},
//		{0, 0, 1, 0, 0},
//		{0, 0, 1, 0, 0},
//		{0, 0, 0, 0, 0}
//	};
	char board[HEIGHT][WIDTH];
	char bufferBoard[HEIGHT][WIDTH];
	generateBoard(board);
	int max = 10000;
	int i = 0;
	printf("%s", clrEscChr);
	//printBoard(bufferBoard);
	//step(board, bufferBoard);
	//printBoard(bufferBoard);
	while(i < max) {
		if(i % 2 == 0) {
			step(board, bufferBoard);
			//printBoard(bufferBoard);
		} else {
			step(bufferBoard, board);
			//printBoard(board);
		}
		i++;
		//sleep(0.1);
	}
	printBoard(board);
	return 0;
}

void printBoard(char board[HEIGHT][WIDTH]) {
	//printf("%s", clrEscChr);
	printf("%s", cnrLfEscChr);
	char buffer[HEIGHT * ((WIDTH * UTF_8_LENGTH) + 1)];
	for(unsigned short row = 0; row < HEIGHT; row++) {
		for(unsigned short col = 0; col < WIDTH; col++) {
			unsigned short pos = col * UTF_8_LENGTH;
			for(unsigned short i = 0; i < UTF_8_LENGTH; i++) {
				buffer[(row * (WIDTH * UTF_8_LENGTH + 1)) + pos + i] = board[row][col] == 1 ? block[i] : space[i];
			}		
		}
		buffer[(row * (WIDTH * UTF_8_LENGTH + 1)) + WIDTH * UTF_8_LENGTH] = '\n';
		//printf("%s\n", buffer[row]);
	}
	buffer[((HEIGHT - 1) * (WIDTH * UTF_8_LENGTH + 1)) + WIDTH * UTF_8_LENGTH] = '\0';
	printf("%s\n", buffer);
	fflush(stdout);
}

void step(char board[HEIGHT][WIDTH], char newBoard[HEIGHT][WIDTH]) {
	for(unsigned short row = 0; row < HEIGHT; row++) {
		for(unsigned short col = 0; col < WIDTH; col++) {
			unsigned short numberOfNeighbors = getNumOfNeighbors(board, row, col);
			if(board[row][col] == 1) {
				if(numberOfNeighbors < 2) {
					newBoard[row][col] = 0;
				} else if(numberOfNeighbors == 2 || numberOfNeighbors == 3) {
					newBoard[row][col] = 1;
				} else if(numberOfNeighbors > 3) {
					newBoard[row][col] = 0;
				}
			} else {
				if(numberOfNeighbors == 3) {
					newBoard[row][col] = 1;
				} else {
					newBoard[row][col] = 0;
				}
			}
		}
	}
}

unsigned short getNumOfNeighbors(char board[HEIGHT][WIDTH], unsigned short i, unsigned short j) {
	unsigned short numberOfNeighbors = 0;
	for(short row = i - 1; row <= i + 1; row++) {
		if(row < 0 || row >= HEIGHT) {
			continue;
		}
		for(short col = j - 1; col <= j + 1; col++) {
			if(i == row && j == col) continue;
			if(col < 0 || col >= WIDTH) {
				continue;
			}
			if(board[row][col] == 1) {
				numberOfNeighbors++;
			}
		}
	}
	return numberOfNeighbors;
}

void generateBoard(char board[HEIGHT][WIDTH]) {
	for(unsigned short row = 0; row < HEIGHT; row++) {
		for(unsigned short col = 0; col < WIDTH; col++) {
			char value = rand() % 2;
			board[row][col] = value;
		}
	}
}
//void printBoard(char board[HEIGHT][WIDTH]) {
//	char buffer[HEIGHT][(WIDTH * UTF_8_LENGTH) + 1];
//	for(unsigned short row = 0; row < HEIGHT; row++) {
//		for(unsigned short col = 0; col < WIDTH; col++) {
//			unsigned short pos = col * UTF_8_LENGTH;
//			for(unsigned short i = 0; i < UTF_8_LENGTH; i++) {
//				buffer[row][pos + i] = board[row][col] == 1 ? block[i] : space[i];
//			}		
//		}
//		buffer[row][WIDTH*UTF_8_LENGTH] = '\0';
//		printf("%s\n", buffer[row]);
//	}
//	//buffer[HEIGHT - 1][WIDHT*UTF_8_LENGTH] = '\0';
//	//printf("%s", buffer);
//}
