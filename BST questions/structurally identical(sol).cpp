#include<iostream>
using namespace std;
 class node{
    public:
    int data;
    node * left;
    node* right;
    node(int d)
    {
      data=d;
      left=NULL;
      right=NULL;

    }

  };
  node * buildtree(node* root, bool ilc)
  {
			int cdata;
            cin>>cdata;
			node * child= new node(cdata);

			// left
			string hlc;
            cin>>hlc;

			if (hlc=="true") {
				child->left = buildtree(child,true);
			}

			// right
            string hrc;
            cin>>hrc;

			if (hrc=="true") {
				child->right = buildtree(child,false);
			}

			// return
			return child;
  }
bool checkidentical(node*root1, node*root2)
{ if(root1==NULL && root2==NULL)
  {
  return true;
  }
 if(root1 == NULL || root2 == NULL)
			return false;

if(root1!=NULL && root2!=NULL){
    return checkidentical(root1->left, root2->left) && checkidentical(root1->right, root2->right);
			}
	return false;

}

int main() {
  node * root1=buildtree(NULL,false);
  node * root2=buildtree(NULL, false);
  if(checkidentical(root1,root2))
  {
    cout<<"true";
  }
    else
     cout<<"false";



	return 0;
}
