#ifndef __linked_list_hpp
#define __linked_list_hpp

#include <ostream>

#define nullptr     NULL


template<typename DataType>
struct tNode {
    DataType data;
    tNode* next;
};


template<typename DataType>
struct List {
    tNode<DataType> *begin;
    tNode<DataType> *end;
    int size;
};

template<typename DataType>
void list_init(List<DataType> &lst)
{
    lst.begin = nullptr;
    lst.end = nullptr;
    lst.size = 0;
}

template<typename DataType>
tNode<DataType> * insert_node(tNode<DataType> *p_begin, DataType data)
{
    auto *p = new tNode<DataType>;
    p->data = data;
    p->next = p_begin;
    return p;
}

template<typename DataType>
void list_insert(List<DataType> &lst, const DataType &value)
{
    lst.size += 1;
    tNode<DataType> *newnode = insert_node(lst.begin, value);
    lst.begin = newnode;
    if (lst.end == nullptr)
        lst.end = newnode;
}

template<typename DataType>
void list_print(const List<DataType> &lst, std::ostream &out)
{
    tNode<DataType> *p = lst.begin;
    for(; p; p = p->next)
    {
        out << p->data << '\t';
    }
    std::cout << std::endl;
}

template<typename DataType>
void list_destroy(List<DataType> &lst)
{
    tNode<DataType> *p = lst.begin;
    tNode<DataType> *prev;
    while (p) {
        prev = p;
        p = p->next;
        delete prev;
    }
    lst.size = 0;
    lst.begin = nullptr;
    lst.end = nullptr;
}

template<typename DataType>
tNode<DataType> * insert_node_back(DataType data)
{
    auto *p = new tNode<DataType>;
    p->data = data;
    p->next = nullptr;
    return p;
}

template<typename DataType>
void list_insert_back(List<DataType> &lst, const DataType &value)
{
    lst.size += 1;
    tNode<DataType> *newnode = insert_node_back(value);
    lst.end->next = newnode;
    lst.end = newnode;
}

template<typename DataType>
tNode<DataType>* get_i(List<DataType> & l, int i){
    int iter = 0;
    tNode<DataType> *current = l.begin;
    while (i != iter)
    {
        current = current->next;
        ++iter;
    }
    return current;
}

template<typename DataType>
tNode<DataType>* getnext(List<DataType> & l, int i)
{
    return get_i(l, i)->next;
}

template<typename DataType>
tNode<DataType>* getprev(List<DataType> & l, int i)
{
    if (i == 0)
        return nullptr;
    return get_i(l, i - 1);
}

template<typename DataType>
bool list_insert_i(List<DataType> & l, int i, DataType data)
{
    if (i < 0 or i >= l.size)
        return false;
    auto *newnode = new tNode<DataType>;
    newnode->data = data;
    tNode<DataType> *current = get_i(l, i);
    tNode<DataType> *prev = getprev(l, i);
    if (prev == nullptr)
    {
        newnode->next = current;
        l.begin = newnode;
        l.size++;
    }else
    {
        newnode->next = current;
        prev->next = newnode;
        l.size++;
    }
    return true;
}

template<typename DataType>
bool list_swap(List<DataType> & l, int i, int j)
{
    if (i > j){
        int tmp = i;
        i = j;
        j = tmp;
    }
    tNode<DataType> *nodei = get_i(l ,i);
    tNode<DataType> *nodej = get_i(l, j);
    tNode<DataType> *nodeiprev = getprev(l, i);
    tNode<DataType> *nodejprev = getprev(l, j);
    tNode<DataType> *nodeinext = getnext(l, i);
    tNode<DataType> *nodejnext = getnext(l, j);
    if (i < 0 or i >= l.size  or j < 0 or j >= l.size)
    {
        return false;
    }
    if (i == j)
        return true;
    if (j - i != 1){
        if (nodei == l.begin)
        {
            l.begin = nodej;
            nodej->next = nodeinext;
            nodejprev->next = nodei;
            nodei->next = nodejnext;
        }else
        {
            nodei->next = nodejnext;
            nodej->next = nodeinext;
            nodeiprev->next = nodej;
            nodejprev->next = nodei;
        }
        if (nodej == l.end)
            l.end = nodei;
    }else{
        if (nodei == l.begin)
        {
            l.begin = nodej;
            nodej->next = nodei;
            nodei->next = nodejnext;
        }else
        {
            nodeiprev->next = nodej;
            nodej->next = nodei;
            nodei->next = nodejnext;
        }
        if (nodej == l.end)
            l.end = nodei;
    }
    return true;
}

template<typename DataType>
bool list_remove(List<DataType> & l, int i)
{
    if (i < 0 or i >= l.size)
        return false;
    tNode<DataType> *nodei = get_i(l ,i);
    tNode<DataType> *nodeiprev = getprev(l, i);
    tNode<DataType> *nodeinext = getnext(l, i);
    if (nodei == l.end)
        l.end = nodeiprev;
    if (nodeiprev == nullptr)
        l.begin = nodeinext;
    else
        nodeiprev->next = nodeinext;
    delete nodei;
    l.size--;
    return true;
}

template<typename DataType>
void list_reverse(List<DataType> & l)
{
    for (int i = 0; i < l.size/2; ++i)
        list_swap(l, i, l.size - i - 1);
}

template<typename DataType>
void list_sort(List<DataType> & l)
{
    int siz = l.size;
    for (int i = 0; i < siz - 1; ++i)
        for (int j = 0; j < siz - i -1; ++j)
            if (get_i(l, j)->data > get_i(l, j + 1)->data)
                list_swap(l, j, j + 1);
}

#endif
