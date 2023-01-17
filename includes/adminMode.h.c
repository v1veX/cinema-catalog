#include <stdio.h>
#include <locale.h>
#include "films.h"
#include "adminMode.h"

void adminMode() {
    system("cls");
    FILE* file = fopen("films.txt", "a");
    char name[BUFF_SIZE], year[BUFF_SIZE], country[BUFF_SIZE], genre[BUFF_SIZE], rate[BUFF_SIZE];
    scanf("%s", &name);
    scanf("%s", &year);
    scanf("%s", &country);
    scanf("%s", &genre);
    scanf("%s", &rate);
    fprintf(file, "\n%s", name);
    fprintf(file, "\n%s", year);
    fprintf(file, "\n%s", country);
    fprintf(file, "\n%s", genre);
    fprintf(file, "\n%s", rate);
    fclose(file);
}