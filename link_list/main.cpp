#include "link_list.h"
#include <unistd.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> array;
	Link_list* list = new Link_list;

	if (list->init_list()) {
		return -1;
	}

	for (int i = 0; i < 10; i++) {
		if (list->add_first(i)) {
			return -1;
		}
	}

	list->add_last(11);
	list->add_last(12);
	list->add_last(13);

	cout << list->get_size() << endl;
	list->print_list();

	list->remove_first();
	list->print_list();
	cout << list->get_size() << endl;

	list->remove_last();
	list->print_list();
	cout << list->get_size() << endl;

	list->remove_all();
	cout << list->get_size() << endl;

	sleep(100);

	return 0;
}