#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void open_display(void);
void close_display(void);
void display_letter(int letter, int xOffset, int yOffset);
void clear_display(void);
void open_input(void);
int check_input(int delay);
