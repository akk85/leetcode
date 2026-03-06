#include "../common.hpp"

class ParkingSystem {
public:
    int bigLot;
    int mediumLot;
    int smallLot;
    ParkingSystem(int big, int medium, int small){
        bigLot = big;
        mediumLot = medium;
        smallLot = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1 && bigLot > 0){
            bigLot --;
            return true;
        } else if (carType == 2 && mediumLot > 0){
            mediumLot --;
            return true;      
        } else if (carType == 3 && smallLot > 0){
            smallLot --;
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    ParkingSystem system(1,1,0);
    cout << boolalpha << system.addCar(1) << endl; // return true because there is 1 available slot for a big car
    cout << boolalpha << system.addCar(2) << endl; // return true because there is 1 available slot for a medium car
    cout << boolalpha << system.addCar(3) << endl; // return false because there is no available slot for a small car
    cout << boolalpha << system.addCar(1) << endl; // return false because there is no available slot for a big car. It is already occupied.
}

/*
[1]
[1]
[0]
*/