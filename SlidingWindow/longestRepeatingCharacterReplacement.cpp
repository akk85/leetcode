#include "../common.hpp"

/*
Thought process;
    1. use a sliding window that requires k or less replacements
    2. we will see how many replaceents we need in the window by counting freq of least frequoent character in that window
    3. once window grows too big( requiring more than k replacments) we shrink it from the left
*/
class Solution{
public:
    int characterReplacement(string s, int k){
        int l = 0;
        int r = 0;
        int n = s.size();
        unordered_map<char, int> counter;
        int ans {};

        while (r < n){
            counter[s[r]] ++;
            int currentMaxFrequency = getMaxFrequency(counter);
            int charToReplace = r - l + 1 - currentMaxFrequency;

            while (charToReplace > k && l <= r){
                counter[s[l]] --;
                l++;

                currentMaxFrequency = getMaxFrequency(counter);
                charToReplace = r - l + 1 - currentMaxFrequency;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
    int getMaxFrequency(const unordered_map<char, int>& counter){
        if (counter.empty()) return 0;
        int max = 0;
        for (const auto& pair : counter){
            if (pair.second > max){
                max = pair.second;
            }
        }
        return max;
    }
};

/*
x y x y 

*/

int main(){
    Solution sol;
    string s = "XYXY"; int k = 2;
    cout << sol.characterReplacement(s, k) << endl; // 4


    s = "AAABABB"; k = 1;
    cout << sol.characterReplacement(s, k) << endl; // 5

    s = "AABABBA"; k = 1;
    cout << sol.characterReplacement(s, k) << endl; // 4

}