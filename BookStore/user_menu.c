#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "fun.h"
#include "main.h"
#include "user_menu.h"

#define MAX_BOOKS 100
#define BOOKS_PER_PAGE 5

typedef struct
{
    char code[10];
    char title[100];
    char author[100];
    char publisher[100];
    int price;
    int count;
} Book;

Book books[MAX_BOOKS];
int book_count = 0;

void load_books();
void my_library(char id[]);
int settings(char id[]);

void user_menu(char id[])
{
    system("cls");
    load_books();

    int page = 0;
    char search[100] = "";
    int filtered_index[MAX_BOOKS];
    int filtered_count = book_count;

    for (int i = 0; i < book_count; i++) filtered_index[i] = i;

    while (1)
    {
        system("cls");
        int x = 2, y = 2;

       
        gotoxy(x, y);
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");

        gotoxy(x, y + 1);
        printf("弛 紫憮匐儀 : %-40s                           (Enter煎 匐儀) 弛", search);

        gotoxy(x, y + 2);
        printf("弛                 (囀萄, 紫憮貲, 濛陛貲, 轎っ餌貲)                                             弛");

        gotoxy(x, y + 3);
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");

        gotoxy(x, y + 4);
        printf("弛 囀萄   薯跡                        濛陛                           轎っ餌      陛問     熱榆  弛");

        gotoxy(x, y + 5);
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");

        for (int i = 0; i < 5; i++)
        {
            int idx = page * 5 + i;
            gotoxy(2, 8 + i);

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
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");

        gotoxy(6, 18);
        printf("≦ %s椒檜 煎斜檣 醞殮棲棻 ≦", id);

        gotoxy(16, 3);
        int ch = _getch();

        if (ch == 0 || ch == 224)
        {
            ch = _getch();
            if (ch == 75 && page > 0) page--;
            if (ch == 77 && page * 5 + 5 < filtered_count) page++;
        }
        else if (ch == 8 && strlen(search))
        {
            search[strlen(search) - 1] = 0;
        }
        else if (ch == 27 || ch == 'q' || ch == 'Q') break;
        else if (ch == 'a' || ch == 'A') { my_library(id); continue; }
        else if (ch == 's' || ch == 'S')
        {
            settings(id);

            return;
        }
        else if (ch == 13)
        {
        
        }
        else if (strlen(search) < 90)
        {
            strncat(search, (char[]) { ch, 0 }, 1);
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


        if (filtered_count > 0 && page * 5 >= filtered_count) page = 0;
    }
}

void load_books()
{
    FILE* fp = fopen("booklist.txt", "r");
    if (!fp)
    {
        printf("booklist.txt だ橾擊 翮 熱 橈蝗棲棻.\n");
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
    printf("[%s椒曖 憮營]\n", id);
    printf("憮營 晦棟\n");
    system("pause");
}

void dummy_charge()
{
    system("cls");
    printf("濤擋醱瞪 晦棟\n");
    system("pause");
}

void delete_account(char id[])
{
    int x = 2, y = 2;
    int key;

    while (1)
    {
        system("cls");
        gotoxy(x, y);     printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
        gotoxy(x, y + 1); printf("弛                      薑蜓 驍黴ж衛啊蝗棲梱?                         弛");
        gotoxy(x, y + 2); printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");
        gotoxy(x, y + 3); printf("弛              [  Yes (Y) ]                    [  No (N) ]            弛");
        gotoxy(x, y + 4); printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");

        key = _getch();

        if (key == 'y' || key == 'Y')
        {
            system("cls");
            printf("�蛾� 驍黴陛 諫猿腎歷蝗棲棻.\n");
            system("pause");
            return;
        }
        else if (key == 'n' || key == 'N' || key == 27)
        {
            settings(id);
        }
    }
}

extern void show_menu();

int settings(char id[])
{
    int cursor = 0;
    int key;
    int x = 2, y = 1;

    char* menu[4] = { "濤擋醱瞪", "煎斜嬴醒", "�蛾躠酷�", "菴煎" };
    int menu_count = 4;

    while (1)
    {
        system("cls");

        gotoxy(x, y);
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
        gotoxy(x, y + 1);
        printf("弛                             撲薑                             弛");
        gotoxy(x, y + 2);
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");
        gotoxy(x, y + 3);
        printf("弛                                                              弛");

        for (int i = 0; i < menu_count; i++)
        {
            gotoxy(x, y + 4 + i);

            if (cursor == i)
                printf("弛                       Ⅱ  %-12s  ９                     弛", menu[i]);
            else
                printf("弛                          %-12s                        弛", menu[i]);
        }
        gotoxy(x, y + 8);
        printf("弛                                                              弛");
        gotoxy(x, y + 9);
        printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");
        gotoxy(x, y + 10);
        printf("弛           ∟⊿ 檜翕        Enter 摹鷗       ESC 菴煎           弛");
        gotoxy(x, y + 11);
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");

        key = _getch();

        if (key == 224)
        {
            key = _getch();
            if (key == 72 && cursor > 0) cursor--;
            else if (key == 80 && cursor < menu_count - 1) cursor++;
        }
        else if (key == 13)
        {
            if (cursor == 0) dummy_charge();
            else if (cursor == 1) { show_menu(); return 0; }
            else if (cursor == 2) { delete_account(id); show_menu(); return 0; }
            else if (cursor == 3) return 0;
        }
        else if (key == 27) return 0;
    }
}
