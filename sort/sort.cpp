#include "sort.h"
#include <iostream>
#include <vector>
using namespace std;

void my_sort::swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void my_sort::print_data(const vector<int>& elements)
{
    for (int i = 0; i < elements.size(); i++) {
        cout << elements[i] << " ";
    }

    cout << endl;
}

vector<int> my_sort::bubble_sort(vector<int> elements)
{
    if (elements.size() <= 1) {
        return elements;
    }

    vector<int>::size_type size = elements.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (elements[j] > elements[j + 1]) {
                swap(elements[j], elements[j + 1]);
            }
        }
    }

    return elements;
}

vector<int> my_sort::select_sort(vector<int> elements)
{
    if (elements.size() <= 1) {
        return elements;
    }

    int max = INT32_MIN, max_index = 0;
    vector<int>::size_type size = elements.size();

    int i = 0, j = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i; j++) {
            if (elements[j] > max) {
                max = elements[j];
                max_index = j;
            }
        }
        max = INT32_MIN;
        swap(elements[max_index], elements[j - 1]);
    }

    return elements;
}

vector<int> my_sort::insert_sort(vector<int> elements)
{
    if (elements.size() <= 1) {
        return elements;
    }

    vector<int>::size_type size = elements.size();
    int index = 0, data = 0;

    for (int i = 0; i < size - 1; i++) {
        index = i;
        data = elements[index + 1];
        while (index >= 0 && data < elements[index]) {
            elements[index + 1] = elements[index];
            index--;
        }
        elements[index + 1] = data;
    }

    return elements;
}

vector<int> my_sort::shell_sort(vector<int> elements)
{
    if (elements.size() <= 1) {
        return elements;
    }

    int size = elements.size();
    int gap = size / 2;
    int index = 0, data = 0;

    while (gap >= 1) {
        for (int i = 0; i < size - gap; i++) {
            index = i;
            data = elements[index + gap];
            while (index >= 0 && data < elements[index]) {
                elements[index + gap] = elements[index];
                index -= gap;
            }
            elements[index + gap] = data;
        }

        gap /= 2;
    }

    return elements;
}

void my_sort::merge(vector<int>& elements, int low, int mid, int high)
{
    vector<int> tmp;
    int i = low, j = mid + 1, k = 0;

    for (; i <= mid && j <= high;) {
        if (elements[i] < elements[j]) {
            tmp.push_back(elements[i++]);
        } else {
            tmp.push_back(elements[j++]);
        }
    }

    while (i <= mid) {
        tmp.push_back(elements[i++]);
    }
    while (j <= high) {
        tmp.push_back(elements[j++]);
    }

    for (int l = 0; l < tmp.size(); l++) {
        elements[low + l] = tmp[l];
    }
}

void my_sort::_merge_sort(vector<int>& elements, int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high) {
        _merge_sort(elements, low, mid);
        _merge_sort(elements, mid + 1, high);
        merge(elements, low, mid, high);
    }
}
vector<int> my_sort::merge_sort(vector<int> elements)
{
    if (elements.size() <= 1) {
        return elements;
    }

    _merge_sort(elements, 0, elements.size() - 1);

    return elements;
}

void my_sort::_quick_sort(vector<int>& elements, int low, int high)
{
    if (low >= high) {
        return;
    }

    int i = low, j = high, pivot = elements[(low + high) / 2];
    while (i <= j) {
        while (elements[i] < pivot) {
            i++;
        }
        while (elements[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(elements[i], elements[j]);
            i++;
            j--;
        } else if(i == j){
            i++;
        }
    }

    _quick_sort(elements, low, j);
    _quick_sort(elements, i, high);
}

vector<int> my_sort::quick_sort(vector<int> elements)
{
    if (elements.size() <= 1) {
        return elements;
    }

    _quick_sort(elements, 0, elements.size() - 1);

    return elements;
}

vector<int> my_sort::heap_sort(vector<int> elements)
{
}

vector<int> my_sort::count_sort(vector<int> elements)
{
}

vector<int> my_sort::bucket_sort(vector<int> elements)
{
}

vector<int> my_sort::radix_sort(vector<int> elements)
{
}