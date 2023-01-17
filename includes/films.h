#pragma once

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


Film* CreateFilm(char* name, int* year, char* country, char* genre, float* rate);
void AddExistingFilm(FilmList* list, Film* film);
void PrintFilm(Film* film);
Film* CreateFilmFromFile(FILE* file);
void AddFilmsFromFile(FILE* file, FilmList* list);
Film* CreateFilmList();



