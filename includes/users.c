#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "users.h"

struct user* login() {
    char login[21], pass[21];
    char loginf[21], passf[21], cardf[17];
    int favf, is_adminf, is_successful = 0;
    struct user* user_info = (struct user*)malloc(sizeof(struct user));
    while (1) {
        FILE* users = fopen("users.txt", "r");
        system("cls");
        printf("Login: ");
        scanf("%s", &login);
        printf("Password: ");
        scanf("%s", &pass);
        while (1) {
            if (fscanf(users, "%s %s %s %d %d", &loginf, &passf, &cardf, &favf, &is_adminf) != EOF) {
                if (strcmp(login, loginf) == 0 && strcmp(pass, passf) == 0) {
                    system("cls");
                    is_successful = 1;
                    fclose(users);
                    break;
                }
            }
            else {
                system("cls");
                printf("Wrong login or password! Press any key to try again.");
                char cont = _getch();
                fclose(users);
                break;
            }
        }
        if (is_successful == 1) {
            user_info->login = login;
            user_info->pass = pass;
            user_info->card = cardf;
            user_info->favorites = favf;
            user_info->is_admin = is_adminf;
            return user_info;
            break;
        }
    }
}

int is_login_free(char* login) {
    char loginf[21], passf[21], cardf[17];
    int favf, is_adminf;
    FILE* users = fopen("users.txt", "r");
    while (1) {
        if (fscanf(users, "%s", &loginf) != EOF) {
            if (strcmp(login, loginf) == 0) {
                fclose(users);
                return 0;
            }
        }
        else return 1;
    }
}

int password_check(char* pass, int pass_length) {
    int L_count = 0, l_count = 0, num_count = 0;
    for (int i = 0; i < pass_length; i++) {
        for (int j = 65; j < 91; j++) {
            if (pass[i] == j) {
                L_count += 1;
                break;
            }
        }
        for (int h = 97; h < 123; h++) {
            if (pass[i] == h) {
                l_count += 1;
                break;
            }
        }
        for (int k = 48; k < 58; k++) {
            if (pass[i] == k) {
                num_count += 1;
                break;
            }
        }
    }
    if (L_count > 0 && l_count > 0 && num_count > 0) return 1;
    else return 0;
}

int card_number_check(char* card, int card_length) {
    int num_count = 0;
    for (int i = 0; i < card_length; i++) {
        for (int j = 48; j < 58; j++) {
            if (card[i] == j) {
                num_count += 1;
                break;
            }
        }
    }
    if (num_count == card_length) return 1;
    else return 0;
}

void print_reg_error(char* text) {
    system("cls");
    printf("%s", text);
    _getch();
}

void reg() {
    char login[21], pass[21], card[17];
    int fav = 0, is_admin = 0, is_successful = 0, login_length, pass_length, card_length;
    while (1) {
        system("cls");
        printf("Login (3 - 20 symbols):\n");
        scanf("%s", &login);
        login_length = strlen(login);
        printf("Password (6 - 20 symbols, at least one number, one capital letter, one small letter):\n");
        scanf("%s", &pass);
        pass_length = strlen(pass);
        printf("Card number (16 numbers):\n");
        scanf("%s", &card);
        card_length = strlen(card);
        if (login_length < 3 || login_length > 20) print_reg_error("Login must contain from 3 to 20 symbols! Press any key to try again.");
        else if (is_login_free(login) == 0) print_reg_error("This login is already exists! Press any key to try again.");
        else if (password_check(pass, pass_length) == 0) print_reg_error("Password must contain at least one number, one capital letter, one small letter! Press any key to try again.");
        else if (pass_length < 6 || pass_length > 20) print_reg_error("Password must contain from 6 to 20 symbols! Press any key to try again.");
        else if (card_number_check(card, card_length) == 0) print_reg_error("Card number must contain only numbers! Press any key to try again.");
        else if (card_length != 16) print_reg_error("Card number must contain 16 numbers! Press any key to try again.");
        else break;
    }
    FILE* users = fopen("users.txt", "a");
    fprintf(users, "\n%s %s %s %d %d", login, pass, card, fav, is_admin);
    fclose(users);
    printf("\nYou signed up successfully. Press any key to sign in.");
    _getch();
}

struct user* welcome() {
    printf("Welcome to online cinema RODINA!\n\n1 - Sign in\n2 - Sign up\nESC - Exit");
    while (1) {
        char welcome = _getch();
        if (welcome == '1') {
            struct user* user = login();
            return user;
            break;
        }
        else if (welcome == '2') {
            reg();
            struct user* user = login();
            return user;
            break;
        }
        else if (welcome == 27) {
            exit(0);
        }
        else continue;
    }
}