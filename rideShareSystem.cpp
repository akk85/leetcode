#include "common.hpp"
/*
A ride sharing system manages ride requests from riders and availability from drivers. Riders request rides, and drivers become available over time. The system should match riders and drivers in the order they arrive.

Implement the RideSharingSystem class:

RideSharingSystem() Initializes the system.
void addRider(int riderId) Adds a new rider with the given riderId.
void addDriver(int driverId) Adds a new driver with the given driverId.
int[] matchDriverWithRider() Matches the earliest available driver with the earliest waiting rider and removes both of them from the system. Returns an integer array of size 2 where result = [driverId, riderId] if a match is made. If no match is available, returns [-1, -1].
void cancelRider(int riderId) Cancels the ride request of the rider with the given riderId if the rider exists and has not yet been matched.

thought process 
    1. use two queuse to process riders and drivers in a fifa fashion and allows to just grab earliest rider / driver from front of queue in 0(1)
    2. need a way to track waiting riders and efficiently remove them from ride request when cancelrider is called maybe a map? or a set 
    {rider:}
    3 : false
    1 : false 
    * if rider cancels, just check set if this rider is present and remove them from active riders set if they are not present do nothing assuming they got matched before and got removd from the active set pool
    * also when doing match rider check if this rider is in our active riders set if not continue finding from front rider who hasnt cancelled 
pseudo code
    add rider
        queue.push(rider)
        activerequests.insert(rider)
    add driver
        queue.push(driver)
    matchdricerwithrider
        if at least one queue empty return {-1, -1}
        rider = queue.front() q.pop()
        if rider not in set
            try getting  another rider in queue and check rider is in set 
        driver = queue.front() queue.pop()

        remove rider from set
        return [driver, rider]
    cancelrider(rider)
    if rider in set remove from set 


*/

class RideSharingSystem {
public:
    queue<int> riders;
    queue<int> drivers;
    unordered_set<int> rideRequests;  // rider wants a ride 
    RideSharingSystem() {
        
    }
    
    // add this rider to queue and to set of requested rides 
    void addRider(int riderId) {
        riders.push(riderId);
        rideRequests.insert(riderId);
    }
    
    // add this driver to queue of drivers 
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    // get rider who still needs a ride and match with driver
    vector<int> matchDriverWithRider() {
        while(!riders.empty() && !rideRequests.contains(riders.front())){
            riders.pop();
        }

        if (riders.empty() || drivers.empty()){
            return {-1, -1};
        }

        int currRider = riders.front(); 
        riders.pop();
        rideRequests.erase(currRider);

        int currDriver = drivers.front(); 
        drivers.pop();

        return {currDriver, currRider};
    }
    
    // remove rider from set of requested riders 
    void cancelRider(int riderId) {
        if (rideRequests.contains(riderId)){
            rideRequests.erase(riderId);
        }
    }
};

void printResult(const vector<int>& result){
    for (const int& num : result){
        cout << num << " ";
    }
    cout << endl;
}

int main(){ 
    RideSharingSystem system;
    system.addRider(3);
    system.addDriver(2);
    system.addRider(1);

    vector<int> matched = system.matchDriverWithRider();
    printResult(matched);

    system.addDriver(5);
    system.cancelRider(3);

    matched = system.matchDriverWithRider();
    printResult(matched);

    matched = system.matchDriverWithRider();
    printResult(matched);
}
/*
ridequeue = {}
driverqueue = {};
requests =  {3 -> true}
            {1 -> false}

match = {5, 1}
match = {}
match = {}

ridequeue = 
*/
