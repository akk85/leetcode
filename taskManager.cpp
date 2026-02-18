#include "common.hpp"

/*
Thought process:
    use a map to map each task with its priroty and user
    use a set to keep track of each task and its priority

    we can use a set that maps each priorty to its task
    hence highest priority will be at the end of the set and we can just pop that when executing task
*/


class TaskManager {
private:
    unordered_map<int, pair<int,int>> tasksMap;
    set<pair<int, int>> prioritySet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int>& vec : tasks){
            int user     = vec[0];
            int task     = vec[1];
            int priority = vec[2];
            tasksMap[task] = {user, priority};
            prioritySet.insert({priority, task});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasksMap[taskId] = {userId, priority};
        prioritySet.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = tasksMap[taskId].second;

        pair<int, int> tastToRemove = {oldPriority, taskId};
        pair<int, int> tastToInsert = {newPriority, taskId};
        prioritySet.erase(tastToRemove);
        prioritySet.insert(tastToInsert);

        tasksMap[taskId].second = newPriority;
    }
    
    void rmv(int taskId) {
        int priority = tasksMap[taskId].second;
        pair<int, int> tastToRemove = {priority, taskId};
        prioritySet.erase(tastToRemove);

        tasksMap.erase(taskId);
    }
    
    int execTop() {
        if (prioritySet.empty()) return -1;

        set<pair<int, int>>::iterator prioritySetEnd      = prioritySet.end();
        set<pair<int, int>>::iterator prioritySetLastPair = prev(prioritySetEnd);

        pair<int, int> lastPair = *prioritySetLastPair;

        int task = lastPair.second;
        int user = tasksMap[task].first;

        prioritySet.erase(lastPair);
        tasksMap.erase(task);

        return user;
    }
};

int main(){
    vector<vector<int>> tasks = {{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    TaskManager taskmanager(tasks);

    taskmanager.add(4, 104, 5);
    taskmanager.edit(102, 8);
    cout << taskmanager.execTop() << endl; // 3
    taskmanager.rmv(101);
    taskmanager.add(5, 105, 15);
    cout << taskmanager.execTop() << endl; // 5

}