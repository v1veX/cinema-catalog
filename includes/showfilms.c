#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

void Print_up() {
    for (int i = 1; i < 66; i++) {
        printf(" ");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    for (int i = 1; i < 81; i++) {
        printf("%c", 220);
    }
    printf("\n");

}
void Print_up_left() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    printf("%c", 218);
    for (int i = 1; i < 65; i++) {
        printf("%c", 196);
    }
}
void Print_up_right() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    for (int i = 1; i < 65; i++) {
        printf("%c", 196);
    }
    printf("%c", 191);
    printf("\n");
}
void Print_down_left() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    printf("%c", 192);
    for (int i = 1; i < 65; i++) {
        printf("%c", 196);
    }
}
void Print_down_right() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

    for (int i = 1; i < 65; i++) {
        printf("%c", 196);
    }
    printf("%c", 217);
    printf("\n");
}
void Print_down() {
    for (int i = 1; i < 66; i++) {
        printf(" ");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    for (int i = 1; i < 81; i++) {
        printf("%c", 223);
    }
    printf("\n");
}
void Print(char* str) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("%c", 221);
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        k += 1;
    }
    for (int i = 1; i < (80 - k) / 2; i++) {
        printf(" ");
    }

    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    if (k % 2 == 0) {
    for (int i = 0; i < (80 - k) / 2 - 1; i++) {
        printf(" ");
    }
    }
    else {
    for (int i = 0; i < (80 - k) / 2; i++) {
        printf(" ");
    }
    }
    printf("%c", 222);
}
void Print_left(char* str) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    printf("%c", 179);
    int k = 0;
        for (int i = 0; str[i] != '\0'; i++) {
    k += 1;
    }
    for (int i = 1; i < (64-k)/2; i++) {
        printf(" ");
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0) {
            printf("%c", str[i]);
        }
        else if (i == k ) {
            printf("%c", str[i]);
        }
        else {
            printf("%c", str[i]);
        }
        }
        if (k % 2 == 0) {
        for (int i = 0; i < (64 - k) / 2 - 1; i++) {
            printf(" ");
        }
    }
    else {
        for (int i = 0; i < (64 - k) / 2; i++) {
            printf(" ");
        }
    }
    printf(" ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}
void Print_right(char* str) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    printf(" ");
    int k = 0;
        for (int i = 0; str[i] != '\0'; i++) {
    k += 1;
    }
    if (k % 2 == 0) {
        for (int i = 0; i < (64 - k) / 2 - 1; i++) {
            printf(" ");
        }
    }
    else {
        for (int i = 0; i < (64 - k) / 2; i++) {
            printf(" ");
        }
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0) {
            printf("%c", str[i]);
        }
        else if (i == k ) {
            printf("%c", str[i]);
        }
        else {
            printf("%c", str[i]);
        }
    }
    for (int i = 1; i < (64 - k) / 2; i++) {
        printf(" ");
    }
    printf("%c", 179);
    printf("\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}

void ShowFilms() {
    Film* p = CreateFilmList();
    char gap[] = " ";
    
    while (1) {
        char* name_l = p->prev->name;
        char* year_l = p->prev->year;
        char* country_l = p->prev->country;
        char* genre_l = p->prev->genre;
        char* rate_l = p->prev->rate;

        char* name_с = p->name;
        char* year_с = p->year;
        char* country_с = p->country;
        char* genre_с = p->genre;
        char* rate_с = p->rate;

        char* name_r = p->next->name;
        char* year_r = p->next->year;
        char* country_r = p->next->country;
        char* genre_r = p->next->genre;
        char* rate_r = p->next->rate;
        
        system("cls");        
        system("mode con cols=320 lines=20");
        Print_up();
        Print_up_left();
        Print(gap);
        Print_up_right();
        Print_left(name_l);
        Print(name_с);
        Print_right(name_r);
        Print_left(country_l);
        Print(country_с);
        Print_right(country_r);
        Print_left(genre_l);
        Print(genre_с);
        Print_right(genre_r);
        Print_left(year_l);
        Print(year_с);
        Print_right(year_r);
        Print_left(rate_l);
        Print(rate_с);
        Print_right(rate_r);
        Print_down_left();
        Print(gap);
        Print_down_right();
        Print_down();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("\nA - Switch to left\nD - Switch to right\nESC - Exit");
        char a = _getch();
        if (a == 'a') p = p->prev;
        else if (a == 'd') p = p->next;
        else if (a == 27) exit(0);
        else continue;
    }
}