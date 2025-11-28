#include "settings.h"

int settings(char id[])
{

    system("cls");
    int cursor = 0;
    int key;
    int x = 2, y = 2;

    char* menu[3] = { "ÀÜ¾×ÃæÀü", "·Î±×¾Æ¿ô", "È¸¿øÅ»Åð" };
    int menu_count = 3;

    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

    while (1)
    {

        gotoxy(x, y);
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
        gotoxy(x, y + 1);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 2);
        printf("¦¢                                             ¼³Á¤                                             ¦¢");
        gotoxy(x, y + 3);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 4);
        printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
        gotoxy(x, y + 5);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 6);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 7);
        printf("¦¢                                           %-12s                                       ¦¢", menu[0]);
        gotoxy(x, y + 8);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 9);
        printf("¦¢                                           %-12s                                       ¦¢", menu[1]);
        gotoxy(x, y + 10);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 11);
        printf("¦¢                                           %-12s                                       ¦¢", menu[2]);
        gotoxy(x, y + 12);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 13);
        printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
        gotoxy(x, y + 14);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 15);
        printf("¦¢                                                                                     µÚ·Î°¡±â ¦¢"); 
        gotoxy(x, y + 16);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 17);
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");

        enable_mouse_input();

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SHORT mx, my;
        if (get_mouse_click_pos(&mx, &my))
        {
            if (mx >= 45 && mx <= 54 && my >= 8 && my <= 9)
            {
                gotoxy(46, 9);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("ÀÜ¾×ÃæÀü");
                Sleep(130);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                charge_money(id);
            }
            else if (mx >= 46 && mx <= 53 && my >= 10 && my <= 11)
            {
                gotoxy(46, 11);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("·Î±×¾Æ¿ô");
                Sleep(130);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                show_menu();
                return 0;
            }
            else if (mx >= 45 && mx <= 53 && my == 13)
            {
                gotoxy(46, 13);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("È¸¿øÅ»Åð");
                Sleep(130);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                delete_account(id);
                show_menu();
                return 0;
            }
            else if (mx >= 87 && mx <= 95 && my >= 16 && my <= 17)
            {
                gotoxy(88, 17);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("µÚ·Î°¡±â");
                Sleep(130);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                user_menu(id);
            }
        }
        Sleep(1);
    }
}

void delete_account(char id[])
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

    int x = 2, y = 2;
    int key;

    system("cls");
    gotoxy(x, y);
    printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
    gotoxy(x, y + 1);
    printf("¦¢                                                                                              ¦¢");
    gotoxy(x, y + 2);
    printf("¦¢                                           È¸¿øÅ»Åð                                           ¦¢");
    gotoxy(x, y + 3);
    printf("¦¢                                                                                              ¦¢");
    gotoxy(x, y + 4);
    printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
    gotoxy(x, y + 5);
    printf("¦¢                                                                                              ¦¢");
    gotoxy(x, y + 6);
    printf("¦¢                                                                                              ¦¢");
    gotoxy(x, y + 7);
    printf("¦¢                                                                                              ¦¢");
    gotoxy(x, y + 8);
    printf("¦¢                                    Á¤¸» Å»ÅðÇÏ½Ã°Ú½À´Ï±î?                                    ¦¢");
    gotoxy(x, y + 9);
    printf("¦¢                                                                                              ¦¢");
    gotoxy(x, y + 10);
    printf("¦¢                                                                                              ¦¢");
    gotoxy(x, y + 11);
    printf("¦¢                                                                                              ¦¢");
    gotoxy(x, y + 12);
    printf("¦¢                                                                                              ¦¢");
    gotoxy(x, y + 13); printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
    gotoxy(x, y + 14);
    printf("¦¢                                                                                              ¦¢");
    gotoxy(x, y + 15); printf("¦¢                         [  Yes  ]                           [  No  ]                         ¦¢");
    gotoxy(x, y + 16);
    printf("¦¢                                                                                              ¦¢");
    gotoxy(x, y + 17); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");

    while (1)
    {
        enable_mouse_input();

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SHORT mx, my;
        if (get_mouse_click_pos(&mx, &my))
        {
            if (mx >= 27 && mx <= 37 && my >= 16 && my <= 17)
            {
                gotoxy(28, 17);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("[  Yes  ]");
                Sleep(130);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                system("cls");
                gotoxy(x, y);
                printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
                gotoxy(x, y + 1);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 2);
                printf("¦¢                                           È¸¿øÅ»Åð                                           ¦¢");
                gotoxy(x, y + 3);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 4);
                printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
                gotoxy(x, y + 5);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 6);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 7);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 8);
                printf("¦¢                                   È¸¿ø Å»Åð°¡ ¿Ï·áµÇ¾ú½À´Ï´Ù.                                ¦¢");
                gotoxy(x, y + 9);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 10);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 11);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 12);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 13); printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
                gotoxy(x, y + 14);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 15);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 16);
                printf("¦¢                                                                                              ¦¢");
                gotoxy(x, y + 17); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");

                gotoxy(33, y + 15);
                system("pause");
                return;
            }
            else if (mx >= 63 && mx <= 71 && my >= 16 && my <= 17)
            {
                gotoxy(64, 17);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("[  No  ]");
                Sleep(130);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                settings(id);
            }
        }
        Sleep(1);
        
    }
}

void charge_money(char id[])
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

    extern int money;

    int x = 2, y = 2;
    int amount = 0;

    system("cls");

    while (1)
    {

        gotoxy(x, y);     printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
        gotoxy(x, y + 1);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 2); printf("¦¢                                        ÀÜ¾× ÃæÀüÇÏ±â                                         ¦¢");
        gotoxy(x, y + 3);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 4); printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
        gotoxy(x, y + 5);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 6); printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 7); printf("¦¢   ÃæÀü ±Ý¾×À» ÀÔ·ÂÇÏ¼¼¿ä (1¸¸¿ø ´ÜÀ§ / ÃÖ¼Ò 1¸¸¿ø) (ÃÖ´ë 9,000,000¸¸¿ø)                      ¦¢");
        gotoxy(x, y + 8);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 9); printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 10); printf("¦¢   ÀÔ·Â: ");
        printf("%7d¿ø                                                                            ¦¢", amount);
        gotoxy(x, y + 11);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 12); printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 13); printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
        gotoxy(x, y + 14);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 15); printf("¦¢   Enter: È®ÀÎ                                                                       µÚ·Î°¡±â ¦¢");
        gotoxy(x, y + 16);
        printf("¦¢                                                                                              ¦¢");
        gotoxy(x, y + 17); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        if (_kbhit())
        {
            int key = _getch();

            if (key == 13)
            {
                if (amount >= 10000 && amount % 10000 == 0)
                {
                    money += amount;
                    system("cls");
                    gotoxy(x, y);
                    printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
                    gotoxy(x, y + 1);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 2);
                    printf("¦¢                                        ÀÜ¾× ÃæÀüÇÏ±â                                         ¦¢");
                    gotoxy(x, y + 3);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 4);
                    printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
                    gotoxy(x, y + 5);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 6);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 7);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 8);
                    printf("¦¢                               ÃæÀü ¿Ï·á! ÇöÀç ÀÜ¾×: %7d¿ø                                ¦¢", money);
                    gotoxy(x, y + 9);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 10);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 11);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 12);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 13);
                    printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
                    gotoxy(x, y + 14);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 15);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 16);
                    printf("¦¢                                                                                              ¦¢");
                    gotoxy(x, y + 17);
                    printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");

                    gotoxy(33, y + 15);
                    system("pause");
					user_menu(id);
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    gotoxy(21, 14);
                    printf("Àß¸øµÈ ±Ý¾×ÀÔ´Ï´Ù. 1¸¸¿ø ´ÜÀ§, ÃÖ¼Ò 1¸¸¿ø ÀÌ»ó ÀÔ·ÂÇÏ¼¼¿ä.");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    PAUSE;
                    continue;
                }
            }
            else if (key >= '0' && key <= '9')
            {
                int len = 0;
                int temp = amount;

                if (temp == 0) len = 0;
                else
                {
                    while (temp > 0)
                    {
                        temp /= 10;
                        len++;
                    }
                }

                if (len < 7)
                {
                    amount = amount * 10 + (key - '0');
                }
            }
            else if (key == 8)
            {
                amount /= 10;
            }
        }
        enable_mouse_input();

        SHORT mx, my;
        if (get_mouse_click_pos(&mx, &my))
        {
            if (mx >= 87 && mx <= 95 && my >= 16 && my <= 17)
            {
                gotoxy(88, 17);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("µÚ·Î°¡±â");
                Sleep(130);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                return;
            }
        }
    }
}