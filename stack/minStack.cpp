#include "../common.hpp"

/*

Design a stack class that supports the push, pop, top, and getMin operations.

MinStack() initializes the stack object.

void push(int val) pushes the element val onto the stack.

void pop() removes the element on the top of the stack.

int top() gets the top element of the stack.

int getMin() retrieves the minimum element in the stack.

Each function should run in O(1) time.
*/

class minStack{


public:
    vector<int> vec;
    vector<int> minVec;

    minStack(){

    }
    void push(int x){
        vec.push_back(x);
        if (!minVec.empty()){
            int minimum = minVec.back();
            minVec.push_back(min(minimum, x));
        } else {
            minVec.push_back(x);
        }
    }

    void pop(){
        if (!vec.empty()){
            vec.pop_back();
            minVec.pop_back();
        }
    }

    int top(){
        if (!vec.empty()){
            return vec.back();
        }
        return -1;
    }

    int getMin(){
        if (!minVec.empty()){
            return minVec.back();
        }
        return -1;
    }
};


int main(){
    minStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(0);
    // 1 2 0
    cout << stack.getMin() << endl;

    stack.pop();

    cout << stack.top() << endl;

    cout << stack.getMin() << endl;

}


