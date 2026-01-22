#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
class Node{
public:
    int data;
    vector<Node*> children;
    Node(int x){
        data = x;
    }
    ~Node(){
        for (Node* child : children){
            delete child;
        }
    }
};

class Tree{
private:
    Node* root;
public:
    Tree(){
        root = nullptr;
    }

    ~Tree(){
        delete root;
    }

    // setRoot Node
    void setRoot(Node* node) {
        root = node;
    }

    Node* getRoot() const {
        return root;
    }

    int getNodes() const {
        if (!root){
            return 0;
        }
        int count {};
        queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()){
            Node* current = queue.front();
            queue.pop();
            count ++;
            for (Node* children : current->children){
                queue.push(children);
            }

        }
        return count;
    }

    int getLeafNodes() const{
        if (!root){
            return 0;
        }
        int count {};
        stack<Node* > stack;
        stack.push(root);

        while (!stack.empty()){
            Node* current = stack.top();
            stack.pop();

            if ((current->children).empty()){
                count ++;
            }

            for (Node* children : current->children){
                stack.push(children);
            }
        }
        return count;
    }

    vector<int > bfs() const {
        if (!root){
            return {};
        }
        queue<Node* > queue;
        queue.push(root);

        vector<int> result;

        while (!queue.empty()){
            Node* current = queue.front();
            queue.pop();
            result.push_back(current->data);
            for (Node* children : current->children){
                queue.push(children);
            }
        }

        return result;
    }

    vector<int> dfs() const {
        if (!root){
            return {};
        }
        stack<Node* > stack;
        stack.push(root);
        
        vector<int> result;
        while(!stack.empty()){
            Node* current = stack.top();
            stack.pop();
            result.push_back(current->data);
            // push in reverse for a preorder traversal
            for (auto it = current->children.rbegin(); it != current->children.rend(); it++){
                stack.push(*it);
            }
        }

        return result;
    }

    bool hasPath(Node* src, Node* dst) const {
        stack<Node* > stack;
        stack.push(src);
        while (!stack.empty()){
            Node* current = stack.top();
            stack.pop();
            if (current == dst){
                return true;
            }
            for (Node* children : current->children){
                stack.push(children);
            }
        }
        return false;
    }

    int height() const {
        if (!root){
            return 0;
        }
        int maxLevel {};
        queue<pair<Node* , int>> queue;
        queue.push({root, 0});
        while (!queue.empty()){
            pair<Node*, int> currentPair = queue.front();
            Node* current = currentPair.first;
            int currentLevel  = currentPair.second;
            maxLevel = max(maxLevel , currentLevel);
            queue.pop();
            for (Node* children : current->children){
                queue.push({children , currentLevel + 1});
            }
        }
        return maxLevel;
    }

    int longestPath() const {
        if (!root){
            return 0;
        }
        int count {};
        stack<pair<Node* , int>> stack;

        stack.push({root, count + 1});
        while (!stack.empty()){
            pair<Node* , int> currentPair = stack.top();
            stack.pop();
            Node* current    = currentPair.first;
            int currentCount = currentPair.second;
            count = max(count , currentCount);
            for (Node* children : current->children){
                stack.push({children, currentCount + 1});
            }
        }

        return count;
    }

    int getSum() const {
        if (!root){
            return 0;
        }
        int sum {};
        queue<Node* > queue;
        queue.push(root);

        while (!queue.empty()){
            Node* current = queue.front();
            queue.pop();
            sum += current->data;
            for (Node* children : current->children){
                queue.push(children);
            }
        }

        return sum;
    }

    // nodes greater than target
    vector<int> NodesGreater(int target) const {
        vector<int > result;
        stack<Node* > stack;
        stack.push(root);

        while(!stack.empty()){
            Node* current = stack.top();
            stack.pop();
            if (current->data > target){
                result.push_back(current->data);
            }
            for (Node* neighbor : current->children){
                stack.push(neighbor);
            }
        }
        return result;
    }

    // returns pair of two nodes sum to target else
    vector<vector<int>> twoSum(int target) const {
        vector<int> values;
        queue<Node* > queue;
        queue.push(root);

        // traverse and get all values
        while(!queue.empty()){
            Node* current = queue.front();
            queue.pop();
            values.push_back(current->data);
            for (Node* child : current->children){
                queue.push(child);
            }
        }

        // get all pairs
        unordered_set<int> visit;
        vector<vector<int>> result;
        for (int val : values){
            int diff = target - val;
            if (visit.count(diff)){
                result.push_back({min(diff, val), max(diff, val)});
            }
            visit.insert(val);
        }
        return result;
    }

    // tree parent is less than children
    bool isminHeap() const{
        if (!root){
            return true;  // empty tree can be considered valid
        }
        queue<pair<Node*, int >> queue;
        queue.push({root, INT_MIN});

        while (!queue.empty()){
            pair<Node*, int> currentPair = queue.front();
            queue.pop();
            Node* child  = currentPair.first;
            int parentVal = currentPair.second;

            if (child->data < parentVal){
                return false;
            }

            for (Node* neighbor : child->children){
                queue.push({neighbor, child->data});
            }
        }

        return true;
    }

    // only two children per parent
    bool isBinaryTree() const{
        queue<Node* > queue;
        queue.push(root);

        while(!queue.empty()){
            Node* current = queue.front();
            queue.pop();
            if (current->children.size() > 2){
                return false;
            }
            for (Node* neighbor : current->children){
                queue.push(neighbor);
            }
        }
        return true;
    }
    // Count nodes with value == target : int
    int sameValue(int target) const {
        if (!root){
            return 0;
        }
        int count {};
        stack<Node* > stack;
        stack.push(root);

        while (!stack.empty()){
            Node* current = stack.top(); 
            stack.pop();
            if (current->data == target){
                count ++;
            }
            for (Node* child : current->children){
                stack.push(child);
            }
        }

        return count;
    }
    // Find all nodes at given level / depth : vector<int> (DFS)
    vector<int> nodesLevelDfs(int targetLevel) const {
        if (!root || targetLevel < 0){
            return {};
        }

        vector<int> result;
        stack<pair<Node* , int>> stack;
        stack.push({root, 0});

        while(!stack.empty()){
            pair<Node* , int> currentPair = stack.top();
            stack.pop();
            Node* node    = currentPair.first;
            int currLevel = currentPair.second;

            if (currLevel == targetLevel){
                result.push_back(node->data);
            }
            for (auto it = node->children.rbegin(); it != node->children.rend(); it++){ //pushing in reverse order for leftmost is popped first
                stack.push({*it, currLevel + 1});
            }
        }
        return result;
    }
    // Find all nodes at given level / depth : vector<int> (BFS) -> break early once we reach higher level
    vector<int> nodesLevelBfs(int targetLevel) const {
        if (!root || targetLevel < 0){
            return {};
        }
        vector<int> result;
        queue<pair<Node* , int>> queue;
        queue.push({root, 0});

        while(!queue.empty()){
            pair<Node*, int> currPair = queue.front();
            queue.pop();
            Node* node    = currPair.first;
            int currLevel = currPair.second;

            if (currLevel == targetLevel){
                result.push_back(node->data);
            }

            if (currLevel > targetLevel){  // exit from searching 
                break;
            }
            for (Node* child : node->children){
                queue.push({child, currLevel + 1});
            }
        }
        return result;
    }

    // Sum of all nodes at given level : int
    int levelSum(int targetLevel) const{
        if (!root || targetLevel < 0){
            return 0;
        }
        int sum {};
        queue<pair<Node*, int>> queue;
        queue.push({root, 0});

        while (!queue.empty()){
            pair<Node* , int> currPair = queue.front();
            queue.pop();

            Node* node = currPair.first;
            int currLevel = currPair.second;
            if (currLevel == targetLevel){
                sum += node->data;
            }

            if (currLevel > targetLevel){
                break;
            }

            for (Node* child : node->children){
                queue.push({child, currLevel + 1});
            }
        }

        return sum;
    }
    // Has path with given sum (root → leaf): bool
    bool hasRootLeafPathSum(int targetSum) const {
        if (!root){
            return false;
        }

        queue<pair<Node*, int>> queue;
        queue.push({root, root->data });

        while (!queue.empty()){
            pair<Node*, int> currPair = queue.front();
            queue.pop();

            Node* node  = currPair.first;
            int currSum = currPair.second;

            if (node->children.size() == 0 && currSum == targetSum){ //is a leaf
                return true;
            }

            for (Node* child : node->children){
                queue.push({child, currSum + child->data});
            }
        }
        return false;
    }
    
    // true if there exists a level with this sum
    bool hasLevelwithSum(int levelSum) const{
        if(!root){
            return false;
        }
        queue<Node* > queue;
        queue.push(root);
        while(!queue.empty()){
            int sum {};
            int levelsize = queue.size();
            for (int i = 0; i < levelsize; i++){
                Node* node = queue.front(); queue.pop();
                sum += node->data;

                for (Node* child : node->children){
                    queue.push(child);
                }
            }

            if (sum == levelSum){
                return true;
            }
        }

        return false;
    }

    // Has path with given sum (root → Node): bool
    bool hasPathRootToNode(int pathSum) const {
        if (!root){
            return false;
        }

        stack<pair<Node*, int>> stack;
        stack.push({root, root->data});

        while (!stack.empty()){
            pair<Node*, int> currPair = stack.top(); stack.pop();
            Node* current = currPair.first;
            int currSum   = currPair.second;

            if (currSum == pathSum){
                return true;
            }
            for (Node* child : current->children){
                stack.push({child, currSum + child->data});
            }
        }

        return false;
    }

    // All root-to-leaf paths with given sum: vector<vector<int>>
    vector<vector<int>> rootToLeafPath(int targetSum){
        vector<vector<int>> result;

        // build map of parents {node -> {sum , parent}}
        unordered_map<Node*, pair<int, Node*>> map;
        Node* temp = new Node(0);
        map[root] = {root->data, temp};
        queue<pair<Node*, int>> queue;
        queue.push({root, root->data});

        while(!queue.empty()){
            pair<Node*, int> currPair = queue.front(); queue.pop();
            Node* current = currPair.first;
            int currSum   = currPair.second;

            for (Node* child : current->children){
                map[child] = {currSum + child->data, current};
                queue.push({child, currSum + child->data});
            }
        } 

        // get nodes from path 
        for (auto it = map.begin(); it != map.end(); it++){
            Node* key = it->first;
            pair<int, Node*> currPair = it->second;
            int currSum      = currPair.first;

            if (currSum == targetSum){
                vector<int> nodesVec = getNodes(key, map);
                result.push_back(nodesVec);
            }
        }

        return result;
    }

    // helper for getting parent nodes
    vector<int> getNodes(Node* node, unordered_map<Node*, pair<int, Node*>> checkMap){
        vector<int> result;
        Node* current = node;
        result.push_back(current->data);
        while(current != root){
            Node* parent = checkMap[current].second;
            result.push_back(parent->data);
            current = parent;
        }

        return result;
    }
};

void printVector(vector<int > vec){
    for (int val : vec){
        cout << val << " ";
    }
    cout << endl;
}
void printVectorVector(vector<vector<int>> vec){
    for (vector<int> v : vec){
        printVector(v);
    }
}

int main(){
    // nodes
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);
    Node* node5 = new Node(50);
    Node* node6 = new Node(60);
    Node* node7 = new Node(30);
    Node* node8 = new Node(80);

    // link nodes
        //            10
        //        20      30
        //      40  50 60   30
        //   80 
    node1->children.push_back(node2);                         
    node1->children.push_back(node3);
    node2->children.push_back(node4);
    node2->children.push_back(node5);
    node3->children.push_back(node6);
    node3->children.push_back(node7);
    node4->children.push_back(node8);

    // tree
    Tree myTree;
    myTree.setRoot(node1);
    vector<int> bfsVector = myTree.bfs();
    printVector(bfsVector);

    vector<int> dfsVector = myTree.dfs();
    printVector(dfsVector);

    cout << "Tree has " << myTree.getNodes() << " nodes" << endl;
    cout << "Tree has " << myTree.getLeafNodes() << " leaf nodes" << endl;

    cout << "Path exists: " << boolalpha << myTree.hasPath(node1, node6) << endl;

    cout << "Tree has " << myTree.height() << " levels" << endl;

    cout << "The longest path in this tree is " << myTree.longestPath() << endl;

    cout << "Sum of this tree is " << myTree.getSum() << endl;

    int target = 120;
    vector<vector<int>> twoSumVector = myTree.twoSum(target);

    for (vector<int> pair : twoSumVector){

        cout << pair[0] << " + " << pair[1] << " = " << target << endl;

    }

    vector<int> greaterNodes = myTree.NodesGreater(50);
    printVector(greaterNodes);

    cout << "Tree is min heap: " << boolalpha << myTree.isminHeap() << endl;
    cout << "Tree is a binary tree: " << boolalpha << myTree.isBinaryTree() << endl;

    int targetLevel = 2;
    vector<int> nodesDFS = myTree.nodesLevelDfs(targetLevel);
    printVector(nodesDFS);

    vector<int> nodesBFS = myTree.nodesLevelBfs(targetLevel);
    printVector(nodesBFS);

    cout << "The sum of nodes in level " << targetLevel << " is: " << myTree.levelSum(targetLevel) << endl;

    int targetSum = 150;
    cout << "Tree has path from root to leaf with sum " << targetSum << " : " << boolalpha << myTree.hasRootLeafPathSum(targetSum) << endl;

    int levelSum = 50;
    cout << "Tree has level with sum of " << levelSum << " : " << boolalpha << myTree.hasLevelwithSum(levelSum) << endl;

    int pathSum = 80;
    cout << "Tree has a path from root to a node with sum " << pathSum << " : " << boolalpha << myTree.hasPathRootToNode(pathSum) << endl;

    int RootpathSum = 70;
    vector<vector<int>> result = myTree.rootToLeafPath(RootpathSum);

    printVectorVector(result);
}




    // Find all paths from root to leaf (as vectors of values)

    
    // Diameter of a tree (longest path between any two nodes) : int
    // Check if tree is symmetric (mirror of itself) : bool
    // Maximum width of the tree : int 