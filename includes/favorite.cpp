//#include <stdio.h>
//#include <stdlib.h>
//#include "films.h"
//
//typedef struct FavoriteElem {
//	Film* film;
//	struct FavoriteElem* next;
//	struct FavoriteElem* prev;
//} FavoriteElem;
//
//
//typedef struct FavoriteList {
//	int size;
//	FavoriteElem* first;
//	FavoriteElem* last;
//} FavoriteList;
//
//
//FavoriteList* CreateFavList() {
//	FavoriteList* tmp = (FavoriteList*)malloc(sizeof(FavoriteList));
//	tmp->size = 0;
//	tmp->first = NULL;
//	tmp->last = NULL;
//
//	return tmp;
//
//}
//
//
//void InsertFront(FavoriteList* list, Film* film) {
//	FavoriteElem* node = (FavoriteElem*)malloc(sizeof(FavoriteElem));
//	node->film = film;
//	node->prev = NULL;
//	node->next = list->first;
//	if (list->first != NULL) {
//		list->first->prev = node;
//	}
//	list->first = node;
//	if (list->last == NULL) {
//		list->last = node;
//	}
//	list->size++;
//}
//
//
//void InsertBack(FavoriteList* list, Film* film) {
//	FavoriteElem* node = (FavoriteElem*)malloc(sizeof(FavoriteElem));
//	node->film = film;
//	node->prev = list->last;
//	node->next = NULL;
//	if (list->last != NULL) {
//		list->last->next = node;
//	}
//	list->last = node;
//	if (list->first == NULL) {
//		list->first = node;
//	}
//	list->size++;
//}
//
////void* deleteNth(FavoriteList* list, size_t index) {
////	FavoriteElem* elm = NULL;
////	void* tmp = NULL;
////	elm = getNth(list, index);
////	if (elm == NULL) {
////		exit(5);
////	}
////	if (elm->prev) {
////		elm->prev->next = elm->next;
////	}
////	if (elm->next) {
////		elm->next->prev = elm->prev;
////	}
////	tmp = elm->film;
////
////	if (!elm->prev) {
////		list->first = elm->next;
////	}
////	if (!elm->next) {
////		list->last = elm->prev;
////	}
////
////	free(elm);
////
////	list->size--;
////
////	return tmp;
////}
//
//void DeleteFavByIndex(FavoriteList* list, int index) {
//	if (index < 0 || index >= list->size) {
//		return;
//	}
//	FavoriteElem* current = list->first;
//	for (int i = 0; i < index; i++) {
//		current = current->next;
//	}
//	if (current->prev != NULL) {
//		current->prev->next = current->next;
//	}
//	if (current->next != NULL) {
//		current->next->prev = current->prev;
//	}
//	if (index == 0) {
//		list->first = current->next;
//	}
//	if (index == list->size - 1) {
//		list->last = current->prev;
//	}
//
//	free(current);
//	list->size--;
//}
//
//
//void SaveList(FavoriteList* list, const char* filename) {
//	FILE* file = fopen(filename, "w");
//	FavoriteElem* current = list->first;
//	while (current != NULL) {
//		fprintf(file, "%d\n", current->film);
//		current = current->next;
//	}
//	fclose(file);
//}
//
//
//FavoriteList* LoadList(const char* filename) {
//	FavoriteList* list = CreateFavList();
//	FILE* file = fopen(filename, "r");
//	int data;
//	while (fscanf(file, "%d", &data) == 1) {
//		insertBack(list, data);
//	}
//	fclose(file);
//	return list;
//}
//
//void deleteMovie(FavoriteList* list, const char* movieName) {
//	FavoriteElem* current = list->first;
//	while (current != NULL) {
//		if (strcmp(current->film, movieName) == 0) {
//			if (current->prev != NULL) {
//				current->prev->next = current->next;
//			}
//			if (current->next != NULL) {
//				current->next->prev = current->prev;
//			}
//			if (current == list->first) {
//				list->first = current->next;
//			}
//			if (current == list->last) {
//				list->last = current->prev;
//			}
//			free(current);
//			list->size--;
//			return;
//		}
//		current = current->next;
//	}
//}
//
//
//int main() {
//	FavoriteList* list = CreateFavList();
//	Film* film = CreateFilmFromFile(film);
//	InsertBack(list, film);
//
//}