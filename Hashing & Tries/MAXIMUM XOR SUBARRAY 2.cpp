#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x=0; x<n; ++x);

class node{
public:
    node* left;
    node* right;

    node(){
        left=NULL;
        right=NULL;
    }
};

class Trie{
    node* root;
public:
    Trie(){
        root = new node();
    }

    void insert(int a){
        node* curr = root;
        for(int i=31; i>=0; i--){
            bool b = a & (1<<i);
            if(b==1){
                if(!curr->right) curr->right = new node();
                curr = curr->right;
            } else{
                if(!curr->left) curr->left = new node();
                curr = curr->left;
            }
        }
    }

     int findMaxXorPair(int a){
         if(root==NULL) return 0;
         node* curr = root;
         int curr_xor = 0;

         for(int i=31; i>=0 && curr != NULL ; i--){
             bool b = a & (1<<i);
             if(b==1){
                 if(!curr->left) {
                     curr = curr->right;
                //     curr_xor += (1<<i);

                 } else {
                    curr = curr->left;
                    curr_xor += (1<<i);
                 }

             } else{
                 if(!curr->right){
                     curr = curr->left;
                 } else{
                     curr = curr->right;
                     curr_xor += (1<<i);
                 }

             }
         }
         return curr_xor;


     }
};


int maxXORsubarr(int arr[],int n){
    Trie t;
    int pre_xor = 0;
    int max_xor  = INT_MIN;
    t.insert(0);
    for(int i=0; i<n; i++){
        pre_xor = pre_xor ^ arr[i];
        t.insert(pre_xor);
        max_xor = max(max_xor,t.findMaxXorPair(pre_xor));
        cout << t.findMaxXorPair(pre_xor) <<"[\n";
    }

    return max_xor;
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout << maxXORsubarr(arr,n);
}
