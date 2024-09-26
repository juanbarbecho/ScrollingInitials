#include <ncurses.h>
#include "scroll.h"

#define WHITE 1
#define GREEN 2
#define LED_WIDTH 8
#define LED_HEIGHT 8

void open_display(){
    initscr();
    start_color();
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
}

void close_display(){
    if (isendwin()) {
        refresh();
    } else {
        endwin();
    }
}

void display_letter(int letter, int xOffset, int yOffset) {
    // Removes old dot
    clear();
    // Makes sure it loops around
    xOffset = xOffset % LED_WIDTH;
    yOffset = yOffset % LED_HEIGHT;

    if (letter % 2 == 0) {
        // logic for J
        //TOP of J
        mvaddch(yOffset, xOffset, '#');
        mvaddch(yOffset, xOffset+1, '#');
        mvaddch(yOffset, xOffset+2, '#');
        mvaddch(yOffset, xOffset+3, '#');
        mvaddch(yOffset, xOffset+4, '#');
        mvaddch(yOffset, xOffset+5, '#');
        
        // MIDDLE of J
        mvaddch(yOffset +1, xOffset+2, '#');
        mvaddch(yOffset +2, xOffset+2, '#');
        mvaddch(yOffset +3, xOffset+2, '#');
        mvaddch(yOffset +4, xOffset+2, '#');
        mvaddch(yOffset +5, xOffset+2, '#');
        
        // BOTTOM of J
        mvaddch(yOffset + 5, xOffset+2, '#');
        mvaddch(yOffset + 5, xOffset+1, '#');
        mvaddch(yOffset + 5, xOffset, '#');
        mvaddch(yOffset + 5, xOffset-1, '#');

        
} else {
    // logic for B
    mvaddch(yOffset, xOffset-1, '#');
    mvaddch(yOffset, xOffset-2, '#');
    mvaddch(yOffset, xOffset-3, '#');
    mvaddch(yOffset, xOffset-3, '#');
    mvaddch(yOffset+1, xOffset-3, '#');
    mvaddch(yOffset+2, xOffset-3, '#');
    mvaddch(yOffset+3, xOffset-3, '#');
    mvaddch(yOffset+4, xOffset-3, '#');
    mvaddch(yOffset+5, xOffset-3, '#');
    mvaddch(yOffset+6, xOffset-3, '#');
    mvaddch(yOffset+6, xOffset-2, '#');
    mvaddch(yOffset+6, xOffset-1, '#');
    mvaddch(yOffset+5, xOffset, '#');
    mvaddch(yOffset+4, xOffset, '#');
    mvaddch(yOffset+3, xOffset-2, '#');
    mvaddch(yOffset+3, xOffset-1, '#');
    mvaddch(yOffset+2, xOffset, '#');
    mvaddch(yOffset+1, xOffset, '#');
    
}
}

void clear_display(void){
    clear();
}
