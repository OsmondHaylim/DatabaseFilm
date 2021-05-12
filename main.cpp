#include <iostream>
#include <string>

#include "watchlist.hpp"
#include "listfilm.hpp"

int main(){
    pfilm head, list;
    int inputnya;
    head = nullptr;
    while(true){
        startFilm(inputnya);
        if(inputnya == 1){
            showsortedFilm(head);
            showListedFilm(head);        
        }else if(inputnya == 2){
            sortMedia(head);
            showListedFilm(head);  
        }else if(inputnya == 4){
            insertFilm(list, head);
        }else if(inputnya == 7){
            break;
        }
    }
}