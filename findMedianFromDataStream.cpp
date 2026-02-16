#include "common.hpp"

/*
The median is the middle value in a sorted list of integers. 

For lists of even length, there is no middle value, so the median is the mean of the two middle values.

For example:

For arr = [1,2,3], the median is 2.
For arr = [1,2], the median is (1 + 2) / 2 = 1.5
Implement the MedianFinder class:

Thought process:
    we can use two heaps to track the values being added
        * a max heap that stores the smallest of the elements
        * a min heap that stores the biggest  of the elements
    
    * idea is that to get the median if odd size we get the top element in the largest heap
                                     if evn size we get the top elements in both heaps and divide by two

    * when adding an element into our stream
        * we always add it to small heap
        * if top element of small heap(max heap) is bigger than top element in big heap(min heap) we remove from small and push to big
        * if either heap sizes differ by more than 1 we resize 
        * to resize
            * if small heap large we take top value and push to big heap
            * if big   heap large we take top value and push to small heap 
   
Time -> add will be O(logn) for adding and popping elements from the heaps
     -> find median will be O(1) as accessing top elements of queues is a constant time operation

Space -> 0(n) as we are storing queues of total size n 
pseudo code:
    MedianFinder() 
    initialize two heaps 

    void add(int num)
        push to small heap
        if smallheap.top > bigheap.top
            pop and push

        // uneven sizes
        if (smallheap.size - bigheap.size > 1)
            resizesmallheap
        if (bigheap.size - smallheap.size > 1)
            resizebigheap

    double findMedian
        if (smallheap.size > bigheap.size)
            return smallheap.top
        if (largeheap.size > smallheap.size)
            return bigheap.top

        return (smallheap.top + bigheap.small ) / 2

    
*/

class MedianFinder{
public:        
    priority_queue<int, vector<int>, less<int>>    smallHeap;
    priority_queue<int, vector<int>, greater<int>> bigHeap;

    // helper function for resizing the heaps 
    void resizeSmallHeap(){
        int topVal = smallHeap.top();
        smallHeap.pop();
        bigHeap.push(topVal);
    }

    void resizeBigHeap(){
        int topVal = bigHeap.top();
        bigHeap.pop();
        smallHeap.push(topVal);
    }

    MedianFinder() {
    }

    void addNum(int num){
        smallHeap.push(num);
        
        if (!bigHeap.empty() && smallHeap.top() > bigHeap.top()){
            resizeSmallHeap();
        }

        // resize id needed 
        int small = smallHeap.size();
        int big  = bigHeap.size();

        if (small - big > 1) resizeSmallHeap();
        if (big   - small > 1) resizeBigHeap();
    }

    double findMedian(){
        if (smallHeap.size() > bigHeap.size()){
            return smallHeap.top();
        }

        if (bigHeap.size() > smallHeap.size()){
            return bigHeap.top();
        }

        return static_cast<double>(smallHeap.top() + bigHeap.top()) / 2;
    }

};


int main(){
    MedianFinder medianFinder;

    medianFinder.addNum(1);
    cout << medianFinder.findMedian() << endl; // 1

    medianFinder.addNum(3);
    cout << medianFinder.findMedian() << endl; // 2

    medianFinder.addNum(2);
    cout << medianFinder.findMedian() << endl; // 2

}

/*
[1, 2, 3]
*/

