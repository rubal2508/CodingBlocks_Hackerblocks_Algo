#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define loop(x,n) for(int x=0; x<n; ++x)

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right= NULL;
    }
};

void printPre(node* root){
    if(root==NULL) return;
    cout<<root->data <<" ";
    printPre(root->left);
    printPre(root->right);
}

node* insertInBST(node* root, int d){
    if(root==NULL) return new node(d);
    if(d<root->data) root->left = insertInBST(root->left,d);
    else root->right = insertInBST(root->right,d);
    return root;
}
node* buildBST(int arr[], int n){
    node* root = NULL;
    loop(i,n){
        root = insertInBST(root,arr[i]);

    }
    return root;
}

void printinrange(node* root, int k1, int k2){
    if(root == NULL) return;
    printinrange(root->left, k1, k2);
    if(root->data>=k1 && root->data<=k2) cout << root->data <<" ";
    printinrange(root->right, k1, k2);

}

int main(){
    int t; cin>>t;

    loop(j,t){
        int n; cin>>n;
        int arr[n];
        loop(i,n){
            cin>>arr[i];
        }
        int k1,k2;
        cin>>k1>>k2;
        node* root = buildBST(arr,n);
        cout<< "# Preorder : ";
        printPre(root);
        cout <<endl <<"# Nodes within range are : ";
        printinrange(root,k1,k2);

    }




}
