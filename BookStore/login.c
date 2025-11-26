#include "login.h"

int check_login(char id[], char pw[]);

void login_menu()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    int x = 35, y;
    char id[100], pw[100];
    int step;
    int idx_id, idx_pw;
    char c;

    while (1)
    {
        CLS;
        y = 5;
        step = 0;
        idx_id = idx_pw = 0;
        memset(id, 0, sizeof(id));
        memset(pw, 0, sizeof(pw));

        // 화면 그리기
        gotoxy(x, y++); printf("┌──────────────────────────────────────────┐");
        for (int i = 0; i < 18; i++) { gotoxy(x, y++); printf("│                                          │"); }
        gotoxy(x, y++); printf("└──────────────────────────────────────────┘");
        gotoxy(x + 2, 23); printf("돌아가기");
        gotoxy(x + 16, 6); printf("☆  로그인 ☆");
        gotoxy(x + 5, 11); printf("아이디 : ");
        gotoxy(x + 5, 14); printf("비밀번호 : ");
        gotoxy(x + 14, 11);

        // 입력 처리
        while (step < 2)
        {
            enable_mouse_input();

            // 1. 키보드 입력 처리
            if (_kbhit())
            {
                c = _getch();
                if (c == '\r') { step++; if (step == 1) gotoxy(x + 16, 14); }
                else if (c == '\b') {
                    if (step == 0 && idx_id > 0) { idx_id--; printf("\b \b"); }
                    else if (step == 1 && idx_pw > 0) { idx_pw--; printf("\b \b"); }
                }
                else if (c != '\b') {
                    if (step == 0 && idx_id < 99) { id[idx_id++] = c; putchar(c); }
                    else if (step == 1 && idx_pw < 99) { pw[idx_pw++] = c; putchar('*'); }
                }
            }
            if (mouse_click(37, 23, 45, 23)) {
                show_menu();
                return;
            }

            Sleep(1);
        }

        // 로그인 인증 및 결과 처리 로직
        id[idx_id] = '\0';
        pw[idx_pw] = '\0';
        int result = check_login(id, pw);

        if (result == 0)
        {
            int x = 35, y = 5;
            gotoxy(x, y++); printf("┌──────────────────────────────────────────┐");
            for (int i = 0; i < 18; i++) { gotoxy(x, y++); printf("│                                          │"); }
            gotoxy(x, y++); printf("└──────────────────────────────────────────┘");
            gotoxy(x + 16, 6); printf("☆  로그인 ☆");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            gotoxy(x + 14, 12); printf("%s님 환영합니다!!", id);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            user_menu(id);
            return;
        }
        else if (result = 1)
        {
            admin_menu(id);
            return;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(x + 10, 18);
            if (result == 1) printf("존재하지 않는 아이디입니다.");
            else if (result == 2) printf("비밀번호가 틀렸습니다.");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            PAUSE;
        }
    }
}


int check_login(const char* id, const char* pw)
{
    char path[MAX_PATH];
    sprintf(path, "%s\\SW_BOOKSTORE\\userdata.txt", getenv("APPDATA"));

    FILE* fp = fopen(path, "r");
    if (!fp) return 3; // 파일 없음 → ID 없음 취급

    char file_id[100], file_pw[100];
    int is_admin;
    int id_found = 0;

    char line[256];
    while (fgets(line, sizeof(line), fp)) {

        if (sscanf(line, "%99s %99s %d", file_id, file_pw, &is_admin) == 3) {     // 1=관리자 0=일반유저 -1=예외

            file_id[99] = '\0';
            file_pw[99] = '\0';

            // ID 일치
            if (strcmp(id, file_id) == 0) {
                id_found = 1;

                // PW 일치 여부 체크
                if (strcmp(pw, file_pw) == 0) {

                    fclose(fp);

                    // 관리자인가?
                    if (is_admin == 1)
                        return 1;   // 관리자
                    else
                        return 0;   // 일반 유저
                }
                else {
                    fclose(fp);
                    return -1;   // PW 불일치
                }
            }
        }
    }

    fclose(fp);
    return -1; // ID 없음
}