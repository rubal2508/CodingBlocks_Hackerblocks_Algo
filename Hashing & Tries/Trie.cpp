#include <bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char,node*>
#define loop(x,n) for(int x=0; x<n; ++x);

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

class Trie{
    node* root;
public:
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
};

int main(){
    char word[10][100] = {"apple","ape","coder","coding blocks","no"};
    Trie t;
    loop(i,5){
        t.addWord(word[i]);
    }
    char searchWord[100];
    cin.getline(searchWord,100);

    if(t.search(searchWord)){
        std::cout << "found" << '\n';
    }
    else std::cout << "not found" << '\n';
}
