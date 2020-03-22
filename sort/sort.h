#ifndef __SORT_H__
#define __SORT_H__

#include <vector>
using namespace std;

class my_sort {
public:
    vector<int> bubble_sort(vector<int> elements);
    vector<int> select_sort(vector<int> elements);
    vector<int> insert_sort(vector<int> elements);
    vector<int> shell_sort(vector<int> elements);
    vector<int> merge_sort(vector<int> elements);
    void _merge_sort(vector<int> &elements, int low, int high);
    void _quick_sort(vector<int> &elements, int low, int high);
    vector<int> quick_sort(vector<int> elements);
    vector<int> heap_sort(vector<int> elements);
    vector<int> count_sort(vector<int> elements);
    vector<int> bucket_sort(vector<int> elements);
    vector<int> radix_sort(vector<int> elements);

    static void swap(int& a, int& b);
    static void print_data(const vector<int>& elements);
    static void merge(vector<int> &elements, int low, int mid, int high);
};

#endif
