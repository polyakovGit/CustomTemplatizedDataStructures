#include <iostream>

struct LinkedNode {
	int val;
	LinkedNode* next;

	LinkedNode() :val(0), next(nullptr) {}

	LinkedNode(int value) :val(value), next(nullptr) {}

	LinkedNode(int value, LinkedNode* Node) :val(value), next(Node) {}

};

class MyLinkedList {
public:
	LinkedNode* head;
	LinkedNode* tail;
	int count;
	/** Initialize your data structure here. */
	MyLinkedList() : head(), tail(), count(0) {}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		LinkedNode* current = head;
		while(true) {
			if (!current) return -1;
			if (!index) return current->val;
			current = current->next;
			--index;
		}
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		if (!head)
			head = tail = new LinkedNode(val);
		else head = new LinkedNode(val, head);
		++count;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if (!tail)
			head = tail = new LinkedNode(val);
		else {
			tail->next = new LinkedNode(val);
			tail = tail->next;
		}
		++count;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index <= count) {
			if (index == count)
			{
				addAtTail(val);
			}
			else {
				LinkedNode* current = head;
				if (index == 0)
					addAtHead(val);
				else {
					while (--index) {
						current = current->next;
					}
					current->next = new LinkedNode(val, current->next);
					++count;
				}
			}
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < count) {
			if (count == 1) {
				delete head;
				head = tail = nullptr;
				count = 0;
				return;
			}
			if (index == 0) {
				LinkedNode* current = head->next;
				delete head;
				head = current;
				--count;
				return;
			}
			if (index == count - 1) {
				LinkedNode* current = head;
				while (--index)current = current->next;
				delete tail;
				tail = current;
				current->next = nullptr;
				--count;
				return;
			}
			LinkedNode* current = head;
			while (--index)current = current->next;
			LinkedNode* temp = current->next;
			current->next = temp->next;
			delete temp;
			--count;
		}
	}

	void display() {
		LinkedNode* current = head;
		while (current) {
			std::cout << current->val << ' ';
			current = current->next;
		}
	}
};

int main() {

	//MyLinkedList myLinkedList;
	//myLinkedList.addAtHead(0);
	//myLinkedList.addAtIndex(1, 4);
	//myLinkedList.addAtTail(8);
	//myLinkedList.addAtHead(5);
	//myLinkedList.addAtIndex(4, 3);
	//myLinkedList.addAtTail(0);
	//myLinkedList.display();
	return 0;
}