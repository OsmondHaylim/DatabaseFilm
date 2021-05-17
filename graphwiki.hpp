bool check(tree root, std::string data){
    if(root->a->data == data){
        return false;
    }else if(root->b->data == data){
        return false;
    }else if(root->c->data == data){
        return false;
    }else if(root->d->data == data){
        return false;
    }else if(root->e->data == data){
        return false;
    }else{
        return true;
    }
}
void insertree(tree& root, pb& temp){
    if(root->a == nullptr){
        root->a = temp;
    }else if(root->b == nullptr){
        root->b = temp;
    }else if(root->c == nullptr){
        root->c = temp;
    }else if(root->d == nullptr){
        root->d = temp;
    }else if(root->e == nullptr){
        root->e = temp;
    }
}
void passGO(tree& root, std::string data, pb& temp){
    if(root->a->data == data){
        insertree(root->a, temp);
    }else if(root->b->data == data){
        insertree(root->b, temp);
    }else if(root->c->data == data){
        insertree(root->c, temp);
    }else if(root->d->data == data){
        insertree(root->d, temp);
    }else if(root->e->data == data){
        insertree(root->e, temp);
    }
}
void preOrder(tree root){
    if(root != nullptr){
        std::cout << "1. " << root->a->data << ": \n";
        preOrder(root->a);
        std::cout << "2. " << root->b->data << ": \n";
        preOrder(root->b);
        std::cout << "3. " << root->c->data << ": \n";
        preOrder(root->c);
        std::cout << "4. " << root->d->data << ": \n";
        preOrder(root->d);
        std::cout << "5. " << root->e->data << ": \n";
        preOrder(root->e);
    }
}
void cDP(tree& root, pfilm Elem){
    pb ha = new branch;
    ha->data = Elem->dp;
    ha->a = nullptr;
    ha->b = nullptr;
    ha->c = nullptr;
    ha->d = nullptr;
    ha->e = nullptr;
    
    if(root == nullptr){
        pb akar = new branch;
        akar->data = "akar";
        akar->a = ha;
        akar->b = nullptr;
        akar->c = nullptr;
        akar->d = nullptr;
        akar->e = nullptr;
    }else{
        insertree(root, ha);
    }
}
void cJudul(tree& root, pfilm Elem){
    pb ha = new branch;
    ha->data = Elem->judul;
    ha->a = nullptr;
    ha->b = nullptr;
    ha->c = nullptr;
    ha->d = nullptr;
    ha->e = nullptr;

    std::string temp = Elem->dp;
    if(root == nullptr){
        cDP(root, Elem);
        insertree(root->a, ha);
    }else{
        if(check(root, temp)){
            if(root->a == nullptr){
                insertree(root->a, ha);
            }else if(root->b == nullptr){
                insertree(root->b, ha);
            }else if(root->c == nullptr){
                insertree(root->c, ha);
            }else if(root->d == nullptr){
                insertree(root->d, ha);
            }else if(root->e == nullptr){
                insertree(root->e, ha);
            }
        }else{
            passGO(root, temp, ha);
        }
    }
}
void transtree(tree& root){
    std::cout << "===============Movilist===============" << std::endl;
    std::cout << "Director: " << std::endl;
    preOrder(root);
}


