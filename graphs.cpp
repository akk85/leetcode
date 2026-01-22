#include <iostream>
#include <vector>
using namespace std;

/*
Graph Representation using an adjacency list
*/
class Graph{
private:
    int n; 
    vector<vector<int>> adj;
public:
    Graph(int vertices){
        n   = vertices;
        adj = vector<vector<int>>(n);
    }

    void addEdge(int node, int neighbor){
        adj[node].push_back(neighbor);
        //adj[neighbor].push_back(node);
    }


    void printEdges(){
        for (int node = 0; node < n; node++){
            cout << node << "->";
            for (const int& neighbor : adj[node]){
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    vector<int> dfs(int src){
        stack<int> stack;
        stack.push(src);

        vector<int> result;
        while (!stack.empty()){
            int current = stack.top();
            stack.pop();
            result.push_back(current);
            for (const int& neighbor : adj[current]){
                stack.push(neighbor);
            }
        }
        return result;
    }

    vector<int> bfs(int src){
        queue<int> queue;
        queue.push(src);
        
        vector<int> result;
        while (!queue.empty()){
            int current = queue.front();
            queue.pop();
            result.push_back(current);
            for (const int& neighbor : adj[current]){
                queue.push(neighbor);
            }
        }
        return result;
    }

    bool hasPathDfs(int src, int dst){
        stack<int> stack;
        stack.push(src);
        while (!stack.empty()){
            int current = stack.top();
            stack.pop();
            if (current == dst){
                return true;
            }
            for (const int& neighbor : adj[current]){
                stack.push(neighbor);
            }
        }

        return false;
    }

    bool hasPathBfs(int src, int dst){
        queue<int> queue;
        queue.push(src);

        while (!queue.empty()){
            int current = queue.front();
            queue.pop();
            if (current == dst){
                return true;
            }

            for (const int& neighbor : adj[current]){
                queue.push(neighbor);
            }
        }
        return false;
    }
    
    void hasCycles(){

    }


};


void printVector(vector<int>& vec){
    for (int node : vec){
        cout << node << " ";
    }
    cout << endl;
}

void createGraph(Graph &graph){
    graph.addEdge(1,2);
    graph.addEdge(1,4);
    graph.addEdge(4,3);
    graph.addEdge(4,5);
    graph.addEdge(5,6);
    graph.addEdge(6,7);
}

int main(){
    int n = 7;
    Graph graph(n);
    
    createGraph(graph);
    graph.printEdges();

    vector<int> dfsResult = graph.dfs(1);
    vector<int> bfsResult = graph.bfs(1);

    printVector(dfsResult);
    printVector(bfsResult);
    cout << graph.hasPathDfs(1,5) << endl;
    cout << graph.hasPathBfs(1,7) << endl;
}



