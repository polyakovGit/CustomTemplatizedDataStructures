#include <iostream>

#include "LClinkedList.h"
#include "LClinkedList.inl"

int main() {

	MyLinkedList<int> myLinkedList;
	myLinkedList.addAtHead(0);
	myLinkedList.addAtIndex(1, 4);
	myLinkedList.addAtTail(8);
	myLinkedList.addAtHead(5);
	myLinkedList.addAtIndex(4, 3);
	myLinkedList.addAtTail(0);
	myLinkedList.display();
	return 0;
}