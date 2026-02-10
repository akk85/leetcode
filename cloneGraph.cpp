#include "common.hpp"

/*
Given a node in a connected undirected graph, return a deep copy of the graph.

Each node in the graph contains an integer value and a list of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
The graph is shown in the test cases as an adjacency list. An adjacency list is a mapping of nodes to lists, used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

For simplicity, nodes values are numbered from 1 to n, where n is the total number of nodes in the graph. The index of each node within the adjacency list is the same as the node's value (1-indexed).

The input node will always be the first node in the graph and have 1 as the value.
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int nodeVal) {
        val = nodeVal;
        neighbors = vector<Node*>();
    }
    Node(int nodeVal, vector<Node*> NodeNeighbors) {
        val = nodeVal;
        neighbors = NodeNeighbors;
    }
};

/*
Thought Process:
    the input is a node which inside itself has a vector of its neighbors and from this neighbors we can be able to acess the whole graph right?
    because each neighbor in the vector list is itself a node with it's own vector neighbor I can visualise this like an adjency matrix
    1. since we are doing a deep copy we can use a map to map the old copy node to it's new copied node
    2. this way as we iterate the neighbor vector of a node, to avoid recreating a deep copy of this node again if we had already visited it
    via a different node say parent, we can check if node is already in map if not only create it then push it to map and as well to our queue/ stack whichever inorder to visit its children as well and make copies of those
    if already visited, we just want to add this neighbor node deep copy into the vector list of the parent node. do this for all nodes and 
    then return the new created node of the parameter node.
    Time -> O(n + e) since we visit each node and for each node we visit its edges connection
    Space-> O(n) we only store 2*n nodes in our map which simplies to O(n)

    *edge cases:
        1. if node is null, we just return null no need to create deep copy of a nullptr. is this even possible in c++? what does 
        creating a copy of a nullptr mean? is that creating another nullptr that points to nothing?
        2. if only 1 node which has no neighbors? we will still have this run in our algothm since when we explore its neighbors we 
        will find no neighbors to explore and exit the bfs withiut creating new nodes and just return new node of this given node with no neighbors


*/
class Solution{
public:
    Node* cloneGraph(Node* node){
        if (!node) return nullptr;

        unordered_map<Node*, Node*> map;
        Node* copy = new Node(node->val);
        map[node] = copy;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()){
            Node* curr = q.front(); q.pop();

            for (Node* neighbor : curr->neighbors){
                if (!map.contains(neighbor)){
                    Node* deepCopy = new Node(neighbor->val);
                    map[neighbor] = deepCopy;
                    q.push(neighbor);
                }
                map[curr]->neighbors.push_back(map[neighbor]);   // push deepcopy neighbor to curr's vector of neighbors 
            }
        }

        Node* deepCopy = map[node];
        return deepCopy;
    }
};

int main(){

}
