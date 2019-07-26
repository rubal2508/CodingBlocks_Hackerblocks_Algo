#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(x,n) for(int x = 0; x < n; ++x)
//#define loop(x,i,n) for(int x = i; x < n; ++x)

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

node* insertInBST(node* root, int d){
    if(root==NULL) return new node(d);
    if(d<root->data) root->left = insertInBST(root->left,d);
    else root->right = insertInBST(root->right,d);
    return root;
}

node* buildBSTFromArray(int arr[], int n){
    node* root = NULL;
    loop(i,n){
        root = insertInBST(root,arr[i]);
    }
    return root;
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

        // node* replace = root->right;
        // while(replace->left != NULL) replace = replace->left;
        // root->data = replace->data;
        // root->right = deleteInBST(root->right,replace->data);

        node* replace = root->left;
        while(replace->right != NULL) replace = replace->right;
        root->data = replace->data;
        root->left = deleteInBST(root->left,replace->data);


        return root;
    }

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



int main(){
    int t; cin>>t;
    for(int j=0; j<t; j++){

        int n; cin>>n;
        int a1[n];
        for(int i=0; i<n; i++){
            cin>>a1[i];
        }
        int m; cin>>m;
        int a2[m];
        for(int i=0; i<m; i++){
            cin>>a2[i];
        }
        node* root  = buildBSTFromArray(a1,n);
        for(int i=0; i<m; i++){
            root = deleteInBST(root, a2[i]);
        }

        printPre(root);
        cout<<endl;
        printIn(root);
        cout<<endl;
        printPost(root);
        cout<<endl;

    }
}
