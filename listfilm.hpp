struct film{
    std::string judul;
    std::string synopsis;
    std::string media;
    int rating;
    int visited = 0;
    film* next;
};

typedef film* pfilm;

void startFilm(int &inputnya){
    std::cout << "===============Movilist===============" << std::endl;
    std::cout << "Masukkan input : " << std::endl;
    std::cout << "1. List film berdasarkan popularitas" << std::endl;
    std::cout << "2. List Film berdasarkan Media Tonton" << std::endl;
    std::cout << "3. List Producer/Director Film" << std::endl;
    std::cout << "4. Input Film baru" << std::endl;
    std::cout << "5. Input flim baru dalam Watchlist" << std::endl;
    std::cout << "6. View Watchlist" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cin >> inputnya; 
}

void insertFilm(pfilm& list, pfilm& head){
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
    y = A->media;
    A->media = B->media;
    B->media = y;
    x = A->visited;
    A->visited = B->visited;
    B->visited = x;
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
            if (min->rating < r->rating)
                min = r;
            r = r->next;
        }
        swapFilm(temp, min);
        temp = temp->next;
    }
}

void showListedFilm(pfilm head){
    pfilm temp = head;
    std::cout << "List Film :\n";
    int i = 1;
    while(temp){
        std::cout << i << ". " << temp->judul << "\n";
        std::cout << "   Rating : " << temp->rating << "%\n";
        std::cout << "   Media Tonton : " << temp->media << "\n";
        i++;
        temp = temp->next;
    }
}

void sortMedia(pfilm head){
    pfilm temp = head;
        while (temp) {
        pfilm min = temp;
        pfilm r = temp->next;
        while (r) {
            if (min->media < r->media)
                min = r;
            r = r->next;
        }
        swapFilm(temp, min);
        temp = temp->next;
    }
}
