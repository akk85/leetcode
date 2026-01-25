#include "common.hpp"


class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int rows = words.size();

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < words[r].size(); c++){
                
                if (c >= rows || r >= words[c].size() ||
                    words[r][c] != words[c][r]){
                        return false;
                    }
            }
        }

        return true;
    }
};

int main(){
    Solution sol;
    vector<string> words1= {"abcd",
                            "bnrt",
                            "crmy",
                            "dtye"};
 
    vector<string> words2= {"abcd",
                            "bnrt",
                            "crm",
                            "dt"};

    vector<string> words3= {"ball",
                            "area",
                            "read",
                            "lady"};                        

    cout << boolalpha << sol.validWordSquare(words1) << endl;
    cout << boolalpha << sol.validWordSquare(words2) << endl;
    cout << boolalpha << sol.validWordSquare(words3) << endl;
}