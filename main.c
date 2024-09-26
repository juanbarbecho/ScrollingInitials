#include <ncurses.h>
#include <unistd.h>
#include <math.h>
#include "scroll.h"

#define LED_WIDTH 8
#define LED_HEIGHT 8

void draw_dot(double x, double y) {
    mvaddch((int)y, (int)x, 'O');
    refresh();
}


int main(void) {
    open_display();
    open_input();

    double x = LED_WIDTH / 2.0; // Initial x position (floating-point)
    double y = LED_HEIGHT / 2.0; // Initial y position (floating-point)
    double vx = 0.0; // Initial x velocity (floating-point)
    double vy = 0.0; // Initial y velocity (floating-point)

    while (1) {
        int userInput = check_input(10); // Assume a delay of 10 milliseconds, adjust as needed

        switch (userInput) {
            case 1:
                vx -= 0.05; // Adjust the increment based on your preference
                break;
            case 2:
                vx += 0.05; // Adjust the increment based on your preference
                break;
            case 3:
                vy -= 0.05; // Adjust the increment based on your preference
                break;
            case 4:
                vy += 0.05; // Adjust the increment based on your preference
                break;
            case ' ': // Spacebar to toggle between J and B
                letter = !letter; // Toggle letter (0 for J, 1 for B)
                break;
            case 5:
                endwin();
                return 0;
            default:
                break;
        }

        clear();

        x += vx;
        y += vy;

        // Wrap around the 8x8 grid using regular modulo (%) with casting to int
        x = fmod((x + LED_WIDTH), LED_WIDTH);
        y = fmod((y + LED_HEIGHT), LED_HEIGHT);

        draw_dot(x, y);
        refresh();

        usleep(50000); // 50ms delay for smoother animation
    }

    endwin();
    return 0;
}
