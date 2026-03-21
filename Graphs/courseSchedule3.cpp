#include "../common.hpp"

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

Thougtt peocess:
    build adjaencey list for each course mapping course to prereq
    then traverse adjlist building a map of each course mapped to all prereq in a set
    since if c1 is prereq of c2 and c2 is prereq of c3 then c1 is prereq of c3
    1110 - 2110
    2110 - 3110

    1110 - 3110
*/

using vec = vector<int>;
class Solution {
private:
    vector<vec> adjList;
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adjList.resize(numCourses);

        for (const vec& edge : prerequisites){
            int preReq = edge[0];
            int course = edge[1];
            adjList[course].push_back(preReq);
        }

        unordered_map<int, unordered_set<int>> graph;

        for (int course = 0; course < numCourses; course ++){
            unordered_set<int> ans = bfs(course);
            graph[course] = ans;
        }
        
        vector<bool> result;
        for (const vec& query : queries){
            int course = query[1];
            int prereq = query[0];

            bool ans = graph[course].contains(prereq);
            result.push_back(ans);
        }

        return result;
        
    }
    unordered_set<int> bfs(int course){
        queue<int> q;
        q.push(course);

        unordered_set<int> ans;
        while(!q.empty()){
            int curr = q.front(); q.pop();
            if (curr != course) ans.insert(curr);

            for (const int& prereq : adjList[curr]){
                q.push(prereq);
            }
        }
        return ans;
    }
};