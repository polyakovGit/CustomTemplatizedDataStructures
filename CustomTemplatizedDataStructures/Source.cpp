#include <iostream>

#include "LClinkedList.h"
#include "LClinkedList.inl"



int main() {

	LCMyLinkedList<int> LCMyLinkedList;
	LCMyLinkedList.addAtHead(0);
	LCMyLinkedList.addAtIndex(1, 4);
	LCMyLinkedList.addAtTail(8);
	LCMyLinkedList.addAtHead(5);
	LCMyLinkedList.addAtIndex(4, 3);
	LCMyLinkedList.addAtTail(0);
	LCMyLinkedList.display();
	LCMyLinkedList.reverse();
	LCMyLinkedList.display();
	return 0;
}