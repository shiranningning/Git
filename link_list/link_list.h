#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

struct Node {
	int data;
	Node* next;
	Node* pre;
	Node(int data = 0, Node* next = nullptr, Node* pre = nullptr) :
		data(data), next(next), pre(pre) {}
	~Node() {
		data = 0;
		next = nullptr;
		pre = nullptr;
	}
};

class Link_list {
public:
	Link_list() {
		head = nullptr;
		size = 0;
	}
	~Link_list() {
		remove_all();
		size = 0;
	}
	Node* new_node(int);

public:
	int init_list();
	int add_first(int);
	int add_last(int);
	int add(int index, int element);
	int get_first();
	int get_last();
	int get_data(int);
	int remove_first();
	int remove_last();
	int remove_data(int);
	int remove_all();
	void print_list();
	unsigned int get_size();

private:
	Node* head;
	unsigned int size;
};

#endif // !__LINK_LIST_H__

