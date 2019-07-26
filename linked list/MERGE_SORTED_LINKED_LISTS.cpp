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

void llkreverse(node* &head, int factor){

}

node* MERGE_SORTED_LINKED_LISTS(node* head1, node* head2){
	if(head1 == NULL && head2 == NULL) return NULL;
	node* head3 = NULL ;
	
	while (head1 != NULL && head2 != NULL) {
		if ((head1->data)<=(head2->data)) {
			insertAtTail(head3,head1->data);
			head1 = head1->next;
		} else {
			insertAtTail(head3,head2->data);
			head2 = head2->next;
		}
	}

	if (head2 != NULL) {
		while(head2!=NULL){
			insertAtTail(head3,head2->data);
			head2 = head2->next;
		}
	}

	else if (head1 != NULL) {
		while(head1!=NULL){
			insertAtTail(head3,head1->data);
			head1 = head1->next;
		}
	}

	return head3;

}

int main() {
    int t; cin>>t;

    for (int i = 0; i < t; ++i)
    {
    	int n1; cin>>n1;
    	node* head1;
    	buildList(head1,n1);
    	int n2; cin>>n2;
    	node* head2;
    	buildList(head2,n2);
    	node* head3 = MERGE_SORTED_LINKED_LISTS(head1,head2);
    	print(head3);

    }
    
    return 0;
}







