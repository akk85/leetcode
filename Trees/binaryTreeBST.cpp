#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() 
            : data(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) 
            : data(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* leftNode, TreeNode* rightNode) 
            : data(x), left(leftNode), right(rightNode) {};
    
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class BST{
private:
    TreeNode* root;
public:
    BST() 
        : root(nullptr) {};
    BST(TreeNode* rootNode) 
        : root(rootNode) {};
    ~BST(){
        delete root;
    }

    TreeNode* getRoot() const {
        return root;
    }

};



// root -> left -> right 
vector<int> preOrder(TreeNode* treeRoot) {
    if (!treeRoot){
        return {};
    }
    vector<int> result;
    stack<TreeNode* > s;
    s.push(treeRoot);

    while(!s.empty()){
        TreeNode* curr = s.top(); s.pop();
        result.push_back(curr->data);
        if (curr->right){
            s.push(curr->right);
        }
        if (curr->left){
            s.push(curr->left);
        }
    }
    return result;
}

int TreeSum(TreeNode* TreeRoot){
    if (!TreeRoot){
        return 0;
    }
    int sum {};
    queue<TreeNode* > q;
    q.push(TreeRoot);

    while (!q.empty()){
        TreeNode* curr = q.front(); q.pop();
        sum += curr->data;
        if (curr->left){
            q.push(curr->left);
        }
        if (curr->right){
            q.push(curr->right);
        }
    }

    return sum;
}

    //          40
    //     30        50
    // 25     35  45    60
    // s = []
    // r = [25, 30, 35, 40, 45, 50, 60]

// left -> root -> right (sorted order)
vector<int> inOrder(TreeNode* treeRoot){
    vector<int> result;
    stack<TreeNode* > s;
    TreeNode* curr = treeRoot;
    while (curr || !s.empty()){
        while (curr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top(); s.pop();
        result.push_back(curr->data);
        curr = curr->right;
    }
    return result;
}

// level by level(left -> right)
vector<int> bfs(TreeNode* TreeRoot){
    if (!TreeRoot){
        return {};
    }
    vector<int> result;
    queue<TreeNode* > q;
    q.push(TreeRoot);

    while(!q.empty()){
        TreeNode* curr = q.front(); q.pop();
        result.push_back(curr->data);
        if (curr->left){
            q.push(curr->left);
        }
        if (curr->right){
            q.push(curr->right);
        }
    }
    return result;
}
    //          40
    //     30        50
    // 25     35  45    60

bool isContains(TreeNode* treeRoot, int target){
    if (!treeRoot){
        return false;
    }
    
    TreeNode* curr = treeRoot;
    while (curr){
        if (curr->data == target){
            return true;
        }
        if (target < curr->data){
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return false;
}

int findMin(TreeNode* treeRoot){
    if (!treeRoot){
        return -1;
    }
    TreeNode* curr = treeRoot;
    while(curr->left){
        curr = curr->left;
    }

    return curr->data;
}

int findMax(TreeNode* treeRoot){
    if (!treeRoot){
        return -1;
    }

    TreeNode* curr = treeRoot;

    while (curr->right){
        curr = curr->right;
    }
    return curr->data;
}
    //          40
    //     30        50
    // 25     35  45    60

bool validateBST(TreeNode* treeRoot){
    // do an inorder traversal
    stack<TreeNode* > s;
    vector<int> res;
    TreeNode* curr = treeRoot;
    while(curr || !s.empty()){
        // go as left as possible
        while (curr){
            s.push(curr);
            curr = curr->left;
        }
        // append left most node to result and go to right tree 
        curr = s.top(); s.pop();
        res.push_back(curr->data);
        curr = curr->right;
    }

    for (size_t i = 1; i < res.size(); i++){
        if (res[i-1] >= res[i]){
            return false;
        }
    }
    return true;
}

TreeNode* insertBST(TreeNode* TreeRoot, int val){
    if (!TreeRoot){
        return new TreeNode(val);
    }

    TreeNode* curr = TreeRoot;
    while (true){
        if (val < curr->data){
            if (curr->left == nullptr){
                curr->left = new TreeNode(val);
                break;
            }
            curr = curr->left;
        } else {
            if (curr->right == nullptr){
                curr->right = new TreeNode(val);
                break;
            }
            curr = curr->right;
        }
    }
    return TreeRoot;
}

    //          40
    //     30        50
    // 25     35  45    60

    //k = 0
    // c = 40
    // s = []
int kthSmallest(TreeNode* TreeRoot, int k){
    if (!TreeRoot){
        return -1;
    }
    stack<TreeNode* > s;
    
    TreeNode* curr = TreeRoot;
    while (curr || !s.empty()){
        // go as left as possible to smalles values 
        while (curr){
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top(); s.pop();
        k --;
        if (k == 0){
            return curr->data;
        }
        
        // go right of current node
        curr = curr->right;
    }
    return -1; // if not found 
}
    //          40
    //     30        50
    // 20     35  45    60
    //                55
    // 25 <-> 35
    // c = 35
    // s = []
    // sum = 65
int rangeSumBST(TreeNode* treeRoot, int low, int high){
    if (!treeRoot){
        return 0;
    }
    int sum {};
    stack<TreeNode* > s;
    s.push(treeRoot);

    while(!s.empty()){
        TreeNode* curr = s.top(); s.pop();
        if (curr->data >= low && curr->data <= high){
            sum += curr->data;
        }

        if (curr->right){
            if (curr->data <= high){
                s.push(curr->right);
            }
        }
        if (curr->left){
            if (curr->data >= low){
                s.push(curr->left);
            }
        }
    }

    return sum;
}
    //          40
    //     30        50
    // 20     35  45    60
    //                55
    // 25 <-> 35
int countInRange(TreeNode* TreeRoot, int low, int high){
    if (!TreeRoot){
        return 0;
    }
    int count {};
    stack<TreeNode* > s;
    s.push(TreeRoot);
    while(!s.empty()){
        TreeNode* curr = s.top(); s.pop();
        if (curr->data >= low && curr->data <= high){
            count ++;
        }
        if (curr->right){
            if (curr->data <= high){
                s.push(curr->right);
            }
        }
        if (curr->left){
            if (curr->data >= low){
                s.push(curr->left);
            }
        }
    }
    return count;
}
int maxDepth(TreeNode* TreeRoot){
    if (!TreeRoot){
        return 0;
    }
    int depth {};
    queue<pair<TreeNode* , int>> q;
    q.push({TreeRoot, 1});
    while (!q.empty()){
        pair<TreeNode*, int> currPair = q.front(); q.pop();
        depth = max(depth, currPair.second);
        if (currPair.first->left){
            q.push({currPair.first->left, currPair.second + 1});
        }
        if (currPair.first->right){
            q.push({currPair.first->right, currPair.second + 1});
        }
    }
    return depth;
}

bool isBalanced(TreeNode* TreeRoot);

int diameterOfBinaryTree(TreeNode* root);
TreeNode* deleteNode(TreeNode* root, int key);



//          1
//       2    3
//    4
// 5

// q    = [4]
// size = 2
// curr = 3
// vec  = [ 2, 3]
// res  = [1 , 3]
// Binary Tree Right Side View
vector<int> rightSideView(TreeNode* TreeRoot){
    if (!TreeRoot){
        return {};
    }
    queue<TreeNode* > q;
    vector<int> res; 
    q.push(TreeRoot);
    while (!q.empty()){
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++){
            TreeNode* curr = q.front(); q.pop();

            if (i == levelSize - 1){        // last in the level 
                res.push_back(curr->data);
            }
            if (curr->left){
                q.push(curr->left);
            }
            if (curr->right){
                q.push(curr->right);
            }
        }
    }

    return res;
}

vector<int> leftSideView(TreeNode* TreeRoot){
    if (!TreeRoot){
        return {};
    }
    queue<TreeNode* > q;
    vector<int> res;
    q.push(TreeRoot);
    while (!q.empty()){
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++){
            TreeNode* curr = q.front(); q.pop();

            if (i == 0){                     // front of level 
                res.push_back(curr->data);
            }
            if (curr->left){
                q.push(curr->left);
            }
            if (curr->right){
                q.push(curr->right);
            }
        }
    }

    return res;
}
// Invert Binary Tree
TreeNode* invertTree(TreeNode* TreeRoot){
    if (!TreeRoot){
        return nullptr;
    }

    queue<TreeNode* > q;
    q.push(TreeRoot);

    while (!q.empty()){
        TreeNode* curr = q.front(); q.pop();
        swap(curr->left, curr->right);
        if (curr->left){
            q.push(curr->left);
        }
        if (curr->right){
            q.push(curr->right);
        }
    }

    return TreeRoot;
}
// Same Tree
bool isSameTree(TreeNode* root1, TreeNode* root2){
    stack<pair<TreeNode*, TreeNode* >> s;
    s.push({root1, root2});
    while (!s.empty()){
        pair<TreeNode* , TreeNode* > currPair = s.top(); s.pop();   

        if (currPair.first == nullptr && currPair.second == nullptr){
            continue;
        }
        if (currPair.first == nullptr || currPair.second == nullptr || currPair.first->data != currPair.second->data){
            return false;
        }

        s.push({currPair.first->left,  currPair.second->left}); 
        s.push({currPair.first->right, currPair.second->right});
    }
    return true;

}

int sumRootToNode(TreeNode* treeRoot, int node);
// Symmetric Tree
// Sum Root to Leaf Numbers
// Lowest Common Ancestor of a Binary Tree
// Convert Sorted Array to BST
    //          40
    //     30        50
    // 20     35  45    60
    //                55 
    
int main(){
    TreeNode* child3 = new TreeNode(20);
    TreeNode* child4 = new TreeNode(35);  
    TreeNode* child5 = new TreeNode(45);
    TreeNode* child6 = new TreeNode(60);
    TreeNode* child1 = new TreeNode(30, child3, child4);
    TreeNode* child2 = new TreeNode(50, child5, child6);
    TreeNode* parent = new TreeNode(40, child1, child2);

    BST tree(parent);
    TreeNode* root = tree.getRoot();

    vector<int> bfsVec = bfs(root);
    cout << "BFS: " ;
    for (const int& val : bfsVec){
        cout << val << " ";
    }
    cout << endl;

    vector<int> preOrderVec = preOrder(root);
    cout << "preOrder: " ;
    for (const int& val : preOrderVec){
        cout << val << " ";
    }
    cout << endl;

    vector<int> inOrderVec = inOrder(root);
    cout << "Inorder: " ;
    for (const int& val : inOrderVec){
        cout << val << " ";
    }
    cout << endl;

    cout << "Sum of Tree is: " << TreeSum(root) << endl;

    int target = 45;
    cout << "Tree has the node " << target << ": "<< boolalpha << isContains(root, target) << endl;

    cout << "Minimum in tree is: " << findMin(root) << endl;

    cout << "Minimum in tree is: " << findMax(root) << endl;
 
    cout << "Tree is a BST: " << boolalpha << validateBST(root) << endl;

    TreeNode* root2 = insertBST(root, 55);
    vector<int> inorder2 = inOrder(root2);
    for (const int& val : inorder2){
        cout << val << " ";
    }
    cout << endl;

    cout << "4th smallest in tree is: " << kthSmallest(root, 4) << endl;;

    cout << "Sum of nodes in this range is: " << rangeSumBST(root, 25, 35) << endl;

    cout << "Number of nodes in this range is: " << countInRange(root, 25, 55) << endl;

    cout << "Max Depth: " << maxDepth(root) << endl;

    cout << "Right Side View of tree: ";
    vector<int> rightSide = rightSideView(root);
    for (const int& val : rightSide){
        cout << val  << " ";
    }
    cout << endl;

    cout << "Left Side View of tree: ";
    vector<int> leftSide = leftSideView(root);
    for (const int& val : leftSide){
        cout << val  << " ";
    }
    cout << endl;

    TreeNode* inverted = invertTree(root);
    vector<int> levelBfs = bfs(inverted);
    cout << "Level BFS of Inverted Tree: " ;
    for (const int& val : levelBfs){
        cout << val << " ";
    }
    cout << endl;  

    cout << "Is Same tree: " << boolalpha << isSameTree(root, root) << endl;

}