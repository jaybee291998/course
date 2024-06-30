#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *clearScreenEscapeChar = "\033[2J";        /* Clear the screen */
    	char *cornerLeftCursorEscapeChar = "\033[H";
	char block[] = {0xE2, 0x96, 0x88, '\0'};
	char space[] = {0xE2, 0x96, 0x91, '\0'};
	printf("%s%s%s\n", block, space, block);
	//printf("%s", clearScreenEscapeChar);
	printf("%s\n", space);
	printf("%ld\n", strlen(clearScreenEscapeChar));
	return 0;
}
