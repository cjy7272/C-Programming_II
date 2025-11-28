#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MAX_BOOKS 100
#define BOOKS_PER_PAGE 5

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "fun.h"
#include "main.h"
#include "settings.h"


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

void user_menu(char id[]);
void load_books();
void my_library(char id[]);
void purchase_book_screen(int real_index);
void add_to_my_library(Book b);