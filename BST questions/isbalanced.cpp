#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x=0; x<n; ++x)

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
    bool balanced;
};


node* buildBST_truefalse(){
    int d; cin>>d;
    node* root = new node(d);

    string left; cin>>left;
    if(left == "true") root->left = buildBST_truefalse();

    string right; cin>>right;
    if(right == "true") root->right = buildBST_truefalse();

    return root;
}

Pair isBalanced(node* root){
    Pair p;

    if(root == NULL) {
        p.height = -1;
        p.balanced = true;
        return p;
    }

    Pair leftp = isBalanced(root->left);
    Pair rightp = isBalanced(root->right);

    p.height = max(leftp.height, rightp.height)+1;
    p.balanced = leftp.balanced && rightp.balanced && abs(leftp.height - rightp.height)<=1;

    return p;
}

int main(){

    node* root = buildBST_truefalse();

    Pair p = isBalanced(root);

    if(p.balanced == true) cout <<"true";
    else cout <<"false";


}
