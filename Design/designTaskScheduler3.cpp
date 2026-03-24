#include "../common.hpp"

/*
You are given a list of tasks where each task has a priority and a deadline. 

Implement a scheduler that always executes the highest priority task first.
*/

struct Task {
    string name;
    int    priority;
    int    insertionOrder;
    int    deadline;
};

class TaskScheduler {
private:
    priority_queue<tuple<int, int, string>> maxHeap; // priority, insertion order, taskName;
    unordered_map<string, Task> activeTasksMap;         // task -> details 
    int count = 0;

public:
    void addTask(string name, int priority, int deadline){
        maxHeap.push({priority, -count, name});
        Task currTask(name, priority, count, deadline);
        activeTasksMap[name] = currTask;
        count += 1;
    }
    string getNextTask(){
        while(!maxHeap.empty() && !activeTasksMap.contains(std::get<2>(maxHeap.top()))){
            maxHeap.pop();
        }
        if (maxHeap.empty()) {
            return "";
        }
        return std::get<2>(maxHeap.top());
    }
    void completeTask(string name){
        activeTasksMap.erase(name);
    }
    vector<string> getOverdueTasks(int currentTime){
        vector<string> ans;
        for (const auto& [name, task] : activeTasksMap){
            if (task.deadline < currentTime){
                ans.push_back(name);
            }
        }
        return ans;
    }
};

int main(){
    TaskScheduler ts;
    ts.addTask("email",       2, 10);
    ts.addTask("meeting",     5, 8);
    ts.addTask("code review", 5, 6);

    cout << ts.getNextTask() << "\n";   // meeting
    ts.completeTask("meeting");
    cout << ts.getNextTask() << "\n";   // code review

    vector<string> overdue = ts.getOverdueTasks(7);
    for (auto& t : overdue) cout << t << "\n";  // code review
}