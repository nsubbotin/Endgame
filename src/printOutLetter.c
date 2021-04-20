#include "knopkodav.h"

void printOutLetter(WINDOW *win, char a, int x, int y, int color){
    attron(COLOR_PAIR(color));
    switch (a){
        case 'A':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   _____   ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (  _  )  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | (_) |  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  |  _  |  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | | | |  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (_) (_)  ");
            break;
        }    
        case 'B':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   ___     ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (  _`\\   ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | (_) )  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  |  _ <'  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | (_) )  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (____/'  ");
            break;
        }    
        case 'C':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   ___     ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (  _`\\   ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | ( (_)  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | |  _   ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | (_( )  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (____/'  ");
            break;
        }
        case 'D':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   ___     ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (  _`\\   ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | | ) |  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | | | )  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | |_) |  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (____/'  ");
            break;
        }
        case 'E':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   ___     ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (  _`\\   ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | (_(_)  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  |  _)_   ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | (_( )  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (____/'  ");
            break;
        }
        case 'F':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   ___     ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (  _`\\   ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | (_(_)  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  |  _)    ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | |      ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (_)      ");
            break;
        }
        case 'G':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   ___     ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (  _`\\   ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | ( (_)  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | |___   ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | (_, )  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (____/'  ");
            break;
        }
        case 'H':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   _   _   ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  ( ) ( )  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | |_| |  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  |  _  |  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | | | |  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (_) (_)  ");
            break;
        }
        case 'I':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "     _     ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "    (_)    ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "     _     ");
            mvwprintw(win, y / 2, x / 2 - 6, "    | |    ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "    | |    ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "    (_)    ");
            break;
        }
        case 'J':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   _____   ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (___  )  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "      | |  ");
            mvwprintw(win, y / 2, x / 2 - 6, "   _  | |  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  ( )_| |  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  `\\___/'  ");
            break;
        }
        case 'K':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   _   _   ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  ( ) ( )  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | |/'/'  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | , <    ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | |\\`\\   ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (_) (_)  ");
            break;
        }
        case 'L':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   _       ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  ( )      ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | |      ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | |  _   ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | |_( )  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (____/'  ");
            break;
        }
        case 'M':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "  /'\\_/`\\  ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  |     |  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | (_) |  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | | | |  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  (_) (_)  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "           ");
            break;
        }
        case 'N':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   _   _   ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  ( ) ( )  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | `\\| |  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | , ` |  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | |`\\ |  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (_) (_)  ");
            break;
        }
        case 'O':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   _____   ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (  _  )  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | ( ) |  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | | | |  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | (_) |  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (_____)  ");
            break;
        }
        case 'P':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   ___     ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (  _`\\   ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | | ) |  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | ,__/'  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | |      ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (_)      ");
            break;
        }
        case 'Q':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   _____   ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (  _  )  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | ( ) |  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  || | ||  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  |  ('\\|  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (___\\_)  ");
            break;
        }
        case 'R':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   ___     ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (  _`\\   ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | (_) )  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | ,  /   ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | |\\ \\   ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (_) (_)  ");
            break;
        }
        case 'S':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "  ____     ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, " (  __`\\   ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, " | |__(_)  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  `\\__ \\   ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  ( )_) |  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, " `\\____)   ");
            break;
        }
        case 'T':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   _____   ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  (_   _)  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "    | |    ");
            mvwprintw(win, y / 2, x / 2 - 6, "    | |    ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "    | |    ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "    (_)    ");
            break;
        }
        case 'U':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   _   _   ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  ( ) ( )  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | | | |  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | | | |  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | (_) |  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  (_____)  ");
            break;
        }
        case 'V':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "   _   _   ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "  ( ) ( )  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "  | | | |  ");
            mvwprintw(win, y / 2, x / 2 - 6, "  | | | |  ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  | \\_/ |  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "  `\\___/'  ");
            break;
        }
        case 'W':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, " _       _ ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, "( )  _  ( )");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "| | ( ) | |");
            mvwprintw(win, y / 2, x / 2 - 6, "| | | | | |");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "| (_/ \\_) |");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "`\\___x___/'");
            break;
        }
        case 'X':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "  _    _   ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, " ( )  ( )  ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, " `\\`\\/'/'  ");
            mvwprintw(win, y / 2, x / 2 - 6, "   >  <    ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  /'/\\`\\   ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, " (_)  (_)  ");
            break;
        }
        case 'Y':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "  _     _  ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, " ( )   ( ) ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, " `\\`\\_/'/' ");
            mvwprintw(win, y / 2, x / 2 - 6, "   `\\ /'   ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "    | |    ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, "    (_)    ");
            break;
        }
        case 'Z':{
            mvwprintw(win, y / 2 - 3, x / 2 - 6, "  _______  ");
            mvwprintw(win, y / 2 - 2, x / 2 - 6, " (_____  ) ");
            mvwprintw(win, y / 2 - 1, x / 2 - 6, "      /'/' ");
            mvwprintw(win, y / 2, x / 2 - 6, "    /'/'   ");
            mvwprintw(win, y / 2 + 1, x / 2 - 6, "  /'/'___  ");
            mvwprintw(win, y / 2 + 2, x / 2 - 6, " (_______) ");
            break;
        }
    refresh();
    }
    attroff(COLOR_PAIR(color));
    /*if (!tc){
        player->limit = color == 2 ? player->limit * 0.95 : color == 3 ? player->limit * 1.05 : player->limit;
    }*/
}
