#include "common.hpp"

/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
Example 1:

Input: ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]

Output: [null, null, null, true, false, null, true, null, false]
Explanation:
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1); // set = [1]
myHashSet.add(2); // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2); // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2); // set = [1]
myHashSet.contains(2); // return False, (already removed)

*/
// solution 1 using a boolean array of length 1,000,001
// time is O(1) for each function and space is O(1,000,001) for the boolean vector
class MyHashSet1 {
private:
    vector<bool> vec;
public:
    MyHashSet1() : vec(1000000, false) {}
    
    void add(int key) {
        vec[key] = true;
    }
    
    void remove(int key) {
        vec[key] = false;
    }
    
    bool contains(int key) {
        return vec[key];
    }
    
};



int main(){
    MyHashSet1* myHashSet = new MyHashSet1();
    myHashSet->add(1); // set = [1]
    myHashSet->add(2); // set = [1, 2]
    cout << boolalpha << myHashSet->contains(1) << endl; // return True
    cout << boolalpha << myHashSet->contains(3) << endl; // return False, (not found)
    myHashSet->add(2); // set = [1, 2]
    cout << boolalpha << myHashSet->contains(2) << endl; // return True
    myHashSet->remove(2); // set = [1]
    cout << boolalpha << myHashSet->contains(2) << endl; // return False, (already removed)
}


