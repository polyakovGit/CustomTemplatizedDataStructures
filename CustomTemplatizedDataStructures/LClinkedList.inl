#include "LClinkedList.h"

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
template<class NODETYPE>
NODETYPE MyLinkedList<NODETYPE>::get(int index) {
	LinkedNode<NODETYPE>* current = head;
	while (true) {
		if (!current) return -1;
		if (!index) return current->val;
		current = current->next;
		--index;
	}
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
template<class NODETYPE>
void  MyLinkedList<NODETYPE>::addAtHead(NODETYPE val) {
	if (!head)
		head = tail = new LinkedNode<NODETYPE>(val);
	else head = new LinkedNode<NODETYPE>(val, head);
	++count;
}

/** Append a node of value val to the last element of the linked list. */
template<class NODETYPE>
void MyLinkedList<NODETYPE>::addAtTail(NODETYPE val) {
	if (!tail)
		head = tail = new LinkedNode<NODETYPE>(val);
	else {
		tail->next = new LinkedNode<NODETYPE>(val);
		tail = tail->next;
	}
	++count;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
template<class NODETYPE>
void MyLinkedList<NODETYPE>::addAtIndex(int index, NODETYPE val) {
	if (index <= count) {
		if (index == count)
		{
			addAtTail(val);
		}
		else {
			LinkedNode<NODETYPE>* current = head;
			if (index == 0)
				addAtHead(val);
			else {
				while (--index) {
					current = current->next;
				}
				current->next = new LinkedNode<NODETYPE>(val, current->next);
				++count;
			}
		}
	}
}

/** Delete the index-th node in the linked list, if the index is valid. */
template<class NODETYPE>
void MyLinkedList<NODETYPE>::deleteAtIndex(int index) {
	if (index < count) {
		if (count == 1) {
			delete head;
			head = tail = nullptr;
			count = 0;
			return;
		}
		if (index == 0) {
			LinkedNode<NODETYPE>* current = head->next;
			delete head;
			head = current;
			--count;
			return;
		}
		if (index == count - 1) {
			LinkedNode<NODETYPE>* current = head;
			while (--index)current = current->next;
			delete tail;
			tail = current;
			current->next = nullptr;
			--count;
			return;
		}
		LinkedNode<NODETYPE>* current = head;
		while (--index)current = current->next;
		LinkedNode<NODETYPE>* temp = current->next;
		current->next = temp->next;
		delete temp;
		--count;
	}
}

template<class NODETYPE>
void MyLinkedList<NODETYPE>::display() {
	LinkedNode<NODETYPE>* current = head;
	while (current) {
		std::cout << current->val << ' ';
		current = current->next;
	}
}