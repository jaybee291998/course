#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *clrEscChr = "\033[2J";        /* Clear the screen */
char *cnrLfEscChr = "\033[H";
char block[] = {0xE2, 0x96, 0x88};
char space[] = {0xE2, 0x96, 0x91};

#define WIDTH 5
#define HEIGHT 5

unsigned short UTF_8_LENGTH = 3;

void printBoard(char board[HEIGHT][WIDTH]);
void step(char board[HEIGHT][WIDTH], char newBoard[HEIGHT][WIDTH]);
unsigned short getNumOfNeighbors(char board[HEIGHT][WIDTH], unsigned short i, unsigned short j);

int main() {
	char board[HEIGHT][WIDTH] = {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
	};
	char bufferBoard[HEIGHT][WIDTH];

	int max = 100;
	int i = 0;
	printf("%s", clrEscChr);
	//step(board, bufferBoard);
	//printBoard(bufferBoard);
	while(i < max) {
		if(i % 2 == 0) {
			step(board, bufferBoard);
			printBoard(bufferBoard);
		} else {
			step(bufferBoard, board);
			printBoard(board);
		}
		i++;
		sleep(1);
	}
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
