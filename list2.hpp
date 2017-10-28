#ifndef TEMPLATES_LIST2_HPP
#define TEMPLATES_LIST2_HPP

#include <typeindex>

template<typename DataType>
struct node{
    DataType data;
    node<DataType>* next;
    node<DataType>* prev;
};

template<typename DataType>
struct list2{ //With init
    node<DataType>* begin = nullptr;
    node<DataType>* end = nullptr;
    int size = 0;
};

template<typename DataType>
struct listIterator{
    node<DataType>* current;
};

template<typename DataType>
listIterator<DataType> listIterInit(list2<DataType>& lst) {
    listIterator<DataType> it;
    it.current = lst.begin;
    return it;
}

template<typename DataType>
bool listIterHasNext(listIterator<DataType> & it) {
    return it.current->next != nullptr;
}

template<typename DataType>
DataType * listIterNext(listIterator<DataType> & it){
    if (it.current){
        DataType * ptr = & (it.current->data);
        it.current = it.current->next;
        return ptr;
    }
    return nullptr;
}

template<typename DataType>
bool listIterHasPrev(listIterator<DataType> & it) {
    return it.current->prev != nullptr;
}

template<typename DataType>
DataType * listIterPrev(listIterator<DataType> & it){
    if (it.current){
        DataType* ptr = &(it.current->data);
        it.current = it.current->prev;
        return ptr;
    }
    return nullptr;
}

template<typename DataType>
listIterator<DataType> getIterOnI(list2<DataType>& lst, const int& i){
    if ((i < 0 or i >= lst.size) and lst.size != 0){
        std::cout << "getIterOnI: out of range!" << std::endl;
        return listIterInit(lst);
    }
    if (lst.size == 0){
        return listIterInit(lst);
    }
    listIterator<DataType> it = listIterInit(lst);
    for (int j = 0; j < i; j++){
        listIterNext(it);
    }
    return it;
}

template<typename DataType>
void listInsert(list2<DataType> & lst, const DataType & v){
    lst.size++;
    auto* newnode = new node<DataType>;
    newnode->data = v;
    newnode->prev = nullptr;
    newnode->next = lst.begin;
    if (lst.begin != nullptr){
        lst.begin->prev = newnode;
    }
    lst.begin = newnode;
    if (lst.end == nullptr){
        lst.end = newnode;
    }
}

template<typename DataType>
void listPrint(list2<DataType> & lst){
    if (lst.size == 0){
        std::cout << "listPrint: List is empty!";
        return;
    }else{
        listIterator<DataType> it = getIterOnI(lst, 0);
        do{
            DataType* v = listIterNext(it);
            std::cout << *v << ' ';
        }while (listIterHasNext(it));
        DataType* v = listIterNext(it);
        std::cout << *v << ' ';
    }
}

template<typename DataType>
void listPrintInverse(list2<DataType> & lst){
    if (lst.size == 0){
        std::cout << "listPrint: List is empty!";
        return;
    }else{
        listIterator<DataType> it = getIterOnI(lst, lst.size - 1);
        do{
            DataType* v = listIterPrev(it);
            std::cout << *v << ' ';
        }while (listIterHasPrev(it));
        DataType* v = listIterPrev(it);
        std::cout << *v << ' ';
    }
}

template<typename DataType>
void listDestroy(list2<DataType> & lst){
    if(lst.size == 0){
        return;
    }
    listIterator<DataType> it = getIterOnI(lst, 0);
    do{
        node<DataType>* p = it.current;
        listIterNext(it);
        delete p;
    }while(listIterHasNext(it));
    node<DataType>* p = it.current;
    delete p;
    lst.size = 0;
    lst.begin = nullptr;
    lst.end = nullptr;
}

template<typename DataType>
void listRemove(list2<DataType> & lst, int i){
    if (i < 0 or i >= lst.size){
        std::cout << "listRemove: out of range!" << std::endl;
        return;
    }
    listIterator<DataType> it = getIterOnI(lst, i);
    if(it.current == lst.end){
        lst.end = it.current->prev;
    }
    if(listIterHasPrev(it)){
        it.current->prev->next = it.current->next;
        delete it.current;
    }else{
        lst.begin = it.current->next;
        delete it.current;
    }
    if (i == 0 and lst.size == 1){
        lst.begin = nullptr;
        lst.end = nullptr;
    }
    lst.size--;
}

#endif //TEMPLATES_LIST2_HPP