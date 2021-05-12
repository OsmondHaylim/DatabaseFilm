#include "listfilm.hpp"

struct film{
    std::string judul;
    std::string synopsis;
    int rating;
    film* next;
};

typedef film* pfilm;

void insertFilm(pfilm& list, pfilm& head, std::string a){
    int temp = 0;
    list = new film;
    std::string a = "";
    std::getline(std::cin, a);
    std::cout << "Silahkan input judul film : \n";
    std::getline(std::cin, a);
    list->judul = a;
    std::cout << "Silahkan input synopsis film : \n";
    std::getline(std::cin, a);
    list->synopsis = a;
    std::cout << "Silahkan input media tonton film : \n";
    std::getline(std::cin, a);
    list->media = a;
    std::cout << "Silahkan input rating film : \n";
    std::cin >> temp;
    list->rating = temp;
    list->next = nullptr;
    if(head == nullptr){
        head = list;
    }else{
        list->next = head;
        head = list;
    }
}

void swapFilm(pfilm& A, pfilm& B){
    int x = A->rating;
    A->rating = B->rating;
    B->rating = x;
    std::string y = A->judul;
    A->judul = B->judul;
    B->judul = y;
    y = A->synopsis;
    A->synopsis = B->synopsis;
    B->synopsis = y;
}

int nodeCount(pfilm head){
  pfilm temp = head;
  int i = 1;
  while (temp->next != nullptr){
    temp = temp->next;
    i++;
  }
  return i;
}

void showsortedFilm(pfilm& head){
    pfilm temp = head;
    while (temp) {
        pfilm min = temp;
        pfilm r = temp->next;
        while (r) {
            if (min->rating > r->rating)
                min = r;
            r = r->next;
        }
        swapFilm(temp, min);
        temp = temp->next;
    }
}

void showListedFilm(pfilm& head){
    pfilm temp = head;
    for(int i = 0; i > 2; i++){
        std::cout << i+1 << ". " << temp->judul;
        temp = temp->next;
    }
}


// Buat Linked List Film