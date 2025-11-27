#include "user_menu.h"

int book_count = 0;
int money = 0;


void user_menu(char id[])
{

    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD origMode = 0;

    system("cls");
    load_books();

    int page = 0;
    char search[100] = {0};
    int filtered_index[MAX_BOOKS];
    int filtered_count = book_count;

    for (int i = 0; i < book_count; i++) filtered_index[i] = i;

    while (1)
    {
        hide_cursor();

        int x = 2, y = 2;

        gotoxy(x, y);
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
        gotoxy(x, y + 1);
        printf("弛 紫憮匐儀 : 贗葛ж罹 匐儀%-67s 弛", search);
        gotoxy(x, y + 2);
        printf("弛                 (囀萄, 紫憮貲, 濛陛貲, 轎っ餌貲)                                             弛");
        gotoxy(x, y + 3);
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");
        gotoxy(x, y + 4);
        printf("弛 囀萄   薯跡                        濛陛                           轎っ餌      陛問     熱榆  弛");
        gotoxy(x, y + 5);
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");

        for (int i = 0; i < BOOKS_PER_PAGE; i++)
        {
            int idx = page * BOOKS_PER_PAGE + i;
            gotoxy(x, 8 + i);

            if (idx < filtered_count)
            {
                Book b = books[filtered_index[idx]];
                printf("弛 %-6s %-27s %-30s %-10s  %-7d%4d偃  弛",
                    b.code, b.title, b.author, b.publisher, b.price, b.count);
            }
            else
            {
                printf("弛                                                                                              弛");
            }
        }

        gotoxy(x, y + 11);
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");

        gotoxy(x, y + 12);
        printf("弛                                      <   %d / %d   >                                           弛",
            page + 1, (filtered_count + BOOKS_PER_PAGE - 1) / BOOKS_PER_PAGE);

        gotoxy(x, y + 13);
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");

        gotoxy(x, y + 14);
        printf("弛 [頂 憮營]                                                                             [撲薑] 弛");

        gotoxy(x, y + 15);
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");

        gotoxy(x, y + 16);
        printf("弛 [ %s椒檜 煎斜檣 醞殮棲棻 ]                                       [爾嶸 濤擋 : %10d 錳] 弛", id, money);

        gotoxy(x, y + 17);
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");

        fflush(stdout);

        enable_mouse_input();

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SHORT mx, my;
        if (get_mouse_click_pos(&mx, &my))
        {
            // > 幗が (棻擠 む檜雖)
            if (mx >= 52 && mx <= 55 && my >= 13 && my <= 14)
            {
                if ((page + 1) * BOOKS_PER_PAGE < filtered_count) page++;
                gotoxy(53, 14);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf(">");
                Sleep(130);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            // < 幗が (檜瞪 む檜雖)
            else if (mx >= 40 && mx <= 42 && my >= 13 && my <= 14)
            {
                if (page > 0) page--;
                gotoxy(41, 14);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("<");
                Sleep(130);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            // [頂 憮營]
            else if (mx >= 3 && mx <= 13 && my >= 15 && my <= 17)
            {
                gotoxy(4, 16);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("[頂 憮營]");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                Sleep(130);
                my_library(id);
                break;
            }
            // [撲薑]
            else if (mx >= 89 && mx <= 96 && my >= 15 && my <= 17)
            {
                gotoxy(90, 16);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("[撲薑]");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                Sleep(130);
                settings(id);
				break;
            }
            if (mx >= 16 && mx <= 84 && my == 3) // 渠楞瞳檣 '紫憮匐儀 : [ ]' 艙羲
            {
                gotoxy(16, 8);

                printf("%-67s", "");

                if (fgets(search, 99, stdin) != NULL) 
                {
                    search[strcspn(search, "\n")] = 0;
                }

                hide_cursor();

                filtered_count = 0;
                for (int i = 0; i < book_count; i++)
                    if (strstr(books[i].code, search) ||
                        strstr(books[i].title, search) ||
                        strstr(books[i].author, search) ||
                        strstr(books[i].publisher, search))
                    {
                        filtered_index[filtered_count++] = i;
                    }
                if (filtered_count > 0 && page * BOOKS_PER_PAGE >= filtered_count) page = 0;

                continue;
            }
        }
        Sleep(1);
    }
}

void load_books()
{
    char path[MAX_PATH];
    
	sprintf(path, "%s\\SW_BOOKSTORE\\booklist.txt", getenv("APPDATA"));

    FILE* fp = fopen(path, "r");
    if (!fp)
    {
        printf("だ橾擊 翮 熱 橈蝗棲棻: %s\n", path);
        system("pause");
        exit(1);
    }

    book_count = 0;
    char line[256];

    while (fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\n")] = '\0';

        char* code = strtok(line, "|");
        char* title = strtok(NULL, "|");
        char* author = strtok(NULL, "|");
        char* publisher = strtok(NULL, "|");
        char* price = strtok(NULL, "|");

        if (!publisher || !price) continue;

        int exist = -1;
        for (int i = 0; i < book_count; i++)
        {
            if (!strcmp(books[i].title, title) &&
                !strcmp(books[i].author, author) &&
                !strcmp(books[i].publisher, publisher))
            {
                exist = i;
                break;
            }
        }

        if (exist != -1)
        {
            books[exist].count++;
        }
        else
        {
            strcpy(books[book_count].code, code);
            strcpy(books[book_count].title, title);
            strcpy(books[book_count].author, author);
            strcpy(books[book_count].publisher, publisher);
            books[book_count].price = atoi(price);
            books[book_count].count = 1;
            book_count++;
        }

        if (book_count >= MAX_BOOKS) break;
    }

    fclose(fp);
}

void my_library(char id[])
{
    system("cls");

    int x = 2, y = 2;

    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

    while (1)
    {

        gotoxy(x, y);
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
        gotoxy(x, y + 1);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 2);
        printf("弛                                           頂 憮營                                            弛");
        gotoxy(x, y + 3);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 4);
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");
        gotoxy(x, y + 5);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 6);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 7);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 8);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 9);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 10);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 11);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 12);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 13);
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");
        gotoxy(x, y + 14);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 15);
        printf("弛                                                                                     菴煎陛晦 弛");
        gotoxy(x, y + 16);
        printf("弛                                                                                              弛");
        gotoxy(x, y + 17);
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
    }
}