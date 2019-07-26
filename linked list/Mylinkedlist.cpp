#include <bits/stdc++.h>
#define ll long long
using namespace std;

class node {
public:
	int data;
	node* next;

	node(int num){
		data = num;
		next = NULL;
	}
};

void insertAtTail(node* &head, int data);
//------------------------------------------------------------

int length(node*head){
    int len=0;
    while(head!=NULL){
        head = head->next;
        len += 1;
    }
    return len;
}
bool search(node* head, int key){
	if(head == NULL) return false;
	node* temp = head;
	while(temp != NULL) {
		if (temp->data == key) return true;
		temp = temp->next;
	}
	return false;
}
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void deleteAtHead(node*&head){
    if(head==NULL || head->next == NULL){
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
    return;
}
node* midpoint(node* &head){
	if (head == NULL) return head;
	node* fast=head;
	node* slow=head;

	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
void reverse(node* &head) {
	node*C = head; node*P = NULL; node*N;
    while(C!=NULL){
        N = C->next;
        C->next = P;
        P = C;
        C= N;
    }
    head = P;
}
void buildList(node* &head, int size){
	while(size !=0){
		int data; cin>>data;
		insertAtTail(head,data);
		size--;
	}
}
ostream& operator<<(ostream& os, node* head){
	print(head);
	return os;
}
// inserting nodes--------------------------------------------

void insertAtHead(node* &head, int data) {
	node* n = new node(data); //pointer to node
	n->next = head;
	head = n;
}
void insertAtTail(node* &head, int data){
	node* n = new node(data);
	if(head==NULL){head = n; return;}
	node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	} 
	temp->next = n;
}
void insertInMiddle(node* &head, int data, int p){
	if(head == NULL){insertAtHead(head,data); return;}
	else if(length(head)<p){insertAtTail(head,data); return;}
	else {
		node* n = new node(data);
		node* temp = head;
		for (int i = 0; i < p-1; ++i)
		{
			temp = temp->next;
		}
		n->next = temp->next;
		temp->next = n;
		return;
	}
}

//---------------------------------------------------------------


int main() {
    node*head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtTail(head,6);
    insertInMiddle(head,2,3);
    print(head);
    reverse(head);
    print(head);
    
    return 0;
}







