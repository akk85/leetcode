#include "../common.hpp"

/*
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lostMap;

        for (const vector<int>& match : matches){
            int winner = match[0];
            int losser = match[1];

            if (!lostMap.contains(winner)){
                lostMap[winner] = 0;
            }
            lostMap[losser] += 1;
        }

        vector<int> notLostMatch, lostOneMatch;
        for (const auto& [player , matchesLost] : lostMap){
            if (matchesLost == 0)      notLostMatch.push_back(player);
            else if (matchesLost == 1) lostOneMatch.push_back(player);
        }

        return {notLostMatch, lostOneMatch};
    }
};