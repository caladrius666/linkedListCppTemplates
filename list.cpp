#include <iostream>
#include "list.hpp"

int main() {
    List<int> intList;
    list_init(intList);
    int i;
    for(int i = 0; i < 10; ++i) {
        list_insert(intList, i);
    }
    list_print(intList, std::cout);
    std::cout << "/" << intList.size << "/";
    std::cout << std::endl;
    for (int i = 90; i <= 100; i++)
        list_insert_back(intList, i);
    list_print(intList, std::cout);
    std::cout << "/" << intList.size << "/";
    std::cout << std::endl;

    list_insert_i(intList, 0 , -1);
    list_insert_i(intList, 21, -1);
    list_insert_i(intList, 13, -1);
    list_print(intList, std::cout);
    std::cout << "/" << intList.size << "/";
    std::cout << std::endl;

    list_swap(intList, 0, 23);
    list_print(intList, std::cout);
    list_swap(intList, 5, 6);
    list_print(intList, std::cout);
    list_swap(intList, 4, 7);
    list_print(intList, std::cout);
    list_swap(intList, 0, 1);
    list_print(intList, std::cout);
    list_swap(intList, 22, 23);
    list_print(intList, std::cout);
    std::cout << "/" << intList.size << "/";
    std::cout << std::endl;

    list_remove(intList, 23);
    list_remove(intList, 0);
    list_remove(intList, 4);
    list_print(intList, std::cout);
    std::cout << "/" << intList.size << "/";
    std::cout << std::endl;

    list_reverse(intList);
    list_print(intList, std::cout);
    std::cout << "/" << intList.size << "/";
    std::cout << std::endl;

    list_sort(intList);
    list_print(intList, std::cout);
    std::cout << "/" << intList.size << "/";
    std::cout << std::endl;

    std::cout <<"End: " << intList.end->data;
    list_destroy(intList);
}
