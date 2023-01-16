#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

#define BUFF_SIZE 1024

typedef struct Film {
    char* name;
    int* year;
    char* country;
    char* genre;
    float* rate;
    struct Film* prev;
    struct Film* next;
}Film;

typedef struct FilmList {
    Film* head;
}FilmList;

Film* CreateFilm(char* name, int* year, char* country, char* genre, float* rate) {
    Film* new = (Film*)malloc(sizeof(Film));
    new->name = name;
    new->year = year;
    new->country = country;
    new->genre = genre;
    new->rate = rate;
    new->prev = NULL;
    new->next = NULL;
    return new;
};

void AddExistingFilm(FilmList* list, Film* film) {
    if (list->head == NULL) {
        list->head = film;
        film->next = NULL;
        film->prev = NULL;
    }
    else if (list->head->next == NULL) {
        list->head->next = film;
        film->next = list->head;
        list->head->prev = film;
        film->prev = list->head;
    }
    else {
        Film* tail = list->head->prev;
        tail->next = film;
        film->next = list->head;
        film->prev = tail;
        list->head->prev = film;
    }
}

void PrintFilm(Film* film) {
    printf("%s", film->name);
    printf("\t%s", film->year);
    printf("\t%s", film->country);
    printf("\t%s", film->genre);
    printf("\t%s", film->rate);
}

Film* CreateFilmFromFile(FILE *file) {
    
    char* filmData[5];
    for (int i = 0; i < 5; i++) {
        filmData[i] = malloc(sizeof(char) * BUFF_SIZE);
    }

    for (int i = 0; i < 5; i++) {
        fgets(filmData[i], BUFF_SIZE, file);
        filmData[i][strcspn(filmData[i], "\n")] = 0;
    }

    return CreateFilm(filmData[0], filmData[1], filmData[2], filmData[3], filmData[4]);
}

void AddFilmsFromFile(FILE* file, FilmList* list) {

    while (!feof(file)) {  
        Film* film = CreateFilmFromFile(file);
        AddExistingFilm(list, film);
    }

    fclose(file);
}

Film* CreateFilmList() {
    setlocale(LC_ALL, "Russian");
    FilmList* temp = (FilmList*)malloc(sizeof(FilmList));
    temp->head = NULL;
    FILE* file = fopen("films.txt", "r");

    AddFilmsFromFile(file, temp);

    fclose(file);
    return temp->head;
}