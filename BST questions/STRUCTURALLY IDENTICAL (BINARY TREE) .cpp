#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(x,i,n) for(int x = i; x < n; ++x)
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
class Pair{
public:
    int height;
    int diameter;
};
class pair2{
public:
    int height;
    bool balanced;
};
class linkedlist{
public:
    node* head;
    node* tail;
};

node* buildTree(){
    int d; cin>>d;
    if(d==-1) return NULL;
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printPre(node* root){              // 3 4 6 5 1
    if(root == NULL) return;
    cout << root->data <<" ";
    printPre(root->left);
    printPre(root->right);
}
void printIn(node* root){               // 4 6 3 1 5
    if(root == NULL) return;
    printIn(root->left);
    cout << root->data <<" ";
    printIn(root->right);
}
void printPost(node* root){             //6 4 1 5 3
    if(root == NULL) return;
    printPost(root->left);
    printPost(root->right);
    cout << root->data <<" ";
}
int height(node* root){
    if(root == NULL) return -1;
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1,h2)+1;
}
void printKthLevel(node* root, int k){
    if(root == NULL) return;
    if(k==0) cout<<root->data<<" ";
    printKthLevel(root->left, k-1);
    printKthLevel(root->right,k-1);
}
void printAllLevels(node* root){
    int H = height(root);
    for(int i = 0; i <= H; i++){
        printKthLevel(root,i);
        cout <<endl;
    }
}
void bfs(node* root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
        if (f==NULL) {
            cout<<endl;
            q.pop();
            if(!q.empty()) q.push(NULL);

        } else {
            cout << f->data <<" ";
            q.pop();
            if(f->left != NULL) q.push(f->left);
            if(f->right!= NULL) q.push(f->right);
        }

    }
}
int count(node* root){
    if(root == NULL) return 0;
    return 1+count(root->left)+count(root->right);
}
int sumoftree(node* root){
    if(root == NULL){ return 0;}
    return root->data + sumoftree(root->left) + sumoftree(root->right);
}
Pair fastdiameter(node* root){
    Pair p;
    if (root == NULL) {
        p.height = -1;
        p.diameter = 0;
        return p;
    }
    Pair ld = fastdiameter(root->left);
    Pair rd = fastdiameter(root->right);

    p.height = max(ld.height,rd.height)+1;
    p.diameter = max(ld.height+rd.height+2, max(ld.diameter, rd.diameter));
    return p;
}
int replaceSum(node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return root->data;
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);
    int temp = root->data;
    root->data = leftSum+rightSum;
    return temp+root->data;
}
pair2 isHeightBalance(node* root){
    pair2 p;
    if(root==NULL) {
        p.height = -1;
        p.balanced = true;
        return p;
    }
    pair2 left = isHeightBalance(root->left);
    pair2 right = isHeightBalance(root->right);
    p.height = max(left.height, right.height)+1;
    p.balanced = abs(left.height - right.height)<=1 && left.balanced && right.balanced;
    return p;
}
node* buildTreeFromArray(int arr[], int s, int e){
    if(s>e) return NULL;
    int m = (s+e)/2;
    node* root = new node(arr[m]);
    root->left = buildTreeFromArray(arr,s,m-1);
    root->right = buildTreeFromArray(arr,m+1,e);
    return root;
}
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


node* insertInBST(node* root, int d){
    if(root==NULL) return new node(d);
    if(d<root->data) root->left = insertInBST(root->left,d);
    else root->right = insertInBST(root->right,d);
    return root;
}
node* buildBST(){
    int d; cin>>d;
    node* root = NULL;
    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}
bool searchInBST(node* root, int key){
    if(root==NULL) return false;
    if(root->data==key) return true;
    if(key<root->data) return searchInBST(root->left,key);
    else return searchInBST(root->right,key);
}
bool isBST(node *root,int minV = INT_MIN,int maxV = INT_MAX){
    if(root==NULL) return true;
    if(root->data >= minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)) return true;
    return false;
}
node* deleteInBST(node* root, int data){
    if(root==NULL) return root;
    if(data < root->data) {root->left = deleteInBST(root->left,data); return root;}
    if(data > root->data) {root->right = deleteInBST(root->right,data); return root;}
    if(data == root->data){
        //3 Cases
        if(root->left==NULL && root->right==NULL) {delete root; return NULL;}
        if(root->left!=NULL && root->right==NULL) {node* temp = root->left; delete root; return temp;}
        if(root->left==NULL && root->right!=NULL) {node* temp = root->right; delete root; return temp;}

        node* replace = root->right;
        while(replace->left != NULL) replace = replace->left;
        root->data = replace->data;
        root->right = deleteInBST(root->right,replace->data);
        return root;
    }

}


linkedlist flattenBST(node* root){
    linkedlist l;
    if(root==NULL) {l.head=l.tail=NULL; return l;}
    if(root->left==NULL && root->right==NULL) {
        l.head=root;
        l.tail=root;
        return l;
    }
    if(root->left != NULL && root->right==NULL){
        linkedlist lf = flattenBST(root->left);
        lf.tail->right = root;
        l.head = lf.head;
        l.tail = root;
        return l;
    }
    if(root->left == NULL && root->right != NULL){
        linkedlist rt = flattenBST(root->right);
        root->right = rt.head;
        l.head = root;
        l.tail = rt.tail;
        return l;
    }
    else {
        linkedlist l1 = flattenBST(root->left);
        linkedlist l2 = flattenBST(root->right);
        l1.tail->right = root;
        root->right = l2.head;
        l.head = l1.head;
        l.tail = l2.tail;
        return l;
    }
}


node* buildBST_truefalse(){
    int d; cin>>d;
    node* root = new node(d);

    string left; cin>>left;
    if(left == "true") root->left = buildBST_truefalse();

    string right; cin>>right;
    if(right == "true") root->right = buildBST_truefalse();

    return root;
}

bool checkidentical (node* root1, node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;

    return checkidentical(root1->left, root2->left) && checkidentical(root1->right, root2->right);
}



int main(){

    node* root1 = buildBST_truefalse();
    node* root2 = buildBST_truefalse();

    if(checkidentical(root1, root2)) cout<<"true";
    else cout<<"false";



}
