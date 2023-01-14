#pragma once

struct user;
struct user* login();
int is_login_free(char* login);
int password_check(char* pass, int pass_length);
int card_number_check(char* card, int card_length);
void print_reg_error(char* text);
void reg();
struct user* welcome();