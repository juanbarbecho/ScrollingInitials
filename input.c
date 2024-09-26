#include <ncurses.h>
#include <unistd.h> // for usleep
#include <stdio.h>

void open_input(void) {
    if (!isendwin()) {
        initscr();
        keypad(stdscr, TRUE); // For  arrow keys
        nodelay(stdscr, TRUE); // Lets program keep running
        cbreak(); // Makes return not necessary
        noecho(); // Disable echoing of input characters
    }
}

int check_input(int delay) {
    int key = getch(); 

    if (key == ERR) {
        // No key pressed
        usleep(delay * 1000);
        return 0;
    } else {
        // Key pressed
        switch (key) {
            case KEY_LEFT:
                return 1; // Left arrow key
            case KEY_RIGHT:
                return 2; // Right arrow key
            case KEY_UP:
                return 3; // Up arrow key
            case KEY_DOWN:
                return 4; // Down arrow key
            case '\n':
                return 5; // Return key
            case ' ':
                return 6; // Spacebar
            default:
                return 0; // Other keys
        }
    }
}
