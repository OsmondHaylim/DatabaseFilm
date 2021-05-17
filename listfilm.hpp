void startFilm(int &inputnya){
    std::cout << "===============Movilist===============" << std::endl;
    std::cout << "Masukkan input : " << std::endl;
    std::cout << "1. List film berdasarkan popularitas" << std::endl;
    std::cout << "2. List Film berdasarkan Media Tonton" << std::endl;
    std::cout << "3. List Producer/Director Film" << std::endl;
    std::cout << "4. Input Film baru" << std::endl;
    std::cout << "5. Edit Watchlist" << std::endl;
    std::cout << "6. View Watchlist" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cin >> inputnya; 
}
void insertFilm(pfilm& list, pfilm& head, tree& root){
    std::cout << "===============Movilist===============" << std::endl;
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
    std::cout << "Silahkan input producer/director film : \n";
    std::getline(std::cin, a);
    list->dp = a;
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
    y = A->dp;
    A->dp = B->dp;
    B->dp = y;
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
void showFilm(pfilm head, int i){
    std::cout << "===============Movilist===============" << std::endl;
    if(head == nullptr){
            std::cout << "Film tidak ditemukan!\n";
            return;
        }
    pfilm temp = head;
    for(int j = 1; j < i; j++){
        temp = temp->next;
        if(temp == nullptr){
            std::cout << "Film tidak ditemukan!\n";
            return;
        }
    }
    std::cout << temp->judul << "\n";
    std::cout << "   Rating : " << temp->rating << "%\n";
    std::cout << "   Media Tonton : " << temp->media << "\n";
    std::cout << "   Director/Producer : " << temp->dp << "\n";
    std::cout << "   Sinopsis : \n";
    std::cout << temp->synopsis << "\n";

}
void showListedFilm(pfilm head){
    std::cout << "===============Movilist===============" << std::endl;
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
    std::cout << "Pilih nomor film : ";
    std::cin >> i;
    showFilm(head, i);
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
void sortDirector(pfilm head){
    pfilm temp = head;
        while (temp) {
        pfilm min = temp;
        pfilm r = temp->next;
        while (r) {
            if (min->dp < r->dp)
                min = r;
            r = r->next;
        }
        swapFilm(temp, min);
        temp = temp->next;
    }
}