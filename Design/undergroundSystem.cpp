#include "../common.hpp"

class UndergroundSystem{
public:
    unordered_map<int, pair<string, int>> checkInMap;
    map<pair<string, string> , pair<int, int>> checkOutMap;
    UndergroundSystem() {

    }
    void checkIn(int id, string startStation, int startTime){
        checkInMap[id] = {startStation, startTime};
    }

    void checkOut(int id, string stopStation, int stopTime){
        string startStation = checkInMap[id].first;
        int startTime = checkInMap[id].second;

        int travelTime = stopTime - startTime;

        pair<string, string> route = {startStation, stopStation};
        if (!checkOutMap.contains(route)){
            checkOutMap[route] = {0, 0};
        }
        checkOutMap[route].first += travelTime;
        checkOutMap[route].second += 1;

    }

    double getAverageTime(string startStation, string endStation){
        pair<string, string> route = {startStation, endStation};
        int totalTime = checkOutMap[route].first;
        int totalCustomers = checkOutMap[route].second;

        return static_cast<double>(totalTime) / totalCustomers;
    }
};
/*
45 -> leyton, 3
32 -> paradse, 8
27 -> leyton, 10

(leyton , waterloo) -> 22 , 2
(paradise, cambridge) -> 14, 1


*/
int main(){
    UndergroundSystem system;

    system.checkIn(45, "Leyton", 3);
    system.checkIn(32, "Paradise", 8);
    system.checkIn(27, "Leyton", 10);
    
    system.checkOut(45, "Waterloo", 15); 
    system.checkOut(27, "Waterloo", 20);  
    system.checkOut(32, "Cambridge", 22); 

    cout << system.getAverageTime("Paradise", "Cambridge") << endl;   // 14
    cout << system.getAverageTime("Leyton", "Waterloo") << endl;   // 11

    system.checkIn(10, "Leyton", 24);
    
    cout << system.getAverageTime("Leyton", "Waterloo") << endl;      // 11
    
    system.checkOut(10, "Waterloo", 38); 
    cout << system.getAverageTime("Leyton", "Waterloo") << endl;  // 12 
}