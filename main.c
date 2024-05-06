#include "main.h"

int main() {
    
    win_setup();

    if (menu() != 0) goto end;

    while(getch() != 'd') {}





end:
    endwin();
    return 0;
}


void win_setup() {
    initscr();
    noecho();
    nodelay(stdscr, true);
    cbreak();
    curs_set(false);
    keypad(stdscr, true);

    //start_color();
//
    //init_color(COLOR_BROWN, 244, 164, 96);
    //init_color(COLOR_BRIGHT_GREEN, 170, 255, 0);
//
    //init_pair(LAND_PAIR, COLOR_BLACK, COLOR_BROWN);
    //init_pair(WATER_PAIR, COLOR_WHITE, COLOR_BLUE);
    //init_pair(FROG_PAIR, COLOR_BLACK, COLOR_GREEN);
    //init_pair(FLOWER_PAIR, COLOR_BLACK, COLOR_YELLOW);
    //init_pair(FLOWER_CENTER, COLOR_BLACK, COLOR_RED);
    //init_pair(PLANT_PAIR, COLOR_WHITE, COLOR_GREEN);
    //init_pair(CROCODILE_PAIR, COLOR_BLACK, COLOR_BRIGHT_GREEN);
    //init_pair(CROCODILE_EYE_BLACK, COLOR_WHITE, COLOR_BLACK);
    //init_pair(CROCODILE_EYE_WHITE, COLOR_BLACK, COLOR_WHITE);
    //init_pair(CROCODILE_EYE_RED, COLOR_BLACK, COLOR_RED);

    srand(time(NULL));
}

int menu() {
    char title[11][100] = {
        " _____",                               
        "|  ___| __ ___   __ _  __ _  ___ _ __  __   _____",
        "| |_ | '__/ _ \\ / _` |/ _` |/ _ \\ '__| \\ \\ / / __|  ",
        "|  _|| | | (_) | (_| | (_| |  __/ |     \\ V /\\__ \\ ",
        "|_|  |_|  \\___/ \\__, |\\__,| \\___|_|      \\_/ |___/ ",
        "                |___/ |___/                       ",
        " ____  _             _       ",
        "|  _ \\| | __ _ _ __ | |_ ___ ",
        "| |_) | |/ _` | '_ \\| __/ __|",
        "|  __/| | (_| | | | | |_\\__ \\ ",
        "|_|   |_|\\__,_|_| |_|\\__|___/"
    };

    int y = 2;
    for (int i = 0; i < 11; i++) {
        mvaddstr(y, (COLS/2) - 25, title[i]);
        y++;
    }
    char *menu[2] = {"New Game", "Quit"};

    int input;
    int highlighted = 0;

    bkgd(COLOR_PAIR(0));

    mvprintw(LINES-2, 2, "Use SPACE BAR to select the option.");

    box(stdscr, '*', '*');

    while (true) {
        int i;
        for (i = 0; i < 2; i++) {
            if (i == highlighted) attron(A_REVERSE);
            mvprintw(LINES/2 + i, COLS/2 - 8, "%s", menu[i]);
            attroff(A_REVERSE);
        }
        
        input = getch();
        
        switch (input) {
            case KEY_UP:
                highlighted--;
                if (highlighted == -1) highlighted = 0;
                break;

            case KEY_DOWN:
                highlighted++;
                if (highlighted == 2) highlighted = 1;
                break;
            
            case ' ':
                if (highlighted == 0) return 0;
                return 1;

            default:
                break;
        }
    }
}

void game_over(int score) {
    //CLEAR_SCR

    char end_title[6][100] = {
        " _____                         ____",                 
        "/ ____|                       / __ \\",                
        "| |  __  __ _ _ __ ___   ___  | | | |_   _____ _ __", 
        "| | |_ |/ _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|",
        "| |__| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |",
        " \\_____|\\__,_|_| |_| |_|\\___| \\____/  \\_/ \\___|_|"
    };


    bkgd(COLOR_PAIR(0));

    while(getch() != ' ') {
        int y = 2;
        for (int i = 0; i < 6; i++) {
            mvaddstr(y, (COLS/2) - 25, end_title[i]);
            y++;
        }

        mvprintw(LINES-2, 2, "Use SPACE BAR to exit.");
        box(stdscr, '*', '*');

        mvprintw(LINES/2, COLS/2 - 10, "Your score is: %d", score);
    }
}