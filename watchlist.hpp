struct queue{
    pfilm head;
    pfilm tail;
};

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
    pfilm Elem1 = Elem;
    pfilm pRev = nullptr;
    pfilm temp = Q.head;
    if(isEmpty(Q)){
        Q.head = Elem1;
        Q.tail = Elem1;
    }else{
        pRev->next = Elem1;
        Elem1->next = temp;
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
    for(int j = 0; j < i; j++){
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