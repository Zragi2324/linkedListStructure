#include "linkedList.h"
#include <iostream>


/*
Purpose: Be able to push a new node into a linked list in all 4 different cases

case#1: empty list
case#2: Front of list
case#3: midle of list
case#4: end of list



*/
void linkedList::push(int data) { // This push will push to begining of list or end

	if (head == nullptr) {  // empty list, insert first position
		node* newNode = new node(data);
		head = newNode;
		tail = newNode;


	}
	else {
		node* newNode = new node(data);
		tail->next = newNode; //extend the tail to the new node
		tail = newNode; // set the tail to the newNode
	}




	

}


/*
Purpose: inserrt at the front of the list
conditions: set new node to front of lsit, must set head to new node */
void linkedList::pushFront(int data) {

	node* newNode = new node(data);
	newNode->next = head;
	head = newNode;
	tail = newNode;

}


int linkedList::countList() const {
	
	int num = 0;
	if (head == nullptr) {
		num = 0;
	}
	else {
		node* temp = head;
		while (temp != nullptr) {
			num++;
			temp = temp->next; // traverse
		}
	}
	return num;
}

void linkedList::pushMiddle(int data) {

	if (head == nullptr) {
		pushFront(data);
	}
	else {
		
	int num = countList();
	int midPoint = 0;

	if ((num % 2) == 0) { // if even
		midPoint = (num / 2);
	}
	else {
		midPoint = (num + 1) / 2; //if odd
	}
		node* temp = head;
		
		while (midPoint > 1) {
			temp = temp->next;
			--midPoint;
		}

		node* newNode = new node(data);
		newNode->next = temp->next;
		temp->next = newNode;

		//std::cout << "middle element is : " << temp->data << "\n";
	}
}

void linkedList::print() const {

	if (head == nullptr) {
		std::cout << "List is empty" << "\n";
	}
	else {
		node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << "\n";
			temp = temp->next;
		}
	}

}

void linkedList::deleteIndex(int const numToDelete) {


	int num = 0;
	int len = countList();
	if (head == nullptr) {
		std::cout << "Nothing to delete" << "\n";
		return;
	}
	
	//  error handeling when the index inputted is too large 
	if (numToDelete >len ) {
		std::cout << "Can't delete index too large" << "\n";
		return;
	}
	
	// deleting first node in list and updating head
	if (numToDelete == 0) {
		node* temp = head;
		head = temp->next;
		delete temp;
		return;
	}

	// last node in list, updating the tail
	if (numToDelete == len) {
		node* temp = head;
		while (num < len-2) {
			num++;
			temp = temp->next;
			
		}
		node* temp2 = temp->next;
		temp->next = nullptr;
		tail = temp;
		delete temp2;
		return;
	}

	// iterating to the index
	node* temp = head;
	while (num < numToDelete-2) {
		
		num++;
		temp = temp->next;
	}
	node* temp2 = temp->next;
	temp->next = temp->next->next;
	delete temp2;
}


/*
Purpose: Reverses a linked list. Time complexity O(n) space auxilary O(1) addditonal space needed does not rely on size of lis*/
void linkedList::reverseList() {

	// created three pointers

	node* curr = head;  // points to head 
	node* prev = nullptr; // will point to previous element
	node* next = nullptr; // will hold the element in list

	while (curr != nullptr) { // as long as the list doesn't end, until the current pointer hits the end of list

		next = curr->next; // we set the next pointer to next element in list

		curr->next = prev; // we reverse the next element after current element by setting it to previous element


		prev = curr; // then set the previous element to the current element (moving up the list by one)
		curr = next; // moving the current element by one, setting it to next


	}
	head = prev; // after loop ends we update the head to what the previous element is (1 item in list)



}