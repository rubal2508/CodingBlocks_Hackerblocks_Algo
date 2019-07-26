#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(ll x=0; x<n; ++x)
#define hashmap map<char,node*>
#define ll long long

class node{
public:
    char data;
    hashmap h;
    bool isTerminal;

    node(char d){
        data = d;
        isTerminal = false;

    }
};

void printVector(vector<char> v, vector<char> v1){
    loop(i,v1.size()){
        cout<<v1[i];
    }
    loop(i,v.size()){
        cout<<v[i];
    }
    cout<<endl;
}


class Trie{
public:
    node* root;

    Trie(){
        root = new node('\0');
    }

    void addWord(char* word){
        node* temp = root;
        for(int i=0; word[i] != '\0'; i++){
            char ch = word[i];
            if(temp->h.count(ch)==0){
                node* child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            }
            else temp = temp->h[ch];
        }
        temp->isTerminal = true;
    }

    bool search(char* word){
        node* temp = root;
        for(int i=0; word[i] != '\0'; i++){
            char ch = word[i];
            if(temp->h.count(ch)){
                temp = temp->h[ch];
            }
            else return false;
        }

        return temp->isTerminal;


    }

    void printAllNodes(node* temp, vector<char> v, vector<char> v1){

        if(temp->h.empty()) {
            v.push_back(temp->data);
            printVector(v,v1);                                 //
            return;
        }

        if(temp->isTerminal){
            v.push_back(temp->data);
            printVector(v,v1);                                 //
            for(auto it:temp->h){
        //        v.push_back(it.first);
                printAllNodes(it.second,v,v1);
            }
            return;
        }

        if(temp->data != '\0')  v.push_back(temp->data);
        for(auto it:temp->h){
        //    v.push_back(it.first);
            printAllNodes(it.second,v,v1);
        }
        return;

    }


    void printPrefix(char* word){
        //no suggestion
        vector<char> v1;
        vector<char> v;

        node* temp = root;

        if(temp->h.count(word[0])==0 ) {
            cout<<"No suggestion\n";
            //addWord(word);
            return;
        }

        int i=0;
        while(temp->h.count(word[i]) && word[i] != '\0') {
            char ch = word[i] ;
            if(temp->data != '\0')  v1.push_back(temp->data);
            temp = temp->h[ch];
            i++;
        }
        if(word[i] != '\0') {
            cout<<"No suggestion\n";
            addWord(word);
            return;
        }

        printAllNodes(temp,v,v1);

    }
};

int main(){
    // char word[10][100] = {"apple","ape","coder","coding blocks","no"};
    Trie t;
    // loop(i,5){
    //     t.addWord(word[i]);
    // }
    // char searchWord[100];
    // cin.getline(searchWord,100);
    //
    // if(t.search(searchWord)){
    //     std::cout << "found" << '\n';
    // }
    // else std::cout << "not found" << '\n';


    int n; cin>>n;
    loop(i,n){
        char s[100];
    //  cin.getline(s,100);
        cin>>s;
        t.addWord(s);
    }

    // vector<char> v;
    // vector<char> v1;
    // t.printAllNodes(t.root,v,v1);
    // return 0;


    int q; cin>>q;
    loop(i,q){
        char s[100];
        // cin.getline(s,100);
        cin>>s;
        t.printPrefix(s);
    }




}
