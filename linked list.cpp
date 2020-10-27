#include<iostream>
using namespace std;
class Single_LinkedList_Node {
public:
	int number;
	Single_LinkedList_Node * next;
	Single_LinkedList_Node(int num) {
		number = num;
		next = NULL;
	}
};

class Single_LinkedList {
public:
	int size;
	Single_LinkedList_Node* head;
	Single_LinkedList_Node* tail;
	Single_LinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void insertNode(int num) {
		if (size == 0) {
			Single_LinkedList_Node* newNode = new Single_LinkedList_Node(num);
			newNode->next = NULL;
			head = newNode;
			tail = newNode;
			size++;
		}
		else {
			Single_LinkedList_Node* newNode = new Single_LinkedList_Node(num);
			tail->next = newNode;
			tail = newNode;
			newNode->next = NULL;
			size++;
		}
	}
	void deleteNode() {
		if (size != 0) {
			Single_LinkedList_Node* tmp;
			tmp = head;
			while (tmp->next != tail) {
				tmp = tmp->next;
			}
			Single_LinkedList_Node* tmp2;
			tmp2 = tail;
			tail = tmp;
			tail->next = NULL;
			delete tmp2;
			size--;
		}
		else {cout << "no node" << '\n';}
	}
	void printlist() {
		Single_LinkedList_Node* tmp;
		tmp = head;
		while (tmp != NULL) {
			cout << tmp->number << ' ';
			tmp = tmp->next;
		}
		cout << '\n';
	}
};
int main() {
	Single_LinkedList SL;
	SL.insertNode(3);
	SL.insertNode(5);
	SL.insertNode(7);
	SL.insertNode(10);
	SL.deleteNode();
	SL.insertNode(100);
	SL.printlist();
	SL.deleteNode();
	SL.printlist();
	return 0;
}