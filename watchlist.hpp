void createQ(queue& Q){
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q){
    if(Q.head==nullptr&&Q.tail==nullptr)
        return true;
    else
        return false;
}

void enQ(queue& Q, pfilm Elem){
    pfilm prev = nullptr;
    pfilm temp = Q.head;
    pfilm Elem1 = new film;
    Elem1->rating = Elem->rating;
    Elem1->judul = Elem->judul;
    Elem1->synopsis = Elem->synopsis;
    Elem1->dp = Elem->dp;
    Elem1->media = Elem->media;
    Elem1->visited = Elem->visited;
    Elem1->next = nullptr;

    if(isEmpty(Q)){
        Q.head = Elem1;
        Q.tail = Elem1;
    }else{
        while(Elem1->rating <= temp->rating){
          if (temp->next == nullptr)
            break;
          prev = temp;
          temp = temp->next;
        }
        if(temp == Q.head && Elem1->rating > temp->rating){
          Elem1->next = temp;
          Q.head = Elem1;
        }else if(temp == Q.tail && Elem1->rating < temp->rating){
          temp->next = Elem1;
          Q.tail = Elem1;
        }else{
          prev->next = Elem1;
          Elem1->next = temp;
        }
    }
}
void deQ(queue& Q, pfilm Elem){
    if(isEmpty(Q)){
        Elem = nullptr;
    }else if(Q.head->next == nullptr){
        Elem = Q.head;
        Q.head = nullptr;
        Q.tail = nullptr;
    }else{
        Elem = Q.head;
        Q.head = Q.head->next;
        Elem->next = nullptr;
    }
}

void tambahQ(pfilm& head, queue& Q){
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
    std::cout << "Pilih nomor film yang ingin ditambahkan ke Watchlist : ";
    std::cin >> i;
    temp = head;
    for(int j = 1; j < i; j++){
        temp = temp->next;
    }
    enQ(Q,temp);
}
void kurangQ(pfilm& head, queue& Q){
    std::cout << "===============Movilist===============" << std::endl;
    pfilm temp = Q.head;
    deQ(Q,temp);
}
void transQ(queue& Q){
    std::cout << "===============Movilist===============" << std::endl;
    pfilm temp = Q.head;
    std::cout << "Watchlist :\n";
    int i = 1;
    while(temp){
        std::cout << i << ". " << temp->judul << "\n";
        i++;
        temp = temp->next;
    }
}