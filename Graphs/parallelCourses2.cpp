#include "../common.hpp"

/*
You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei. Also, you are given the integer k.

In one semester, you can take at most k courses as long as you have taken all the prerequisites in the previous semesters for the courses you are taking.

Return the minimum number of semesters needed to take all courses. The testcases will be generated such that it is possible to take every course.
*/


class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
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

        int semester = 0;
        while(!q.empty()){
            int size = q.size();

            for (int i = 0; i < min(k, size); i++){
                int prereq = q.front(); q.pop();

                for (const int& course : adjList[prereq]){
                    indegree[course] --;
                    if (indegree[course] == 0){
                        q.push(course);
                    }
                }
            }
            semester += 1;
        }

        return semester;
    }
};

