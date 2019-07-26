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

bool isBST(node *root,int minV = INT_MIN,int maxV = INT_MAX){
    if(root==NULL) return true;
    if(root->data >= minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)) return true;
    return false;
}

int size(node* root){
    if (root==NULL) return 0;

    int l = size(root->left);
    int r = size(root->right);
    return l+r+1;
}

node* largestBST(node* root){
    if(isBST(root)) return root;
    else if (isBST(root->left) && !isBST(root->right)) return root->left;
    else if (!isBST(root->left) && isBST(root->right)) return root->right;
    else {
        if(size(root->left) > size(root->right)) return root->left;
        else return root->right;
    }
}


int main(){
    int n; cin>>n;
    int pre[n];
    loop(i,n){
        cin>>pre[i];
    }

    int in[n];
    loop(i,n){
        cin>>in[i];
    }
    node* root = createTreeFrom_Pre_In(pre,in,0,n-1);
    node* bst = largestBST(root);

    cout << size(bst);


}
