#include "link_list.h"
#include <iostream>
using namespace std;

Node* Link_list::new_node(int data)
{
	Node* node = nullptr;

	try {
		node = new Node(data);
	}
	catch (const bad_alloc & ex) {
		cerr << ex.what() << endl;
		return NULL;
	}

	return node;
}

int Link_list::init_list()
{
	if (!(head = new_node(0))) {
		return -1;
	}

	return 0;
}
int Link_list::add_first(int data)
{
	if (!size) {
		head->data = data;
		head->next = head;
		head->pre = head;
		size++;
		return 0;
	}

	Node* node = nullptr;
	
	node = new_node(data);
	if (!node) {
		return -1;
	}

	node->next = head;
	node->pre = head->pre;
	head->pre->next = node;
	head->pre = node;
	size++;

	head = node;

	return 0;
}

int Link_list::add_last(int data)
{
	if (!size) {
		head->data = data;
		head->next = head;
		head->pre = head;
		size++;
		return 0;
	}

	Node* node = nullptr;

	node = new_node(data);
	if (!node) {
		return -1;
	}

	node->next = head;
	node->pre = head->pre;
	head->pre->next = node;
	head->pre = node;
	size++;

	return 0;
}

int Link_list::add(int index, int element)
{
	int i = 0;
	Node* tmp = head;
	
	if (!size || ((index > size) && !(index = index % size))) {
		return this->add_last(element);
	}

	while (i++ < index) {
		tmp = tmp->next;
	}

	Node* node = new_node(element);

	if (!node) {
		return -1;
	}

	node->next = tmp->next;
	node->pre = tmp;
	tmp->next->pre = node;
	tmp->next = node;

	return 0;
}

int Link_list::get_first()
{
	return head->data;
}

int Link_list::get_last()
{
	return head->pre->data;
}

int Link_list::get_data(int index)
{
	int i = 0;
	Node* tmp = head;

	if (size == 0) {
		return -1;
	}

	while (i++ < index) {
		tmp = tmp->next;
	}

	return tmp->data;
}

int Link_list::remove_first()
{
	if (!size) {
		return -1;
	} else if(size == 1) {
		head->data = 0;
		size--;
		return 0;
	}

	Node* node = head;
	head = head->next;

	node->pre->next = node->next;
	node->next->pre = node->pre;

	delete node;
	size--;

	return 0;
}

int Link_list::remove_last()
{
	if (!size) {
		return -1;
	}
	else if (size == 1) {
		head->data = 0;
		size--;
		return 0;
	}

	Node* node = head->pre;

	head->pre = node->pre;
	node->pre->next = head;

	delete node;
	size--;

	return 0;
}

int Link_list::remove_data(int data)
{
	if (!size) {
		return -1;
	}
	else if(data == head->data){
		return remove_first();
	}
	else if (data == head->pre->data) {
		return remove_last();
	}

	Node* node = head->next;

	while (node != head) {
		if (node->data == data) {
			node->pre->next = node->next;
			node->next->pre = node->pre;
			delete node;
			return 0;
		}
		node = node->next;
	}

	return -1;
}

void Link_list::print_list()
{
	Node* node = head;

	cout << node->data << " ";
	node = node->next;
	while (node != head) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

int Link_list::remove_all()
{
	if (size == 0) {
		return 0;
	}

	Node* node = head;

	while (size) {
		remove_first();
	}
	
	return 0;
}

unsigned int Link_list::get_size()
{
	return size;
}

