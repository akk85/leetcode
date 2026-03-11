#include "../common.hpp"

/*
Design a queue that supports push and pop operations in the front, middle, and back.

Implement the FrontMiddleBack class:

FrontMiddleBack() Initializes the queue.
void pushFront(int val) Adds val to the front of the queue.
void pushMiddle(int val) Adds val to the middle of the queue.
void pushBack(int val) Adds val to the back of the queue.
int popFront() Removes the front element of the queue and returns it. If the queue is empty, return -1.
int popMiddle() Removes the middle element of the queue and returns it. If the queue is empty, return -1.
int popBack() Removes the back element of the queue and returns it. If the queue is empty, return -1.
Notice that when there are two middle position choices, the operation is performed on the frontmost middle position choice. For example:

Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].
*/

class FrontMiddleBackQueue {
private:
    deque<int> frontQueue;
    deque<int> rightQueue;

    void resizeFrontqueue(){
        rightQueue.push_front(frontQueue.back());
        frontQueue.pop_back();
    }
    void resizeRightQueue(){
        frontQueue.push_back(rightQueue.front());
        rightQueue.pop_front();
    }
public:
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        frontQueue.push_front(val);

        int left  = frontQueue.size();
        int right = rightQueue.size();

        if (left - right > 0){
            resizeFrontqueue();
        }
    }
    
    void pushMiddle(int val) {
        rightQueue.push_front(val);

        int left  = frontQueue.size();
        int right = rightQueue.size();

        if (right - left > 1){
            resizeRightQueue();
        }
    }
    
    void pushBack(int val) {
        rightQueue.push_back(val);
    
        int left  = frontQueue.size();
        int right = rightQueue.size();

        if (right - left > 1){
            resizeRightQueue();
        }
    }
    
    int popFront() {
        if (frontQueue.empty() && rightQueue.empty()){
            return -1;
        }

        int front;
        if (!frontQueue.empty()){
            front = frontQueue.front();
            frontQueue.pop_front();
        } else {
            front = rightQueue.front();
            rightQueue.pop_front();
        }

        int left  = frontQueue.size();
        int right = rightQueue.size();

        if (right - left > 1){
            resizeRightQueue();
        }
        return front;
    }
    
    int popMiddle() {
        if (frontQueue.empty() && rightQueue.empty()){
            return -1;
        }

        int left  = frontQueue.size();
        int right = rightQueue.size();

        int middle = 0;
        if (left == right){
            middle = frontQueue.back();
            frontQueue.pop_back();
            left --;
        } else {
            middle = rightQueue.front();
            rightQueue.pop_front();
            right --;
        }

        if (right - left > 1) {
            resizeRightQueue();
        }
        return middle;
    }
    
    int popBack() {
        if (frontQueue.empty() && rightQueue.empty()){
            return -1;
        }

        int back;
        if (!rightQueue.empty()){
            back = rightQueue.back();
            rightQueue.pop_back();
        } else {
            back = frontQueue.back();
            frontQueue.pop_back();
        }

        int left  = frontQueue.size();
        int right = rightQueue.size();
        
        if (left - right > 0){
            resizeFrontqueue();
        }
        return back;
    }
};

int main(){
    FrontMiddleBackQueue q;

    q.pushFront(1);   // [1]
    q.pushBack(2);    // [1, 2]
    q.pushMiddle(3);  // [1, 3, 2]
    q.pushMiddle(4);  // [1, 4, 3, 2]
    cout << q.popFront()  << endl;     // return 1 -> [4, 3, 2]
    cout << q.popMiddle() << endl;    // return 3 -> [4, 2]
    cout << q.popMiddle() << endl;    // return 4 -> [2]
    cout << q.popBack()   << endl;      // return 2 -> []
    cout << q.popFront()  << endl;     // return -1 -> [] (The queue is empty)

}