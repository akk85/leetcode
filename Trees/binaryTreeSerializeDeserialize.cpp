#include "../common.hpp"
#include <sstream>

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() : val(0), left(nullptr), right(nullptr) {};
    Node(int NodeValue) : val(NodeValue), left(nullptr), right(nullptr) {};
    Node(int NodeValue, Node* leftNode, Node* rightNode) : val(NodeValue), left(leftNode), right(rightNode) {};

    ~Node() {
        val = 0;
        delete left;
        delete right;
    }
};
/*
Implement an algorithm to serialize and deserialize a binary tree.

Serialization is the process of converting an in-memory structure into a sequence of bits 
so that it can be stored or sent across a network to be reconstructed later in another computer environment.

You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure. 
There is no additional restriction on how your serialization/deserialization algorithm should work.

Constraints:

0 <= The number of nodes in the tree <= 1000.
-1000 <= Node.val <= 1000


Thought Process:
    Serialize
        1. idea is if a root is a nullptr we turn it into a "-1001" otherwise if its an actual node we turn it into a string "nodevalue"
            * for null nodes we give them the value -1001 because as per the problem statememt we know no node will have this value
        2. do a bfs starting from the root maintaining a global string variable append the respective string represntation of this nodes value and return it after processing all levels 
        3. by doing a bfs our string will read level by level left to right

    Deserialize
        1. the first value from the serialized data will be our root. it it happens our root is value -1001 we immedialtely return nullptr
        2. iterating over the values of the string, use a queue to process the nodes
        3. when we pop a node from the queue, we grab immediate next two values from the list after this node, make them left and right child
            to this node and push them to queue to process their child as well in the same fashion
        4. continue doing so until our pointer reached end of our data string and here we return the root Node

            1
        2       3
            4       5

        data = "1,2,3,N,N,4,N,N,5,N,N,"
        queue = 
        node = 

        data = "1,2,3,N,N,4,5,N,N,N,N,"
                                      i
        root = 1
        
        queue =  
        node = 5
            1
        2      3
            4    5

*/
class Codec {
public:
    string serialize(Node* root){
        if (!root) return "-1001";

        string data;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* node = q.front(); q.pop();
            if (node){
                data += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                data += "-1001,";
            }
        }
        return data;
    }

    Node* deserialize(string data){
        vector<string> vec;
        stringstream stream(data);
        string nodeValue;


        // get string data into a vector for ease of iteration
        while (getline(stream, nodeValue, ',')){
            vec.push_back(nodeValue);
        }
        int firstNode = stoi(vec[0]);
        if (firstNode == -1001){
            return nullptr;
        }
        Node* root = new Node((firstNode));

        int n = vec.size();

        int r = 1;

        // vec = [2,3,-1001,N,4,5,N,N,N,N]
        //                        r 
        // queue =  4 5
        // node  = 3
        //
        //        1
        //.    2.   3
        //        4.  5
        //

        queue<Node*> q;
        q.push(root);

        while (r < n){
            Node* node = q.front(); q.pop();

            if (vec[r] != "-1001"){
                node->left = new Node(stoi(vec[r]));
                q.push(node->left);
            }
            r++;
            if (vec[r] != "-1001"){
                node->right = new Node(stoi(vec[r]));
                q.push(node->right);
            }
            r++;
        }

        return root;
    }

    // level by level(left -> right)
    void topDownPrint(Node* root){
        if (!root){
            return;
        }
        queue<Node* > q;
        q.push(root);

        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            cout << curr->val << " ";
            if (curr->left){
                q.push(curr->left);
            }
            if (curr->right){
                q.push(curr->right);
            }
        }
        cout << endl;
    }
};

int main(){
    Codec codec;
    Node* root = new Node(1, new Node(2), new Node(3, new Node(4), new Node(5)));
    
    codec.topDownPrint(root);

    string data = codec.serialize(root);
    Node* newRoot = codec.deserialize(data);

    codec.topDownPrint(newRoot);

    delete root;
}