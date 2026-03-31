#include "../common.hpp"

/*
Given strings s and t, find the minimum window in s that contains t as a subsequence (not substring — order matters but characters don't need to be contiguous).

Input:  s = "a b c d e b d d e ", t = "b d e"

a b c d e b d d e    b d e
i                    
                    j
*/

class Solution{
public:
    string minimumWindowSubsequence(string& s1, string& s2){

        int i = 0;
        int j = 0;

        int minLength = INT_MAX;
        int stringStartPosition;
        while(i < (int)s1.size()){

            // forward scan 
            while (i < (int)s1.size() && j < (int)s2.size()) {
                if (s1[i] == s2[j]){
                    i ++;
                    j ++;
                    continue;
                }
                i ++;
            }

            // if made it to end of string2 
            if (j == (int)s2.size()){
                int right = i;
                j -= 1;
                i -= 1;
                
                while(i >= 0 && j >= 0){
                    if (s1[i] == s2[j]){
                        i --;
                        j --;
                        continue;
                    }
                    i --;
                }

                int left   = i + 1;
                int length = right - left;

                if (length < minLength){
                    minLength = length;
                    stringStartPosition = left;
                }

                // reset for conitnuing search
                j = 0;
                i = right + 1;
            }
            else {
                break;
            }
            
        }

        if (minLength == INT_MAX){
            return "";
        }
        string ans = s1.substr(stringStartPosition, minLength);

        return ans;
    }
};

int main(){
    Solution sol;

    string s1 = "abcdebdde";
    string s2 = "bde";

    cout << sol.minimumWindowSubsequence(s1, s2) << endl; // bcde

    s1 = "geeksforgeeks";
    s2 = "eksrg";

    cout << sol.minimumWindowSubsequence(s1, s2) << endl; // eksforg
}