#pragma once
template<class T>
struct LCLinkedNode {
	T val;
	LCLinkedNode* next;

	LCLinkedNode() :val(0), next(nullptr) {}

	LCLinkedNode(T value) :val(value), next(nullptr) {}

	LCLinkedNode(T value, LCLinkedNode* Node) :val(value), next(Node) {}

};
template <class NODETYPE>
class LCMyLinkedList {
public:
	LCLinkedNode<NODETYPE>* head;
	LCLinkedNode<NODETYPE>* tail;
	int count;
	/** Initialize your data structure here. */
	LCMyLinkedList() : head(), tail(), count(0) {}

	~LCMyLinkedList();

	//reverse
	void reverse();

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	NODETYPE get(int index);

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(NODETYPE val);

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(NODETYPE val);

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, NODETYPE val);

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index);
	void display();
};