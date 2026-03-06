#include "../common.hpp"

/*
You are given an array prerequisites where prerequisites[i] = [a, b] indicates that you must take course b first if you want to take course a.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
There are a total of numCourses courses you are required to take, labeled from 0 to numCourses - 1.

Return a valid ordering of courses you can take to finish all courses. If there are many valid answers, return any of them. If it's not possible to finish all courses, return an empty array.

Thought process:
    to take a course we need to take first its prerep
    we can build an adjanceny list of the courses and also map each course to how many prereq it has
    we can only take a course when its prerep gets to zero

    pseudo code
        for each pair in prereq
            course = pair[0]
            prereq = pair[1]
            adjlist[prereq].pushback(course)
            vec[course] += 1

        // push all courses with zero prereq to queue
        for each course in vec
            if course == 0
                q.push(course)

        res = []
        while q not empty
            currcourse = q.pop
            result.append(currcourse)
            for course in adjlist[currcourse]
                vec[course] --
                if vec[course] == 0
                    course oush to queue

        return res

*/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjList(numCourses);
        vector<int> vec(numCourses, 0);
        for (const vector<int>& pair : prerequisites){
            int course = pair[0];
            int preReq = pair[1];
            adjList[preReq].push_back(course);
            vec[course] ++;
        }

        // add all courses with no prereq that can be taken right now
        queue<int> q;
        for (int course = 0; course < numCourses; course++){
            if (vec[course] == 0) q.push(course);
        }

        vector<int> result;
        while(!q.empty()){
            int currPreReq = q.front(); q.pop();
            result.push_back(currPreReq);

            for (const int& course : adjList[currPreReq]){
                vec[course] --;
                if (vec[course] == 0) {
                    q.push(course);
                } 
            }
        }

        if (result.size() != numCourses){
            return {}; // could not take all coursess
        }

        return result;
    }
};

void printResult(const vector<int>& result){
    for (const int& val : result){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    Solution sol;

    vector<vector<int>> prerequisites = {{1,0}};

    vector<int> result = sol.findOrder(3, prerequisites);
    printResult(result);

    prerequisites = {{0,1}, {1,2}, {2,0}};

    result = sol.findOrder(3, prerequisites);
    printResult(result);
}