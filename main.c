#include <stdio.h>
#include "users.h"
#include "films.h"
#include "showfilms.h"

int main() {
    struct user* usr = welcome();

    ShowFilms(usr);
    return 0;
}