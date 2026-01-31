#include "common.hpp"

class Solution{
public:
    unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector< int>> adjList (numCourses);

        for (const vector<int>& course : prerequisites){
            adjList[course[0]].push_back(course[1]);
        }

        for (int course = 0; course < numCourses; ++course){
            if (!bfs(adjList, course)){
                return false;
            }
        }
        return true;
    }

    bool bfs(vector<vector<int>>& adjList, int course){
        queue<int> q;
        q.push(course);
        visited.insert(course);

        while(!q.empty()){
            int currCourse = q.front(); q.pop();

            for (int neighbor : adjList[currCourse]){
                if (visited.contains(neighbor)){
                    return false;
                }
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
        return true;

    }

};
/*
0 - 1
1 - 0


queue = 1 
visited = 0
*/
int main(){
    Solution sol;

    int numCourses = 2;

    vector<vector<int>> prerequisites = {
        {0, 1},
    };

    cout << boolalpha << sol.canFinish(numCourses, prerequisites) << endl;
    
    numCourses = 2;
    prerequisites = {
        {0, 1},
        {1, 0},
    };

    

    cout << boolalpha << sol.canFinish(numCourses, prerequisites) << endl;
}