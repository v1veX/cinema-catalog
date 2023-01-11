#include <stdlib.h>
#include <stdio.h>

typedef struct Film{
    char* name;
    char* year;
    char* country;
    char* genre;
    char* rate;
    struct Film* prev;
    struct Film* next;
}Film;

// typedef struct film_element{
//     Film film;
//     struct film_element* prev;
//     struct film_element* next;
// }film_el;

Film* Create_el(char* name, char* year, char* country, char*genre, char* rate){
    Film* new = (Film*)malloc(sizeof(Film));
    new -> name = name;
    new -> year = year;
    new -> country = country;
    new -> genre = genre;
    new -> rate = rate;
    new -> next = NULL;
    return new;
};

void Add_film(Film* head, char* name, char* year, char* country, char*genre, char* rate){
    Film* new = (Film*)malloc(sizeof(Film));
    new -> name = name;
    new -> year = year;
    new -> country = country;
    new -> genre = genre;
    new -> rate = rate;
    new -> next = NULL;
    Film *p = head;
    while ( p -> next != NULL){
        p = p -> next;
    }
    p -> next = new;
}

Film* Scan_films(){
    char* Name;
    char* Year;
    char* Country;
    char* Genre;
    char* Rate;
    FILE* file;
    file = fopen("films.txt", "r");
    Film* head = NULL;

    fscanf(file, "%s", &Name);
    fscanf(file, "%s", &Year);
    fscanf(file, "%s", &Country);
    fscanf(file, "%s", &Genre);
    fscanf(file, "%s", &Rate);
    Film* first = Create_el(Name, Year, Country, Genre, Rate);
    head = first;


    while(fscanf(file, "%s", &Name)!= EOF){
        fscanf(file, "%s", &Year);
        fscanf(file, "%s", &Country);
        fscanf(file, "%s", &Genre);
        fscanf(file, "%s", &Rate);
        Add_film(head, Name, Year, Country, Genre, Rate);
    }
    fclose(file);
    return head;
}

void Print(Film *head){
    Film *p = head;
    while(p != NULL){
        printf("%s ", p->name);
        p = p -> next;
    }
}


int main(){
    FILE* file; 
    file = fopen("films.txt", "r");
    char a;
    fscanf(file, "%c", &a);
    printf("%c", a);
}