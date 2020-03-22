#include "heap.h"
#include <iostream>
#include <string.h>
using namespace std;

void heap::print_data()
{
    for (int i = 1; i <= size; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

int heap::get_size()
{
    return size;
}

bool heap::is_max_heap(const heap& h)
{
    if (h.size == 0 || h.size == 1) {
        return true;
    }

    int index = 1;

    while (index <= h.size / 2) {
        if (index * 2 + 1 <= h.size) {
            if (h.elements[index] < h.elements[index * 2] || 
                h.elements[index] < h.elements[index * 2 + 1]) {
                return false;
            }
        } else {
            if (h.elements[index] < h.elements[index * 2]) {
                return false;
            }
        }
        index++;
    }

    return true;
}

bool heap::is_min_heap(const heap& h)
{
    if (h.size == 0 || h.size == 1) {
        return true;
    }

    int index = 1;

    while (index <= h.size / 2) {
        if (index * 2 + 1 <= h.size) {
            if (h.elements[index] > h.elements[index * 2] || h.elements[index] > h.elements[index * 2 + 1]) {
                return false;
            }
        } else {
            if (h.elements[index] > h.elements[index * 2]) {
                return false;
            }
        }
        index++;
    }

    return true;
}

void heap::shift_down(int index, bool max)
{
    int parent_data = elements[index];

    int i = index * 2;
    for (; i <= size; i *= 2) {

        if (max) {
            if (i + 1 <= size && elements[i] < elements[i + 1]) {
                i++;
            }
            if (elements[i] > parent_data) {
                elements[index] = elements[i];
                index = i;
            } else {
                break;
            }
        } else {
            if (i + 1 <= size && elements[i] > elements[i + 1]) {
                i++;
            }
            if (elements[i] < parent_data) {
                elements[index] = elements[i];
                index = i;
            } else {
                break;
            }
        }
    }
    elements[index] = parent_data;

    return;
}

int heap::heap_create(int* data, int n, bool max)
{
    if (n > capacity) {
        return -1;
    }

    size = n;
    memcpy(elements + 1, data, sizeof(int) * size);
    print_data();

    for (int i = size / 2; i >= 1; i--) {
        shift_down(i, max);
    }

    return 0;
}

int heap::heap_create_max(int* data, int n)
{
    max = 1;
    return heap_create(data, n, true);
}

int heap::heap_create_min(int* data, int n)
{
    max = 0;
    return heap_create(data, n, false);
}

int heap::heap_insert(int data)
{

    if (size == capacity) {
        cout << "the heap is full."
             << endl;
        return -1;
    }

    size++;
    elements[size] = data;

    int parent = size / 2;
    int child = size;

    while (parent >= 1) {
        if (max) {
            if (data > elements[parent]) {
                elements[child] = elements[parent];
                child = parent;
                parent = parent / 2;
            } else {
                break;
            }
        } else {
            if (data < elements[parent]) {
                elements[child] = elements[parent];
                child = parent;
                parent = parent / 2;
            } else {
                break;
            }
        }
    }

    elements[child] = data;

    return 0;
}

int heap::heap_delete()
{
    if (size == 0) {
        cout << "The heap is empty.\n"
             << endl;
        return -1;
    }

    int res = elements[1];
    elements[1] = elements[size];
    size--;

    
    int data = elements[1];
    int child = 1, parent = child;

    while (child <= size / 2) {
        parent = child;
        child = child * 2;
        if (max) {
            if (child + 1 <= size && elements[child] < elements[child + 1]) {
                child++;
            }
            if (data < elements[child]) {
                elements[parent] = elements[child];
            } else {
                elements[parent] = data;
                return res;
            }
        } else {
            if (child + 1 <= size && elements[child] > elements[child + 1]) {
                child++;
            }
            if (data > elements[child]) {
                elements[parent] = elements[child];
            } else {
                elements[parent] = data;
                return res;
            }
        }
    }

    elements[child] = data;

    return res;
}