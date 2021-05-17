struct film{
    std::string judul;
    std::string synopsis;
    std::string media;
    std::string dp;
    int rating;
    int visited = 0;
    film* next;
};

typedef film* pfilm;

struct queue{
    pfilm head;
    pfilm tail;
};
struct branch{
    std::string data;
    branch* a;
    branch* b;
    branch* c;
    branch* d;
    branch* e;
};

using pb = branch*;
using tree = pb;
