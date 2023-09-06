// TUI-C is a Terminal UI made in C, just like the name!
// intended for easy setup, just run the file in a C editor
// if on Linux (make sure ncurses is installed), use: gcc -o TUI-C[TEST].C -lncurses

#include <ncurses.h>

initscr(); // Initialize ncurses
cbreak(); // disables line buffering
noecho(); // prevents echoing keypresses to UI
keypad(stdscr, TRUE); // allows keyboard function

// Time to add options, you can customize these!

char* options[] = {"Option 1, Option 2, Option 3, Option 4, Option 5"};

void displayOptions(int currentOption, char* options[], int numOptions) {
    clear();  // Clear the screen
    for (int i = 0; i < numOptions; i++) {
        if (i == currentOption) {
            attron(A_REVERSE);  // Highlight the selected option
        }
        mvprintw(i + 1, 1, "%s", options[i]);
        attroff(A_REVERSE);  // Turn off highlighting
    }
    refresh();  // Refresh the screen
}

int currentOption = 0;
int key;

while (1) {
    displayOptions(currentOption, options, sizeof(options) / sizeof(options[0]));
    key = getch();

    switch (key) {
        case KEY_UP:
            if (currentOption > 0) {
                currentOption--;
            }
            break;
        case KEY_DOWN:
            if (currentOption < sizeof(options) / sizeof(options[0]) - 1) {
                currentOption++;
            }
            break;
        case 10:  // Enter key
            // Handle the selected option (e.g., perform an action)
            break;
        default:
            break;
    }

    if (key == 10) {
        break;  // Exit the loop when Enter key is pressed
    }
}

endwin(); // close the window and clean up
