#include "../common.hpp"

/*
A prefix tree (also known as a trie) is a tree data structure used to efficiently store and 
retrieve keys in a set of strings. 

Some applications of this data structure include auto-complete and spell checker systems.

Implement the PrefixTree class:

PrefixTree() Initializes the prefix tree object.
void insert(String word) Inserts the string word into the prefix tree.

boolean search(String word) 
Returns true if the string word is in the prefix tree (i.e., was inserted before), and false otherwise.

boolean startsWith(String prefix) 
Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Thought ptocess:
    map each char to a map of it's children
*/

class Node{
public:
    unordered_map<char, Node*> children;
    bool isEnd = false;
};
class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for (const char c : word){
            if (!curr->children.contains(c)){
                Node* cNode = new Node();
                curr->children[c] = cNode;
            }
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (const char c : word){
            if (!curr->children.contains(c)){
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (const char c : prefix){
            if(!curr->children.contains(c)){
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};

int main(){
    PrefixTree trie;

    trie.insert("apple");
    cout << boolalpha << trie.search("apple") << endl;;   // true

    cout << boolalpha << trie.search("app") << endl;     // false 
    cout << boolalpha << trie.startsWith("app") << endl; // true 

    trie.insert("app");
    cout << boolalpha << trie.search("app") << endl;     // true 

}