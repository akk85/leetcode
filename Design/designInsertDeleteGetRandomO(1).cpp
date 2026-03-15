#include "../common.hpp"

/*
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.
*/

class RandomizedSet {
private:
    unordered_map<int, int> map; // value -> index
    vector<int> vec;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        bool notinmap = !map.contains(val);

        if (notinmap){
            map[val] = vec.size();
            vec.push_back(val);
            return notinmap;
        }

        return !notinmap;
    }
    
    bool remove(int val) {
        bool inmap = map.contains(val);
        if (inmap){
            int index      = map[val];
            int lastValue  = vec[vec.size() - 1];
            vec[index]     = lastValue;
            map[lastValue] = index;
            map.erase(val);
            vec.pop_back();
            return inmap;
        }

        return !inmap;
    }
    
    int getRandom() {
        int index = rand() % vec.size();
        int random = vec[index];

        return random;
    }
};

int main(){
    RandomizedSet rand;

    cout << boolalpha << rand.insert(1) << endl; // true   
    cout << boolalpha << rand.insert(2) << endl; // true

    cout << rand.getRandom() << endl;

    cout << boolalpha << rand.remove(1) << endl; // true 
    cout << boolalpha << rand.insert(1) << endl; // true

    cout << boolalpha << rand.getRandom() << endl; // 2
}