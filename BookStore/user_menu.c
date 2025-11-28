#include "user_menu.h"

int book_count = 0;
int money = 0;

void purchase_book_screen(int real_index);


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
    char search_display[68];
    snprintf(search_display, 68, "%-67s", search);

    for (int i = 0; i < book_count; i++) filtered_index[i] = i;

    while (1)
    {
        hide_cursor();

        int x = 2, y = 2;

        char search_display[68];
        snprintf(search_display, 68, "%-67s", search);

        gotoxy(x, y);
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
        gotoxy(x, y + 1);
        if (strlen(search) == 0)
        {
            printf("弛 紫憮匐儀 : %-72s  (Enter) 弛", "贗葛ж罹 匐儀");
        }
        else
        {
            printf("弛 紫憮匐儀 : %-72s  (Enter) 弛", search);
        }
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
            if (mx >= 16 && mx <= 84 && my == 3)
            {
                gotoxy(16, 3);

                printf("%-67s", "");

                gotoxy(16, 3);

                if (fgets(search, 99, stdin) != NULL) 
                {
                    gotoxy(16, 3);
                    search[strcspn(search, "\n")] = 0;
                }

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
            int clicked_book = -1;
            
            if (mx >= 3 && mx <= 95 && my >= 7 && my <= 8)
                clicked_book = 0;

            else if (mx >= 3 && mx <= 95 && my >= 8 && my <= 9)
                clicked_book = 1;

            else if (mx >= 3 && mx <= 95 && my >= 9 && my <= 10)
                clicked_book = 2;

            else if (mx >= 3 && mx <= 95 && my >= 10 && my <= 11)
                clicked_book = 3;

            else if (mx >= 3 && mx <= 95 && my >= 11 && my <= 12)
                clicked_book = 4;

            if (clicked_book != -1)
            {
                int idx = page * BOOKS_PER_PAGE + clicked_book;
                if (idx < filtered_count)
                {
                    int real_index = filtered_index[idx];
                    purchase_book_screen(real_index);
                    continue;
                }
            }

        }
        Sleep(1);
    }
}
void purchase_book_screen(int real_index)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

    Book* b = &books[real_index];
    int x = 2, y = 2;

    system("cls");
    gotoxy(x, y);
    printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    gotoxy(x, y + 1);
    printf("弛                                                                                              弛");
    gotoxy(x, y + 2);
    printf("弛                                     摹鷗и 疇 : %-40s     弛", b->title);
    gotoxy(x, y + 3);
    printf("弛                                                                                              弛");
    gotoxy(x, y + 4);
    printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");
    gotoxy(x, y + 5);
    printf("弛                                                                                              弛");
    gotoxy(x, y + 6);
    printf("弛                                      陛問 :%6d錳                                          弛", b->price);
    gotoxy(x, y + 7);
    printf("弛                                                                                              弛");
    gotoxy(x, y + 8);
    printf("弛                                      ⑷營 濤擋 :%10d錳                                 弛", money);
    gotoxy(x, y + 9);
    printf("弛                                                                                              弛");
    gotoxy(x, y + 10);
    printf("弛                                      掘衙ж衛啊蝗棲梱?                                       弛");
    gotoxy(x, y + 11);
    printf("弛                                                                                              弛");
    gotoxy(x, y + 12);
    printf("弛                                                                                              弛");
    gotoxy(x, y + 13); printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");
    gotoxy(x, y + 14);
    printf("弛                                                                                              弛");
    gotoxy(x, y + 15); printf("弛                         [  Yes  ]                           [  No  ]                         弛");
    gotoxy(x, y + 16);
    printf("弛                                                                                              弛");
    gotoxy(x, y + 17); printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");

    while (1)
    {
        enable_mouse_input();

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SHORT mx, my;
        if (get_mouse_click_pos(&mx, &my))
        {
            // > 幗が (棻擠 む檜雖)
            if (mx >= 63 && mx <= 71 && my >= 16 && my <= 17)
            {
                gotoxy(64, 17);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("[  No  ]");
                Sleep(130);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                
                return;
            }
            else if (mx >= 27 && mx <= 37 && my >= 16 && my <= 17)
            {
                gotoxy(28, 17);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("[  Yes  ]");
                Sleep(130);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                if (money < b->price)
                {
                    gotoxy(42, 14);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf("濤擋檜 睡褶м棲棻.");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					//1.5蟾 �� 檜瞪�飛橉虞�
                    Sleep(1500);

                    return;
                }
                // 掘衙 籀葬
                money -= b->price;

                //add_to_my_library(*b);  // 頂 憮營 盪濰
                gotoxy(35, 14);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("掘衙 諫猿! 頂 憮營縑 蹺陛腎歷蝗棲棻.");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                //1.5蟾 �� 檜瞪�飛橉虞�
                Sleep(1500);

				return;
            }
        }
    }
    Sleep(1);
}
void add_to_my_library(Book b)
{
    
    FILE* fp = fopen("id.txt", "a");
    if (!fp) return;

    fprintf(fp, "%s|%s|%s|%s|%d\n",
        b.code, b.title, b.author, b.publisher, b.price);

    fclose(fp);
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