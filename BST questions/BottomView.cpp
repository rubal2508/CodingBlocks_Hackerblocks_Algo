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

void printLevelOrder(node* root){
    if(root == NULL) return;
    queue <node*> que;
    que.push(root);
    while(!que.empty()){
        cout << que.front()->data <<" ";
        if(que.front()->left != NULL) que.push(que.front()->left);
        if(que.front()->right != NULL) que.push(que.front()->right);
        que.pop();
    }
}

node* buildTreeLevelWise(){
    int d; cin>>d;

	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		node*f = q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			f->left = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}



int main(){

    // int arr[] = {0,1,2,3,4,5,6,7,8,9};
    // node* root = buildBST_array(arr,0,9);
    // printLevelOrder(root);

    node* root = buildTreeLevelWise();


}
