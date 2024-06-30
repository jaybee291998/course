#include <stdio.h>
#include <unistd.h>

int main() {
    printf("\033[2J");        /* Clear the screen */
    printf("\033[H");         /* Position cursor at top-left corner */

    for (int i = 1; i <= 100; i++) {
        printf("The current count is: %d", i);
        fflush(stdout);
        sleep(1);
        printf(i < 100 ? "\033[H" : "\n");  /* Move cursor or new line */
    }

    return 0;
}
