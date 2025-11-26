#pragma once
#include "fun.h"
#include "main.h"
#include "user_menu.h"
#include <stdio.h>
#include <windows.h>

void admin_menu(char* id);
void draw_box();

void add_book(char* id, int admin_account);
void manage_book(char* id, int admin_account);
void manage_user(char* id, int admin_account);

int get_account(char* id);