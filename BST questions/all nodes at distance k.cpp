#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(x,n) for(int x = 0; x < n; ++x)

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* createTreeFrom_Pre_In(int pre[], int in[], int s, int e){
    static int index = 0;
    if(s>e) return NULL;
    node* root = new node(pre[index]);

    int i;
    for(i=s; i<=e; i++){
        if(in[i]==pre[index]) break;
    }
    index++;

    root->left = createTreeFrom_Pre_In(pre,in,s,i-1);
    root->right = createTreeFrom_Pre_In(pre,in,i+1,e);

    return root;
}


void printKthLevel(node* root, int k){
    if(root == NULL) return;
    if(k==0) cout<<root->data<<" ";
    printKthLevel(root->left, k-1);
    printKthLevel(root->right,k-1);
}

bool searchInBT(node* root, int key){
    cout<<"in search\n";
    if(root==NULL) return false;
    if(root->data==key) return true;
    bool r1 =  searchInBT(root->left,key) ;
    bool r2 =  searchInBT(root->right,key);
    return r1 || r2;
}

stack<node*> makeStack(node* root,int key){                     // will stack be destroyed??
    stack<node*> s;
    s.push(root);
    if(root==NULL) return s;
    if(root->data==key) return s;
    node* temp = root;

    while(temp->data != key && temp != NULL){
        if(key < temp->data) {
            temp = temp->left;
            s.push(temp);
        }
        else {
            temp = temp->right;
            s.push(temp);
        }
    }

    return s;
}

void printStack(stack<node*>s){
    while(!s.empty()){
        cout << s.top()->data <<"^";
        s.pop();
    }
    cout<<endl;
}

void printAtDistanceK(node* root, int key, int dis){
    //check if node exists
    cout<<"level 1\n";

    if(!searchInBT(root,key)) {
        cout<<0;
        return;
    }
    //cout<<"level 1\n";
    //push nodes in stack? or queue?
    stack<node*> s = makeStack(root,key);

    printStack(s);

    printKthLevel(s.top(),dis);

    for(int i=1; i<dis; i++){
        node* curr = s.top();
        s.pop();
        node* par = s.top();

        if(curr == par->left) {
            printKthLevel(par->right,dis-i);

        }
        else {
            printKthLevel(par->left,dis-i);
        }

    }

    cout<< "-" << s.top()->data;




}


int main(){
    int n; cin>>n;
    int pre[n];
    int in[n];
    loop(i,n){
        cin>>pre[i];
    }
    loop(i,n){
        cin>>in[i];
    }
    node* root = createTreeFrom_Pre_In(pre,in,0,n-1);

    int t; cin>>t;
    loop(i,t){
        int key;
        int distance;
        cin>>key>>distance;
        cout<<"level 2\n";

        printAtDistanceK(root,key,distance);

        cout<<endl;

    }

}
