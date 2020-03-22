#include "heap.h"
#include <iostream>
using namespace std;

int main()
{
    heap h1, h2;
    int data[] = { 2, 8, 71, 10, 20, 15, 17, 41, 14, 9 };
    h1.heap_create_max(data, sizeof(data) / sizeof(int));
    h2.heap_create_min(data, sizeof(data) / sizeof(int));

    heap h3 = h1;
    h3.print_data();
    h3 = h2;
    h3.print_data();

    for (int i = 0; i < sizeof(data) / sizeof(int); i++) {
        cout << h1.heap_delete() << " ";
    }
    cout << endl;

    for (int i = 0; i < sizeof(data) / sizeof(int); i++) {
        cout << h2.heap_delete() << " ";
    }
    cout << endl;
}

int main1()
{
    heap h1, h2;
    int insert_data = 80;
    int data[] = { 2, 8, 71, 10, 20, 15, 17, 41, 14, 9 };

    h1.heap_create_max(data, sizeof(data) / sizeof(int));
    if (heap::is_max_heap(h1)) {
        cout << "Is max heap" << endl;
    }
    h1.print_data();
    h1.heap_insert(insert_data);
    if (heap::is_max_heap(h1)) {
        cout << "Is max heap" << endl;
    }
    h1.print_data();

    insert_data = 70;
    h1.heap_insert(insert_data);
    if (heap::is_max_heap(h1)) {
        cout << "Is max heap" << endl;
    }
    h1.print_data();
    h1.heap_delete();
    if (heap::is_max_heap(h1)) {
        cout << "Is max heap" << endl;
    }
    h1.print_data();

    h2.heap_create_min(data, sizeof(data) / sizeof(int));
    if (heap::is_min_heap(h2)) {
        cout << "Is min heap" << endl;
    }
    h2.print_data();
    insert_data = 1;
    h2.heap_insert(insert_data);
    if (heap::is_min_heap(h2)) {
        cout << "Is min heap" << endl;
    }
    h2.print_data();
    insert_data = 16;
    h2.heap_insert(insert_data);
    if (heap::is_min_heap(h2)) {
        cout << "Is min heap" << endl;
    }
    h2.print_data();
    h2.heap_delete();
    if (heap::is_min_heap(h2)) {
        cout << "Is min heap" << endl;
    }
    h2.print_data();
    h2.heap_delete();
    if (heap::is_min_heap(h2)) {
        cout << "Is min heap" << endl;
    }
    h2.print_data();

    return 0;
}