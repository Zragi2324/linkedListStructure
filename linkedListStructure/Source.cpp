#include <iostream>
#include "linkedList.h"
using namespace std;




int main() {

	linkedList mylist;

	mylist.push(1);
	mylist.push(2);
	mylist.push(3);
	mylist.push(4);
	mylist.push(5);
	mylist.push(6);
	//mylist.push(8);
	//mylist.pushMiddle(0);
	//mylist.pushFront(0);
	//mylist.pushFront(-1);
	std::cout << " " << endl;
	
	mylist.print();
	
	//  this comment block tests delete func
	/*mylist.deleteIndex(3);
	mylist.deleteIndex(6);
	mylist.deleteIndex(5);
	mylist.print();
	mylist.deleteIndex(0);
	mylist.print();

	*/
	std::cout << "Reversed List" << "\n";
	// testing reversing list
	mylist.reverseList();
	mylist.print();
	mylist.push(7);
	//mylist.print();
	std::cout << std::endl;
	linkedList secondList;
	secondList.push(1);
	secondList.push(2);
	secondList.push(3);
	secondList.print();
}