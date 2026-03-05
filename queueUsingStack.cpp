#include "common.hpp"

#include "common.hpp"

/*
first in first out (FIFO) two stacks
*/
class MyQueue {
private:
    stack<int>  mainStack;
    stack<int>  tempStack;
public:
    MyQueue() {
    }
    
    void push(int x) {
        mainStack.push(x);
    }
    
    int pop() {
        if (mainStack.empty()){
            return -1;
        }

        while(mainStack.size() > 1){
            int val = mainStack.top(); mainStack.pop();
            tempStack.push(val);
        }

        int result = mainStack.top(); mainStack.pop();

        while(!tempStack.empty()){
            mainStack.push(tempStack.top()); tempStack.pop();
        }
        return result;
    }
    
    int peek() {
        if (mainStack.empty()){
            return -1;
        }

        int val = 0;
        while(!mainStack.empty()){
            val = mainStack.top(); mainStack.pop();
            tempStack.push(val);
        }

        while(!tempStack.empty()){
            mainStack.push(tempStack.top()); tempStack.pop();
        }

        return val;
    }
    
    bool empty() {
        return mainStack.empty();
    }
};

int main(){
    MyQueue queue;

    queue.push(1);
    queue.push(2);

    cout << queue.peek() << endl;     // 1

    cout << queue.pop() << endl;     // 1

    cout << boolalpha << queue.empty() << endl; // false
}
/*
1 , 2
*/