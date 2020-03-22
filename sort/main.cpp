#include "sort.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    srand((int)time(0));
    vector<int> data, res;

    for (int i = 0; i < 10; i++) {
        data.push_back(rand() % 100);
    }

   
    my_sort ms;
    ms.print_data(data);
    res = ms.bubble_sort(data);
    ms.print_data(res);
    res = ms.select_sort(data);
    ms.print_data(res);
    res = ms.insert_sort(data);
    ms.print_data(res);
    res = ms.shell_sort(data);
    ms.print_data(res);
    res = ms.merge_sort(data);
    ms.print_data(res);
    res = ms.quick_sort(data);
    ms.print_data(res);

    return 0;
}