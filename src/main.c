#include "knopkodav.h"

bool isAlpha(char letter, int *output){
    *output = letter;
    return letter > 96 && letter < 123;
}

int main(){
    WINDOW* mainwin = initscr();
    t_player *player = malloc(sizeof(player));
    player->points = 0;
    int stage = 0;
    clock_t lastUpdate = 0;
    bool guessSuccess = false;
    bool timeChanged = false;
    int currentPanel = 0;
    int nash_y = 0, nash_x = 0;getmaxyx(stdscr,nash_y,nash_x);
   // WINDOW* win = newwin(nash_y/2 , nash_x/2 , nash_y/4 , nash_x/4);
    curs_set(false); 
    player->limit = 3;
    int scoreLimit = 0;
    srand(time(0));
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    
    char inputChar = rand() % 26 + 65;


    while(true){
        switch(currentPanel){
            case 0:      
                box(mainwin, 0 , 0);
                
                mvwprintw(mainwin, 4 , nash_x/8 - 1 , "           __   __        __   __            ");
                mvwprintw(mainwin, 5 , nash_x/8 - 1  , "|__/ |\\ | /  \\ |__) |__/ /  \\ |  \\  /\\  \\  / ");
                mvwprintw(mainwin, 6 , nash_x/8 - 1, "|  \\ | \\| \\__/ |    |  \\ \\__/ |__/ /~~\\  \\/  ");
                mvwprintw(mainwin, nash_y/2 , nash_x/2 - 4 , "New Game");
                mvwprintw(mainwin, nash_y/2 + 3, nash_x/2 - 4 , "Plan B!");
                mvwprintw(mainwin, nash_y/2 + 6, nash_x/2 - 2 , "Quit");
                
                switch(getch()) {
                    case 110:
                        wattron(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 , nash_x/2 - 4 , "New Game");
                        wattroff(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 + 3, nash_x/2 - 4 , "Plan B!");
                        mvwprintw(mainwin, nash_y/2 + 6, nash_x/2 - 4 , "Quit");
                        currentPanel = 4;
                        break;
                    case 112:
                        wattron(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 + 3, nash_x/2 - 4 , "Plan B!");
                        wattroff(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 , nash_x/2 - 4 , "New Game");
                        mvwprintw(mainwin, nash_y/2 + 6, nash_x/2 - 2 , "Quit");
                        currentPanel = 2;
                        break;
                    case 113:
                        wattron(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 + 6, nash_x/2 - 2 , "Quit");
                        wattroff(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 , nash_x/2 - 4 , "New Game");
                        mvwprintw(mainwin, nash_y/2 + 3, nash_x/2 - 4 , "Plan B!");
                        exit(0);
                        break;
                    default:
                        mvwprintw(mainwin, nash_y/2 , nash_x/2 - 4 , "New Game");
                        mvwprintw(mainwin, nash_y/2 + 3, nash_x/2 - 4 , "Plan B!");
                        mvwprintw(mainwin, nash_y/2 + 6, nash_x/2 - 2 , "Quit");
                        break;
                }
                break;
            case 1:
                
                if (player->points < scoreLimit){
                    erase();
                    box(mainwin, 0 , 0);
                    printOutLetter(mainwin, inputChar, nash_x, nash_y, stage == 0 ? 4 : guessSuccess ? 2 : 3);
                    if (stage == 1) timeChanged = true;
                    mvwprintw(mainwin, 3, 5, "Score: %d", player->points);
                    //mvwprintw(mainwin, 4, 5, "%f", player->limit);
                    //mvwprintw(mainwin, 5, 25, "%d", clock() - lastUpdate);
                    switch (stage){
                        case 0:{                
                                if (clock() - lastUpdate > player->limit * 50000){                    
                                    inputChar = rand() % 26 + 65;
                                    lastUpdate = clock();
                                    guessSuccess = false;
                                    player->points--;
                                }
                                else{                    
                                    int input = 0;
                                    if (isAlpha(getch(), &input)){
                                        guessSuccess = inputChar + 32 == input;
                                        player->points = inputChar + 32 == input ? player->points + 5 : player->points - 1;
                                        lastUpdate = clock();
                                        stage = 1;
                                    }
                                }
                            }
                            break;
                        
                        case 1: {               
                                if (clock() - lastUpdate > 100000){                   
                                    inputChar = rand() % 26 + 65;
                                    lastUpdate = clock();
                                    stage = 0;
                                    guessSuccess = false;
                                    timeChanged = false;
                                }
                            }
                            break;
                        default  :
                            printf("No option selected in case 1");
                            break;
                    }
                
                }
                else{
                    currentPanel = 5;
                }
            break;
            case 2:
                snake();
                currentPanel=3;
            break;
            case 3:
                switch(getch()){
                    case 114:
                        currentPanel=2;
                        break;
                    case 98:
                        erase();
                        currentPanel=0;
                        break;
                    case 113:
                        exit(0);
                }
                break;
            case 4:
                erase();
                box(mainwin, 0 , 0);
                
                mvwprintw(mainwin, nash_y/2 - 3, nash_x/2 - 2, "Easy");
                mvwprintw(mainwin, nash_y/2 , nash_x/2 - 2 , "Hard");
                mvwprintw(mainwin, nash_y/2 + 3, nash_x/2 - 3 , "Insane");
                switch(getch()){
                    case 101:
                        wattron(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 - 3, nash_x/2 - 2, "Easy");
                        wattroff(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 , nash_x/2 - 2 , "Hard");
                        mvwprintw(mainwin, nash_y/2 + 3, nash_x/2 - 3 , "Insane");
                        scoreLimit = 35;
                        currentPanel = 1;
                        break;
                    case 104:
                        wattron(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 , nash_x/2 - 2 , "Hard");
                        wattroff(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 - 3, nash_x/2 - 2, "Easy");
                        mvwprintw(mainwin, nash_y/2 + 3, nash_x/2 - 3, "Insane");
                        player->limit = 2;
                        scoreLimit = 155;
                        currentPanel = 1;
                        break;
                    case 105:
                        wattron(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 + 3, nash_x/2 - 3 , "Insane");
                        wattroff(mainwin, COLOR_PAIR(5));
                        mvwprintw(mainwin, nash_y/2 - 3, nash_x/2 - 2 , "Easy");
                        mvwprintw(mainwin, nash_y/2, nash_x/2 - 2 , "Hard");
                        player->limit = 1;
                        scoreLimit = 300;
                        currentPanel = 1;
                        break;
                    
                    case 113:
                        exit(0);
                    
                    default:
                        mvwprintw(mainwin, nash_y/2 - 3, nash_x/2 - 2 , "Easy");
                        mvwprintw(mainwin, nash_y/2 , nash_x/2 - 2 , "Hard");
                        mvwprintw(mainwin, nash_y/2 + 3, nash_x/2 - 3 , "Insane");
                        break;
                }
            break;
            case 5:
                erase();
                box(mainwin, 0 , 0);
                
                if (scoreLimit == 35){
                    mvprintw(nash_y/2 - 3, nash_x/2 - 10,"OPA, VY SLUGA NARODA");
                }
                else if(scoreLimit == 155){
                    mvprintw(nash_y/2 - 3, nash_x/2 - 34,"OPA, VITAYEMO V SOLIDARNOSTI! PETRO OLEKSIYOVICH PEREKAZUYE VITANNYA");
                }
                else if(scoreLimit == 300){
                    mvprintw(nash_y/2 - 3, nash_x/2 - 13,"LASKAVO PROSYMO DO OPZZHE");
                }
                mvprintw(nash_y/2 + 1,nash_x/2 - 21,"PRESS R TO PROYTY DO NASTUPNOGO SKLYKANNYA");
                mvprintw(nash_y/2 + 5,nash_x/2 -13,"PRESS B TO VTEKTY DO YIDALNI");		
	            
                switch(getch()){
                    case 114:
                        currentPanel=1;
                        break;
                    case 98:
                        erase();
                        currentPanel=0;
                        break;
                    case 113:
                        exit(0);
                }
                refresh();
                getch();
            break;			
        }
        timeout(5);
        refresh();
    }

    delwin(mainwin);
    endwin();
    return 0;
}
