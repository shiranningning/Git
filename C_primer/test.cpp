#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

int main1()
{
    //拷贝使用的list和vector
    list<int> list1(7, 8);
    vector<int> vec2(5, 2);

    //创建的目标容器
    vector<double> vec1(list1.begin(), list1.end());
    vector<double> vec3(vec2.begin(), vec2.end());

    //验证正确性
    vector<double>::iterator it1 = vec1.begin();
    vector<double>::iterator it2 = vec3.begin();
    for (it1; it1 != vec1.end(); it1++) {
        cout << *it1 << " ";
    }
    cout << endl;
    for (it2; it2 != vec3.end(); it2++) {
        cout << *it2 << " ";
    }
    cout << endl;

    vector<int> vec4(10, 1);
    vector<int> vec5(5, 2);

    vector<int>::iterator it = vec4.begin() + 5;

    vec4.swap(vec5);

    cout << *it << endl;

    for (auto it : vec4) {
        cout << it << " ";
    }
    cout << endl;
    for (auto it : vec5) {
        cout << it << " ";
    }
    cout << endl;

    cout << vec4.max_size() << endl;

    return 0;
}

int main2()
{
    int i = 0;
    vector<int> vec(10, 0);
    for (auto& it : vec) {
        it = i++;
        cout << it << " ";
    }
    cout << endl;

    cout << vec.at(0) << " " << vec[0] << " " << *(vec.begin()) << endl;
    cout << vec.front() << " " << vec.back() << endl;

    vec.erase(vec.begin(), vec.begin());
    vec.erase(vec.end(), vec.end());
    for (auto it : vec) {
        cout << it << " ";
    }
    cout << endl;

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> vec1(arr, arr + 10);
    list<int> l1(arr, arr + 10);
    for (auto it : vec1) {
        cout << it << " ";
    }
    cout << endl;
    for (auto it : l1) {
        cout << it << " ";
    }
    cout << endl;

    sleep(100);
    return 0;
}

int main()
{
    vector<int> vec;

    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    vector<int>::iterator it = find(vec.begin(), vec.end(), 5);
    if (it == vec.end()) {
        cout << "Not find" << endl;
    }
    find_if();

    return 0;
}