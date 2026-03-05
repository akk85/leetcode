#include "common.hpp"

/*
Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).

Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive roughly at the same time.

Implement the HitCounter class:

HitCounter() Initializes the object of the hit counter system.
void hit(int timestamp) Records a hit that happened at timestamp (in seconds). Several hits may happen at the same timestamp.
int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp (i.e., the past 300 seconds).

intuition
    use a queueu
    and since timestamps are in chronological order
    for gethIts iterating from front which was the earliest we can remove any timestamp that exxceeeds the 300 duration once we find one that doesnt exceed all others will be safe 
    so we can break and return size of queue
*/

class HitCounter {
private:
    queue<int> hits;
public:
    HitCounter() {
    }
    
    void hit(int timestamp) {
        hits.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while(!hits.empty()){
            int diff = timestamp - hits.front();
            if (diff >= 300) {
                hits.pop();
            }
            else {
                break;
            }
        }

        return hits.size();
    }
};

int main(){
    HitCounter counter;

    counter.hit(1);
    counter.hit(2);
    counter.hit(3);
    
    cout << counter.getHits(4) << endl; // 3

    counter.hit(300);

    cout << counter.getHits(300) << endl; // 4

     cout << counter.getHits(301) << endl; // 3

}