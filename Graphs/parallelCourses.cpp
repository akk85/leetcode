#include "../common.hpp"

/*
You are given an integer n, which indicates that there are n courses labeled from 1 to n. 

You are also given an array relations where relations[i] = [prevCourseᵢ, nextCourseᵢ], 
representing a prerequisite relationship between course prevCourseᵢ and course nextCourseᵢ: course prevCourseᵢ has to be taken before course nextCourseᵢ.

In one semester, you can take any number of courses as long as you have taken all the prerequisites in the previous semester for the courses you are taking.

Return the minimum number of semesters needed to take all courses. If there is no way to take all the courses, return -1.
*/


class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adjList(n + 1);
        vector<int> indegree(n + 1, 0);
        for (const vector<int>& edge : relations){
            int prereq = edge[0];
            int course = edge[1];
            adjList[prereq].push_back(course);
            indegree[course] ++;
        }

        queue<int> q;
        for (int course = 1; course <= n; course ++){
            if (indegree[course] == 0){
                q.push(course);
            }
        }

        if (q.empty()){
            return -1;
        }

        int semester = 0;
        int coursesTaken = 0;
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                int prereq = q.front(); q.pop();
                coursesTaken += 1;

                for (const int& course : adjList[prereq]){
                    indegree[course] --;
                    if (indegree[course] == 0){
                        q.push(course);
                    }
                }
            }
            semester += 1;
        }

        if (coursesTaken == n){
            return semester;
        }

        return -1;
    }
};

