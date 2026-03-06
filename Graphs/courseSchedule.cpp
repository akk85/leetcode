#include "../common.hpp"

/*
Thought process:
    To finish all courses we have to start with a course that has no prerequisites take it inorder to move on right.

    so if we take course 0 with no prereq we can move on to course 1 but if all courses have prereq we cant from anywhere hence no course can be taken

    for each course we can count how many prereq needed and start from course with zero. after taking this course we can 
    decrease the prerequisites of the courses needing this course by 1 and so on

    1. build and adjacency list for easier course traversal mapping each prereq with its courses
    2. build a map with each course mapping to number of prerequisites
    3. starting from all prereq with zero prere push them to a queue, take them and decrease their respective postrequisite by 1
    4. return at the end courses taken is equal to all the courses in the schedule

    pseudo code
        for each prereq pair in prerequistes
            prereq = pair[0]
            course = pair[1]
            adjlist[prereq].pushback(course) 
            courses[course] += 1

        for each course in courses map
            if map[course] == 0
            push to queue

        // bfs 
        while queue not empty
            prereq = q.pop
            taken ++;

            for all courses of this prereq in adjlist(prereq)
                map[course] --;
                if map[course] == 0
                    q.push(course)

        return taken == number of course
        
*/
class Solution {
public:
    unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> vec(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        for (const vector<int>& pair : prerequisites){
            int course = pair[0];
            int preReq = pair[1];
            adjList[preReq].push_back(course);
            vec[course] ++;
        }

        queue<int> q;
        for (int course = 0; course < numCourses; course++){
            if (vec[course] == 0) q.push(course);
        }

        int taken = 0;
        while(!q.empty()){
            int currPreReq = q.front(); q.pop();
            taken ++;
            for (const int& course : adjList[currPreReq]){
                vec[course] --;
                if (vec[course] == 0){
                    q.push(course);
                }
            }
        }

        return taken == numCourses;  
    }

};

int main(){
    Solution sol;

    vector<vector<int>> prerequisites = {{0,1}};

    cout << boolalpha << sol.canFinish(2, prerequisites) << endl;

    prerequisites = {{0,1}, {1,0}};

    cout << boolalpha << sol.canFinish(2, prerequisites) << endl;
}



