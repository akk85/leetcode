#include "common.hpp"

/*
Design a number container system that can do the following:

Insert or Replace a number at the given index in the system.

Return the smallest index for the given number in the system.

Implement the NumberContainers class:

NumberContainers() Initializes the number container system.

void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.

int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.

thought process:
    1. Map each index with its number.
    2. Use a map of ordered set to store each indices of each number

    for find:
        if number in 2ndMap return its top set index
        else return -1
    for change
        if index not in 1st map, make new entry to both maps
        if index already exists:
            get it's mapped number from map1
            go remove this index from set of number in map2
            then replace number of this index in map1
*/

class NumberContainers {
private:
    unordered_map<int, int>      indexMap;
    unordered_map<int, set<int>> numberMap; 
public:
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if (!indexMap.contains(index)){
            indexMap[index] = number;
            numberMap[number].insert(index);
            return;
        }

        int mappedNumber = indexMap[index];
        numberMap[mappedNumber].erase(index);

        indexMap[index] = number;
        numberMap[number].insert(index);
    }
    
    int find(int number) {
        if (numberMap.contains(number) && !numberMap[number].empty()){
            set<int>::iterator topIterator = numberMap[number].begin();
            int smallestIndex = *topIterator;
            return smallestIndex;
        }
        return -1;
    }
};

int main() {
    NumberContainers container;

    cout << container.find(10) << endl; // -1 

    container.change(2, 10);
    container.change(1, 10);
    container.change(3, 10);
    container.change(5, 10);

    cout << container.find(10) << endl; // 1

    container.change(1, 20);

    cout << container.find(10) << endl; // 2
}
