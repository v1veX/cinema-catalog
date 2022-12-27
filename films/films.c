#include "stdlib.h"
#include "stdio.h"

typedef struct Film{
    char* name;
    int year;
    char* country;
    char* genre;
    float rate;
    struct Film* prev;
    struct Film* next;
}Film;

// typedef struct film_element{
//     Film film;
//     struct film_element* prev;
//     struct film_element* next;
// }film_el;
Film Create_el(char* name, int year, char* country, char*genre, float rate){
    Film* new = (Film*)malloc(sizeof(Film));
    new -> name = name;
    new -> year = year;
    new -> country = country;
    new -> genre = genre;
    new -> rate = rate;
    return new;
};

 void Create_filmlist(){
     FILE* file = fopen("films.txt", "r");
     Film* first = NULL;
     char* name, *country, *genre;
     int year;
     float rate;

     while(fscanf(films, "%s", &name) != EOF){
         fscanf(films, "%d", &year);
         fscanf(films, "%s", &country);
         fscanf(films, "%s", &genre);
         fscanf(films, "%g", &rate);
         Create_el(name, year, country, genre, rate);
     }
 }
int main(){

}