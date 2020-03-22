#ifndef __HEAP_H__
#define __HEAP_H__

#include <string.h>
class heap {
public:
    heap()
    {
        capacity = 100;
        size = 0;
        max = 1;
        elements = new int[capacity + 1]();
    }
    heap(int capacity)
        : capacity(capacity)
    {
        size = 0;
        elements = new int[capacity + 1]();
    }
    ~heap()
    {
        delete[] elements;
    }

public:
    heap(const heap& h) 
    {
        this->max = h.max;
        this->capacity = h.capacity;
        this->size = h.size;
        this->elements = new int[this->capacity + 1]();
        memcpy(this->elements + 1, h.elements + 1, h.size * sizeof(int));
    }
    heap& operator=(const heap& h) 
    {
        this->max = h.max;
        this->capacity = h.capacity;
        this->size = h.size;
        this->elements = new int[this->capacity + 1]();
        memcpy(this->elements + 1, h.elements + 1, h.size * sizeof(int));
        return *this;
    }

public:
    void shift_down(int index, bool max);
    int heap_create_max(int* data, int n);
    int heap_create_min(int* data, int n);
    int heap_insert(int data);
    int heap_delete();
    void print_data();
    int get_size();

public:
    static bool is_max_heap(const heap& h);
    static bool is_min_heap(const heap& h);

private:
    int heap_create(int* data, int n, bool max);

private:
    int* elements;
    int size;
    int capacity;
    bool max;
};

#endif