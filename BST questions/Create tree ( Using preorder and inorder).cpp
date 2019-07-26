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

void print(node*root)
{
  if(root==NULL){
    return;
  }
  if(root->left)
    cout<<root->left->data;
  else
    cout<<"END";

  cout<<" => "<<root->data<<" <= ";

  if(root->right)
    cout<<root->right->data<<endl;
  else
    cout<<"END"<<endl;
  print(root->left);
  print(root->right);
}



int main(){
    int n; cin>>n;
    int pre[n];
    loop(i,n){
        cin>>pre[i];
    }
    cin>>n;
    int in[n];
    loop(i,n){
        cin>>in[i];
    }
    node* root = createTreeFrom_Pre_In(pre,in,0,n-1);
    print(root);
}
