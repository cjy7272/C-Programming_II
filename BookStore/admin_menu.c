#include "admin_menu.h"
void draw_box()
{
	int x = 2, y = 2;
	gotoxy(x, y); printf("┌"); for (int i = 0; i < 94; i++) printf("─"); printf("┐");
	gotoxy(x, y + 2); printf("├"); for (int i = 0; i < 94; i++) printf("─"); printf("┤");
	for (int i = 5; i < 19; i++)
	{
		gotoxy(x, i); printf("│"); for (int j = 0; j < 94; j++) printf(" "); printf("│");
	}
	gotoxy(x, 19); printf("└"); for (int i = 0; i < 94; i++) printf("─"); printf("┘");
	gotoxy(x + 1, 18); printf(" 로그아웃");
}

void admin_menu(char* id)
{
	/*
	* todo: add_book function
	*/

	int admin_account = get_account(id);

	CLS;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

	draw_box();
	gotoxy(2, 3); printf("│                                         관리자 페이지                                        │");
	gotoxy(2 + 44, 7);  printf("도서 등록");
	gotoxy(2 + 44, 10); printf("도서 관리");
	gotoxy(2 + 44, 13); printf("유저 관리");
	gotoxy(2, 17); printf("├"); for (int i = 0; i < 94; i++) printf("─"); printf("┤");
	gotoxy(16, 18); printf("|    [ %s관리자의 보유 잔액 : %d ]", id, admin_account);
	while (1)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (mouse_click(2, 18, 11, 18))
		{
			show_menu();
			return;
		}
		else if (mouse_click(46, 6, 51, 8))
		{
			//도서등록
			gotoxy(46, 7);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("도서 등록");
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			Sleep(170);
			add_book(id, admin_account);
			return;


		}
		else if (mouse_click(46, 9, 51, 11))
		{
			//도서 관리
			gotoxy(46, 10);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("도서 관리");
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			Sleep(170);
			manage_book(id, admin_account);
			return;
		}
		else if (mouse_click(46, 12, 46, 14))
		{
			//유저관리
			gotoxy(46, 13);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("유저 관리");
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			Sleep(170);
			manage_user(id, admin_account);
			return;
		}
	}
}


void add_book(char* id, int admin_account)
{
	draw_box();
	gotoxy(2, 17); printf("├"); for (int i = 0; i < 94; i++) printf("─"); printf("┤");
	gotoxy(2, 3); printf("│                                           도서 등록                                          │");
	gotoxy(16, 18); printf("|    [ %s관리자의 보유 잔액 : %d ]", id, admin_account);
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);


	while (1)
	{
		if (mouse_click(2, 18, 11, 18))
		{
			admin_menu(id);
			return;
		}
	}
}

void manage_book(char* id, int admin_account)
{
	draw_box();
	gotoxy(2, 17); printf("├"); for (int i = 0; i < 94; i++) printf("─"); printf("┤");
	gotoxy(2, 3); printf("│                                           도서 관리                                          │");
	gotoxy(16, 18); printf("|    [ %s관리자의 보유 잔액 : %d ]", id, admin_account);
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);


	while (1)
	{
		if (mouse_click(2, 18, 11, 18))
		{
			admin_menu(id);
			return;
		}
	}
}

void manage_user(char* id, int admin_account)
{
	draw_box();
	gotoxy(2, 17); printf("├"); for (int i = 0; i < 94; i++) printf("─"); printf("┤");
	gotoxy(16, 18); printf("|    [ %s관리자의 보유 잔액 : %d ]", id, admin_account);
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

	while (1)
	{
		if (mouse_click(2, 18, 11, 18))
		{
			admin_menu(id);
			return;
		}
	}
}

int get_account(char* id)
{
	char base[MAX_PATH];
	char filepath[MAX_PATH];
	char* app = getenv("APPDATA");

	if (!app) return -1;
	sprintf(base, "%s\\SW_BOOKSTORE\\USERS", app);
	sprintf(filepath, "%s\\%s.txt", base, id);

	FILE* fp = fopen(filepath, "r");
	if (!fp) return -1;

	int money = 0;

	// 첫 번째 숫자 읽기
	if (fscanf(fp, "%d", &money) != 1) {
		fclose(fp);
		return -1;        // 읽기 실패
	}

	fclose(fp);
	return money;
}