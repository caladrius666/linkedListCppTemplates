#include <iostream>
#include "list2.hpp"

using namespace std;

int main(){
    list2<int> l;
    listDestroy(l);
    listPrint(l);
    for (int i = 0; i < 10; i++)
        listInsert(l, i);
    cout << endl;
    cout << l.size << endl;
    listPrint(l);
    cout << endl;
    listPrintInverse(l);
    cout << endl;
    listRemove(l, 9);
    listRemove(l, 5);
    listRemove(l, 0);
    listInsert(l, 10);
    listPrint(l);
    cout << endl;
    for (int i = l.size - 1; i >= 0; i--)
        listRemove(l, i);
    listPrint(l);
    cout << endl;
    cout << l.size << " " << l.begin << " " << l.end;
    cout << endl;
    for (int i = 0; i < 10; i++)
        listInsert(l, i);
    listPrint(l);
    cout << endl;
    listDestroy(l);
}
