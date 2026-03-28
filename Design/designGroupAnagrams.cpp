#include "../common.hpp"

class AnagramGroupManager{
private:
    unordered_map<string, unordered_set<string>> keySetMap;
    string getKey(const string& word){
        vector<int> freqTable(26, 0);

        for (const char& ch : word){
            freqTable[ch - 'a'] += 1;
        }

        string ans;
        for (int i = 0; i < 26; i++){
            ans += to_string(freqTable[i]) + ',';
        }
        return ans;
    }
public:
    void addWord(const string& word){
        string key = getKey(word);
        keySetMap[key].insert(word);
    }
    vector<string> getGroup(const string& word){
        string key = getKey(word);
        if (!keySetMap.contains(key)) return {};

        const unordered_set<string>& groupSet = keySetMap[key];

        vector<string> ans(groupSet.begin(), groupSet.end()); // range iterator constructor  
        return ans;
    }

    bool deleteWord(const string& word){
        string key = getKey(word);

        if (!keySetMap.contains(key)) return false;

        keySetMap[key].erase(word);

        if (keySetMap[key].empty()){
            keySetMap.erase(key);
        }
        return true;
    }

    bool isValidAnagram(const string& word1, const string& word2){
        string key1 = getKey(word1);
        string key2 = getKey(word2);

        return (key1 == key2);
    }

    vector<vector<string>> getAllGroups(){
        vector<vector<string>> ans;
        for (const auto& [key, groupSet] : keySetMap){
            vector<string> vec(groupSet.begin(), groupSet.end());
            ans.push_back(vec);
        }

        return ans;
    }
};

int main(){
    AnagramGroupManager manager;

    cout << boolalpha << manager.isValidAnagram("eat", "ate") << endl;
    
    manager.addWord("eat");
    manager.addWord("tea");
    manager.addWord("tan");
    manager.addWord("ate");
    manager.addWord("nat");
    manager.addWord("bat");

    vector<vector<string>> ans = manager.getAllGroups();
    for (const vector<string>& vec : ans){
        for (const string& word : vec){
            cout << word << " ";
        }
        cout << endl;
    }

    vector<string> result = manager.getGroup("eat");
    for (const string& word : result){
        cout << word << " ";
    }
    cout << endl;

    manager.deleteWord("eat");
    result = manager.getGroup("eat");
    for (const string& word : result){
        cout << word << " ";
    }
    cout << endl;

}