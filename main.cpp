#include <iostream>
#include <string>

#include "listfilm.hpp"
#include "watchlist.hpp"

int main(){
    pfilm head, list;
    int inputnya;
    head = nullptr;
    queue Q;
    createQ(Q);
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
        }else if(inputnya == 5){
            std::cout << "1. Tambah film dalam watchlist\n";
            std::cout << "2. Selesai tonton\n";
            std::cout << "Masukkan input : ";
            std::cin >> inputnya;
            if(inputnya == 1){
                tambahQ(head, Q);
            }else if(inputnya == 2){
                kurangQ(head, Q);
                std::cout << "Watchlist berhasil diupdate!\n";
            }else{
                continue;
            }
            continue;
        }else if(inputnya == 6){
            transQ(Q);
        }else if(inputnya == 7){
            break;
        }
    }
}