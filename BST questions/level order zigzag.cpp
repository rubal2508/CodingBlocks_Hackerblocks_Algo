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

void printKthLevelreverse(node* root, int k){
    if(root == NULL) return;
    if(k==0) cout<<root->data<<" ";
    printKthLevel(root->right,k-1);
    printKthLevel(root->left, k-1);
}





void printZigZag(node* root){
    int H = height(root);
    for(int i = 0; i <= H; i++){
        //cout <<endl;
        printKthLevel(root,i);
        i++;
        printKthLevelreverse(root,i);


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


int main(){
    node* root = buildBST_truefalse();
    printZigZag(root);
}
