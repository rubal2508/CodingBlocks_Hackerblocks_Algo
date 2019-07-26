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
         if(root==NULL) {
             return 0;
             cout<<"null 1";
         }
         node* curr = root;
         int curr_xor = 0;

         for(int i=31; i>=0 && curr != NULL ; i--){
             bool b = a & (1<<i);
             if(b==1){
                 if(!curr->left) {
                     curr = curr->right;

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


int maxXORsubarr(int arr[],int s,int e){
    if(s>e) {
       return 0;
   }

    Trie t;
    int pre_xor = 0;
    int max_xor  = 0;   //int min
    int i;
    t.insert(0);
    for(i=s; i<=e; i++){
        pre_xor = pre_xor ^ arr[i];
        t.insert(pre_xor);
        max_xor = max(max_xor,t.findMaxXorPair(pre_xor));
    }

    return max_xor;
}

int trie_interview(int arr[], int n){
    int max = 0;
    for(int i=0; i<=n; i++){
        int curr_max;
        curr_max = maxXORsubarr(arr,0,i-1) + maxXORsubarr(arr,i,n-1);
    //    cout<<0<<":"<<i-1<<" - " << maxXORsubarr(arr,0,i-1) << " = " <<i<<":"<<n-1<<" - " << maxXORsubarr(arr,i,n-1) << endl; //

        if(curr_max>max) max = curr_max;
    }
    return max;
}


int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout << trie_interview(arr,n);
    //cout << maxXORsubarr(arr,0,n);
}
