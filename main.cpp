#include <iostream>
#include <string>

#include "watchlist.hpp"
#include "listfilm.hpp"

int main(){
    pfilm head, list;
    std::string a;
    head = nullptr;
    insertFilm(list, head, a);
    insertFilm(list, head, a);
    insertFilm(list, head, a);
    showListedFilm(head);
    showsortedFilm(head);
    showListedFilm(head);
}