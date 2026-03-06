#include "../common.hpp"

/*
Design a system that manages the reservation state of n seats that are numbered from 1 to n.

Implement the SeatManager class:

SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. All seats are initially available.

int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.

void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.

thought process:
    1. use a minheap whose to element will always be the smallest unreserved sit
    
*/
class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    SeatManager(int n) {
        for (int seat = 1; seat <= n; seat++){
            minHeap.push(seat);
        }
    }
    
    int reserve() {
        int seat = minHeap.top();
        minHeap.pop();

        return seat;
    }
    
    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
    }
};


int main(){
    SeatManager seatManager(5);

    cout << seatManager.reserve() << endl; // 1
    cout << seatManager.reserve() << endl; // 2

    seatManager.unreserve(2);

    cout << seatManager.reserve() << endl; // 2
    cout << seatManager.reserve() << endl; // 3
    cout << seatManager.reserve() << endl; // 4
    cout << seatManager.reserve() << endl; // 5

    seatManager.unreserve(5); 
}
