/*#include <iostream>
using namespace std;
//Question 1 Singular Linked List
struct Node {
	int varable;
	Node* next;
};
//this prints the list
void printlist(Node *p) {
	while (p != NULL) {
		cout << p->varable << " ";
		p = p->next;
	}
	cout << endl;
}
//this inserts the list
void prepend(Node** p, int x) {
	Node* first = new Node();
	first->varable = x;
	first->next = *p;
	*p = first;
}
//this is append, it goes through the list
void append(Node** p, int x) {
	Node* last = new Node();
	last->varable = x;
	last->next = NULL;
	if (*p == NULL) {
		*p = last;
		return;
	}
	Node* q = *p;
	while (q->next != NULL) {
		q = q->next;
	}
	q->next = last;
}
Node* inserts(Node** prev, int x) {
	if (*prev == NULL) {
		return NULL;
	}
	Node* newNode = new Node();
	newNode->varable = x;
	newNode->next = (*prev)->next;
	(*prev)->next = newNode;
	return newNode;
}
Node* find(Node* p, int x) {
	while (p != NULL && x != p->varable)
		p = p->next;
	return p;
}
Node* erase(Node** p, int num) {
	Node* front = *p;
	Node* prev = NULL;
	if (front != NULL && front->varable == num) {
		*p = front->next;
		delete front;
		return *p;
	}
	while (front != NULL && front->varable != num) {
		prev = front;
		front = front->next;
	}
	if (front == NULL) 
		return NULL;
		prev->next = front->next;
		delete front;
		return prev->next;
}
int main() {
	Node* head = NULL;
	prepend(&head, 1);
	prepend(&head, 2);
	prepend(&head, 3);
	prepend(&head, 4);
	cout << "The List in the beginning" << endl;
	printlist(head);

	Node* headTwo = NULL;
	append(&headTwo, 5);
	append(&headTwo, 6);
	append(&headTwo, 7);
	append(&headTwo, 8);
	append(&headTwo, 9);
	cout << "The List with append" << endl;
	printlist(headTwo);

	int x = 5;
	Node* p = find(headTwo, 2);
	if (p != NULL) {
		inserts(&p,x);
		cout << "The list with Insert"<<x << endl;
		printlist(headTwo);
	}
	else
		cout << x << " Not found" << endl;
	erase(&head, 4);
	cout << "The list after deleting 4" << endl;
	printlist(head);
}
*/

#include <iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
	Node* prev;
};
void printlist(Node* p) {
	while (p != NULL) {
		cout << p->val << ",";
		p = p->next;
	}
}
void prepend(Node** head_Node, Node** tail_Node, int x) {
	Node* first = new Node();
	Node* temp = *head_Node;
	first->val = x;
	first->next = temp;
	first->prev = NULL;
	*head_Node = first;
	if (first->next == NULL) {
		*tail_Node = first;
	}
	else
		temp->prev = first;
}
void append(Node** head_Node, Node** tail_Node, int x) {
	Node* last = new Node();
	Node* temp = *tail_Node;
	last->val = x;
	last->next = NULL;
	*tail_Node = last;
	if (*head_Node == NULL) {
		*head_Node = last;
		last->prev = NULL;
	}
	else {
		last->prev = temp;
		temp->next = last;
	}
}
Node* insertAfter(Node** prev_Node, Node** tail_Node, int x) {
	if (*prev_Node == NULL) {
		return NULL;
	}
	Node *temp = (*prev_Node)->next;
	Node* new_node = new Node();
	new_node->val = x;
	new_node->next = temp;
	new_node->prev = *prev_Node;
	(*prev_Node)->next = new_node;
	if (temp == NULL)
		*tail_Node = new_node;
	else
		temp->prev = new_node;
	return new_node;
}
Node* insertBefore(Node** next_Node, Node** head_Node, int x) {
	if (*next_Node == NULL) {
		return NULL;
	}
	Node* temp = (*next_Node)->prev;
	Node* new_node = new Node();
	new_node->val = x;
	new_node->next = *next_Node;
	new_node->prev = temp;
	(*next_Node)->prev = new_node;
	if (temp == NULL)
		*head_Node = new_node;
	else
		temp->next = new_node;
	return new_node;
}
Node* find(Node* p, int x) {
	while (p != NULL && x != p->val)
		p = p->next;
	return p;
}
void clear(Node* head) {
	Node* temp = new Node();
	while (head != NULL) {
		temp = head;
		head = head->next;
		//free(temp);
	}
	//to check is all of the list is deleted.
	cout << "All is deleteed" << endl;
	
}
void pop_back(Node *head,Node *tail) {
	int temp;
	if (tail) {
		Node* deletes = tail;
		tail = tail->prev;
		if (tail) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}
		delete deletes;
		temp--;
	}
}
void pop_front(Node*head) {
	if (head != NULL) {
		Node* temp = head;
		head = head->next;
		head;
		delete(temp);
		if (head != NULL)
			head->prev = NULL;
	}
}
int size(struct Node* node) {
	int tem = 0;
	while (node != NULL) {
		tem++;
		node = node->next;
	}
	return tem;
}
int is_empty(Node* head,int temp) {
	
	if (temp->head == NULL && temp->tail == NULL) {
		return 1;
	else
		return 0;
	
}
int main() {
	//Check page 13 for double linked list
	Node* head = NULL;
	Node* tail = NULL;
	
	prepend(&head, &tail, 1);
	prepend(&head, &tail, 2);
	prepend(&head, &tail, 3);
	prepend(&head, &tail, 4);
	cout << "The List in the beginning" << endl;
	printlist(head);
	cout << size(head);
	is_empty(head, 0);
	//pop_back(&head,&tail);
	cout << "The list when it deleted" << endl;
	clear(head);
	printlist(head);
	pop_front(head);
	
	Node* headTwo = NULL;
	Node* tail2 = NULL;
	append(&headTwo,&tail2, 12);
	append(&headTwo,&tail2, 10);
	append(&headTwo,&tail2, 5);
	append(&headTwo,&tail2, 8);
	append(&headTwo,&tail2, 9);
	cout << "The List with append" << endl;
	printlist(headTwo);
	
}

