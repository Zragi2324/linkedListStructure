
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
class linkedList
{
private:
	struct node {
		int data;
		node* next;
		node(int num) {
			data = num;
			next = nullptr;
		}
	};


	node* head; // if you dont add these to private variables then you must pass by reference, and create separate head and tail
	node* tail;
public:

	linkedList() {  // when the constructor is called we set the head and tail null (an empty list)
		head = nullptr;
		tail = nullptr;
	}

	~linkedList() {  // destructor is called when program ends
		node* temp;
		while (head != nullptr) {
			temp = head->next;
			delete head;
			head = temp;
		}

	}

	void push(int data);
	void pushFront(int data);
	void pushMiddle(int data);
	void print() const;
	int countList() const;
	void deleteIndex(int const numTodelete);
	void reverseList();

};
#endif

