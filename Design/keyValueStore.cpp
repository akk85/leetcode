#include "../common.hpp"

class TimeMap {
public:
    unordered_map<string, vector<pair<string , int>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> values = map[key];
        
        int l = 0;
        int r = values.size() - 1;

        string result = "";
        while (l <= r){
            int m = (l + r) / 2;
            int middle = values[m].second;

            if (middle <= timestamp){
                result = values[m].first;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return result;
    }
};

/*
foo -> [(bar, 1), (bar2, 4), (bar3, 8)]
map[foo] = 
1 2 3 4 9
l   m   r 
*/
int main(){
    TimeMap store;

    store.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    cout << store.get("foo", 1) << endl;         // return "bar"
    cout << store.get("foo", 3) << endl;         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    store.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    store.set("foo", "bar3", 5);
    cout << store.get("foo", 4) << endl;         // return "bar2"
    cout << store.get("foo", 5) << endl;         // return "bar3"

}