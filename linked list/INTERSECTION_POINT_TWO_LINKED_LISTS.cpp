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

void buildList1(node*&head){

    int data;
    cin>>data;

    while(data!=-1){
        insertAtTail(head,data);
        cin>>data;
    }
}

istream& operator>>(istream &is,node*&head){
    buildList1(head);
    return is;
}
ostream& operator<<(ostream& os, node* head){
	print(head);
	return os;
}


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
node* MID(node* head){
	if(head==NULL || head->next ==NULL) return head;
	node* slow = head;
	node* fast = head;
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

node* MERGE(node* a, node* b){
	if (a==NULL) return b;
	if (b==NULL) return a;
	node* c;
	if (a->data < b->data) {
		c = a;
		c->next = MERGE(a->next,b);
	} else {
		c = b;
		c->next = MERGE(a,b->next);
	}

	return c;
}

node* MERGE_SORT(node* head){
	if(head == NULL || head->next == NULL) return head;

	node*mid = MID(head);
	node* b = MERGE_SORT(mid->next);
	mid->next = NULL;
	node* a = MERGE_SORT(head);

	return MERGE(a,b);
}


void CIRCULAR_LINKED_LIST(node* head){
	node* temp_out = head;
	node* temp_in = head;
	while(temp_out!=NULL){

		temp_in = temp_out->next;
		while (temp_in != NULL) {
			if(temp_out->data == (temp_in->next)->data) { temp_in->next = NULL; return;}
			temp_in = temp_in->next;
		}

		temp_out = temp_out->next;
	}
}

int main() {
    node* head= NULL;
    cin>>head;
    print(head);
	CIRCULAR_LINKED_LIST(head);
	print(head);


    return 0;
}
