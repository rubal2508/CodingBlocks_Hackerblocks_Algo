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
node* buildBST_array(int arr[], int s, int e){
    while(s<=e){
        int mid = (s+e)/2;
        node* root = new node(arr[mid]);
        root->left = buildBST_array(arr,s,mid-1);
        root->right = buildBST_array(arr,mid+1,e);
        return root;
    }

    return NULL;

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

void replaceWithGreater(node* root){
    static int sum = 0;
    if(root == NULL) return;
    replaceWithGreater(root->right);
    root->data += sum;
    sum = root->data;
    replaceWithGreater(root->left);
}



int main(){
    int n; cin>>n;
    int arr[n];
    loop(i,n){
        cin>>arr[i];
    }
    node* root = buildBSTFromArray(arr,n);
    //node* root = buildBST_array(arr,0,n-1);
    replaceWithGreater(root);
    printPre(root);

}
