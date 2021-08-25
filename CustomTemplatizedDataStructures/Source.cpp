#include <iostream>

#include "LClinkedList.h"
#include "LClinkedList.inl"
template <class NODETYPE> class Tree;

template <class NODETYPE>
class TreeNode {
	NODETYPE data;
	TreeNode<NODETYPE>* leftPtr{ nullptr };
	TreeNode<NODETYPE>* rightPtr{ nullptr };
	friend class Tree<NODETYPE>;
public:
	TreeNode(const NODETYPE& d) :data(d) {}
	NODETYPE getData() const { return data; }
};

template <class NODETYPE>
class Tree {
	TreeNode <NODETYPE>* rootPtr{ nullptr };

	void insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
		if (*ptr == nullptr)
			*ptr = new TreeNode<NODETYPE>(value);
		else {
			if (value < (*ptr)->getData())
				insertNodeHelper(&((*ptr)->leftPtr), value);
			else if (value > (*ptr)->getData())
				insertNodeHelper(&((*ptr)->rightPtr), value);
			else std::cout << "DATA DUPLICATE: " << value << std::endl;
		}
	}

	void preOrderHelper(TreeNode<NODETYPE>* ptr)const {
		if (ptr != nullptr) {
			std::cout << ptr->data << ' ';
			preOrderHelper(ptr->leftPtr);
			preOrderHelper(ptr->rightPtr);
		}
	}

	void inOrderHelper(TreeNode<NODETYPE>* ptr)const {
		if (ptr != nullptr) {
			inOrderHelper(ptr->leftPtr);
			std::cout << ptr->data << ' ';
			inOrderHelper(ptr->rightPtr);
		}
	}

	void postOrderHelper(TreeNode<NODETYPE>* ptr)const {
		if (ptr != nullptr) {
			postOrderHelper(ptr->leftPtr);
			postOrderHelper(ptr->rightPtr);
			std::cout << ptr->data << ' ';
		}
	}
	
public:
~Tree() {
		delete rootPtr;
	}

	void insertNode(const NODETYPE& value) {
		insertNodeHelper(&rootPtr, value);
	}

	void preOrderTraversal() const {
		preOrderHelper(rootPtr);
	}

	void inOrderTraversal() const {
		inOrderHelper(rootPtr);
	}

	void postOrderTraversal() const {
		postOrderHelper(rootPtr);
	}
};

int main() {
	Tree<int> DmyTree;
	DmyTree.insertNode(50);
	DmyTree.insertNode(25);
	DmyTree.insertNode(75);
	DmyTree.insertNode(12);
	DmyTree.insertNode(33);
	DmyTree.insertNode(67);
	DmyTree.insertNode(88);
	DmyTree.insertNode(6);
	DmyTree.insertNode(13);
	DmyTree.insertNode(68);
	DmyTree.postOrderTraversal();

	//LCMyLinkedList<int> LCMyLinkedList;
	//LCMyLinkedList.addAtHead(0);
	//LCMyLinkedList.addAtIndex(1, 4);
	//LCMyLinkedList.addAtTail(8);
	//LCMyLinkedList.addAtHead(5);
	//LCMyLinkedList.addAtIndex(4, 3);
	//LCMyLinkedList.addAtTail(0);
	//LCMyLinkedList.display();
	//LCMyLinkedList.reverse();
	//LCMyLinkedList.display();
	return 0;
}