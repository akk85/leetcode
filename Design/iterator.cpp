#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x){
        val   = x;
        left  = nullptr;
        right = nullptr;
    }
    TreeNode(int x, TreeNode* leftNode, TreeNode* rightNode){
        val   = x;
        left  = leftNode;
        right = rightNode;
    }

};

void getValues(TreeNode* root){
    stack<TreeNode* > s;
    s.push(root);

    while (!s.empty()){
        TreeNode* current = s.top(); s.pop();
        cout << current->val << " ";
        if (current->right){
            s.push(current->right);
        }
        if (current->left){
            s.push(current->left);
        }
    }
    cout << endl;
}

class BSTIterator{
public:
    /*
    add all small values i.e all left children of the root to a stack
    the smalles will end up being at the top of the stack
    */
    stack<TreeNode* > s;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    void findMinMax(TreeNode* root){
        if (!root){
            return;
        }

        queue<TreeNode* > q;
        q.push(root);

        while (!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            minVal = min(minVal, curr->val);
            maxVal = max(maxVal, curr->val);
            if (curr->left){
                q.push(curr->left);
            }
            if (curr->right){
                q.push(curr->right);
            }
        }
    }

    BSTIterator(TreeNode* root){
        findMinMax(root);
        TreeNode* curr = root;
        while (curr){
            s.push(curr);
            curr = curr->left;
        }
    }
    /*
    Moves the pointer to the right, then returns the number at the pointer.
    */
    int next(){
        if (!hasNext()){
            return -1; 
        }
        TreeNode* curr = s.top(); 
        s.pop();

        TreeNode* node = curr->right;
        while(node){
            s.push(node);
            node = node->left;
        }
       return curr->val; 
    }

    bool hasNext(){
        return (!s.empty());
    }

    int begin(){
        return minVal;
    }

    int end(){
        return maxVal;
    }


};

int main(){
    TreeNode* node3  = new TreeNode(3);
    TreeNode* node9  = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20);
    TreeNode* node15 = new TreeNode(15, node9, node20);
    TreeNode* root   = new TreeNode(7, node3, node15);
    
    getValues(root);

    BSTIterator* obj = new BSTIterator(root);

    cout << obj->next() << " "; // return 3
    cout << obj->next() << " "; // return 7
    cout << boolalpha << obj->hasNext() << " "; // return True
    cout << obj->next() << " ";    // return 9
    cout << boolalpha <<  obj->hasNext() << " "; // return True
    cout << obj->next() << " ";    // return 15
    cout << boolalpha << obj->hasNext() << " "; // return True
    cout << obj->next() << " ";    // return 20
    cout << boolalpha << obj->hasNext() << " "; // return False

    cout << obj->begin() << " ";
    cout << obj->end();

    cout << endl;
    return 0;
}


