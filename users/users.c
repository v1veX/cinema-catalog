#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct user {
    char* login;
    char* pass;
    char* card;
    int favorites;
    int is_admin;
};

void login() {
    char login[21], pass[21];
    char loginf[21], passf[21], cardf[17];
    int favf, is_adminf, is_logged = 0;
    // FILE * users = fopen("users.txt", "r");
    while (1) {
        FILE * users = fopen("users.txt", "r");
        system("cls");
        printf("Login: ");
        scanf("%s", &login);
        printf("Password: ");
        scanf("%s", &pass);
        while (1) {
            if (fscanf(users, "%s %s %s %d %d", &loginf, &passf, &cardf, &favf, &is_adminf) != EOF) {
                if (strcmp(login, loginf) == 0 && strcmp(pass, passf) == 0) {
                    system("cls");
                    printf("You've logged in");
                    is_logged = 1;
                    fclose(users);
                    break;
                }
            } else {
                system("cls");
                printf("Wrong login or password! Press any key to try again");
                char cont = _getch();
                fclose(users);
                break;
            }
        }
        if (is_logged == 1) {
            break;
        }
    }
}

void reg() {
    system("cls");
}

void welcome() {
    printf("Welcome to online cinema <<CINEMA_NAME>>!\n1 - log in\n2 - register");
    while (1) {
        char welcome = _getch();
        if (welcome == '1') {
            login();
            break;
        }
        else if (welcome == '2') {
            reg();
            break;
        } else continue;
    }
}

int main() {
    // struct user* user = (struct user*)malloc(sizeof(struct user));
    welcome();
    return 0;
}