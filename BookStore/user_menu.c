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
    char title[100];
    char author[100];
    char publisher[100];
    int price;
} Book;
Book books[MAX_BOOKS];
int book_count = 0;

void load_books();
void my_library(char id[]);
void settings(char id[]);
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

        gotoxy(x, y); printf("┌──────────────────────────────────────────────────────────────────────────────┐");
        gotoxy(x, y + 1); printf("│ 도서검색 : %-50s (Enter로 검색) │", search);
        gotoxy(x, y + 2); printf("│              (도서명, 작가명, 출판사명)                                      │");
        gotoxy(x, y + 3); printf("├──────────────────────────────────────────────────────────────────────────────┤");
        gotoxy(x, y + 4); printf("│ 제목                     작가                          출판사          가격  │");
        gotoxy(x, y + 5); printf("├──────────────────────────────────────────────────────────────────────────────┤");

        for (int i = 0; i < 5; i++)
        {
            int idx = page * 5 + i;
            gotoxy(2, 8 + i);
            if (idx < filtered_count)
            {
                Book b = books[filtered_index[idx]];
                printf("│ %-25s %-30s %-16s %6d│", b.title, b.author, b.publisher, b.price);
            }
            else printf("│                                                                              │");
        }

        gotoxy(x, y + 11); printf("├──────────────────────────────────────────────────────────────────────────────┤");
        gotoxy(x, y + 12); printf("│                             <   %d / %d   >                                    │",
            page + 1, (filtered_count + BOOKS_PER_PAGE - 1) / BOOKS_PER_PAGE);
        gotoxy(x, y + 13); printf("├──────────────────────────────────────────────────────────────────────────────┤");
        gotoxy(x, y + 14); printf("│ [내 서재]                                                         [설정]     │");
        gotoxy(x, y + 15); printf("└──────────────────────────────────────────────────────────────────────────────┘");

        gotoxy(6, 18); printf("※ %s님이 로그인 중입니다 ※", id);

        gotoxy(15, 3);                            // 커서 위치 고정
        int ch = _getch();

        if (ch == 0 || ch == 224)                 // 방향키
        {
            ch = _getch();
            if (ch == 75 && page > 0) page--;     // 왼쪽
            if (ch == 77 && page * 5 + 5 < filtered_count) page++; // 오른쪽
        }
        else if (ch == 8 && strlen(search))       // 백스페이스
        {
            search[strlen(search) - 1] = 0;
        }
        else if (ch == 27 || ch == 'q' || ch == 'Q') break;
        else if (ch == 'a' || ch == 'A') { my_library(id); continue; }
        else if (ch == 's' || ch == 'S') { settings(id);   continue; }
        else if (ch == 13);                      // 엔터 무시
        else if (strlen(search) < 90)
        {
            strncat(search, (char[]) { ch, 0 }, 1);
        }

        // 실시간 검색
        filtered_count = 0;
        for (int i = 0; i < book_count; i++)
            if (strstr(books[i].title, search) || strstr(books[i].author, search) || strstr(books[i].publisher, search))
                filtered_index[filtered_count++] = i;
        if (filtered_count > 0 && page * 5 >= filtered_count) page = 0;
    }
}

void load_books()
{
    FILE* fp = fopen("booklist.txt", "r");
    if (!fp)
    {
        printf("booklist.txt 파일을 열 수 없습니다.\n");
        system("pause");
        exit(1);
    }
    book_count = 0;
    char line[256];
    while (fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\n")] = '\0';
        char* token = strtok(line, "|");
        if (!token) continue;
        strcpy(books[book_count].title, token);
        token = strtok(NULL, "|");
        if (!token) continue;
        strcpy(books[book_count].author, token);
        token = strtok(NULL, "|");
        if (!token) continue;
        strcpy(books[book_count].publisher, token);
        token = strtok(NULL, "|");
        if (!token) continue;
        books[book_count].price = atoi(token);
        book_count++;
        if (book_count >= MAX_BOOKS) break;
    }
    fclose(fp);
}

void my_library(char id[])
{
    system("cls");
    printf("[%s님의 서재]\n", id);
    printf("서재 기능\n");
    system("pause");
}

void settings(char id[])
{
    system("cls");
    printf("[%s님의 설정 메뉴]\n", id);
    printf("설정 기능\n");
    system("pause");
}