#include "common.hpp"

class TimeStore{
public:
    unordered_map<string, vector<pair<string, int>>> store;
    TimeStore(){
    }

    void set(string key, string value, int timestamp){
        store[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp){
        string result = "";
        vector<pair<string, int>>& values = store[key];

        int l = 0; 
        int r = values.size() - 1;

        while (l <= r){
            int m = (l + r) / 2;
            if (values[m].second <= timestamp){
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
alice -> {happy, 1} , {sad, 3}
               lr
{{happy, 1} , {sad, 3}}


*/
int main(){
    TimeStore store;

    store.set("alice", "happy", 1);
    
    cout << store.get("alice", 1) << endl;   // happy
    cout << store.get("alice", 2) << endl;   // happy

    store.set("alice", "sad", 3);
    cout << store.get("alice", 3) << endl;    // sad

}