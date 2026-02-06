#include "common.hpp"

/*
first in first out (FIFO) two stacks
*/
class MyQueue {
public:
    stack<int>  queue1;
    stack<int>  queue2;

    MyQueue() {
        
    }
    
    void push(int x) {
        
    }
    
    int pop() {
        
    }
    
    int peek() {
        
    }
    
    bool empty() {
        
    }
};

int main(){
    MyQueue queue;

    queue.push(1);
    queue.push(2);

    queue.peek();     // 1

    queue.pop();     // 1

    queue.empty();
}
/*
1 , 2
*/