#include "../common.hpp"

/*
You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creators[i], has an id of ids[i], and has views[i] views.

The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.

If multiple creators have the highest popularity, find all of them.
If multiple videos have the highest view count for a creator, find the lexicographically smallest id.
Note: It is possible for different videos to have the same id, meaning that ids do not uniquely identify a video. For example, two videos with the same ID are considered as distinct videos with their own viewcount.

Return a 2D array of strings answer where answer[i] = [creatorsi, idi] means that creatorsi has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.


Thought process:
    use a map mapping each creator to their info totalviews, bestvideoviews, bestvideoid
*/

class Solution {
private:
    struct creatorInfo{
        long long totalViews = 0;
        int       maxVideoViews = 0;
        string    bestVideoID;
    };
    unordered_map<string, creatorInfo> creatorsMap;
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        for (int i = 0; i < n; i++){
            string creator = creators[i];
            string videoID = ids[i];
            int videoViews = views[i];

            addCreator(creator, videoID, videoViews);
        }
        vector<vector<string>> answer = getPopularCreators();
        return answer;
    }

    void addCreator(string& creator, string& videoID, int videoViews){
        creatorInfo& info = creatorsMap[creator];

        info.totalViews += videoViews;

        if (info.bestVideoID.empty() || videoViews > info.maxVideoViews){ // case when starting off list 
            info.maxVideoViews = videoViews;
            info.bestVideoID = videoID;
        }

        else if (videoViews == info.maxVideoViews && videoID < info.bestVideoID){
            info.bestVideoID = videoID;
        }
    }

    vector<vector<string>> getPopularCreators(){
        long long highestVideoViews = 0;
        for (const auto& [creator, info] : creatorsMap){
            if (info.totalViews > highestVideoViews){
                highestVideoViews = info.totalViews;
            }
        }
        vector<vector<string>> result;
        for (const auto& [creator, info] : creatorsMap){
            if (info.totalViews == highestVideoViews){
                result.push_back({creator, info.bestVideoID});
            }
        }

        return result;
    }
};

void printResult(vector<vector<string>>& ans){
    for (auto& v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    vector<string> creators = {"alice","bob","alice","chris"};
    vector<string> ids      = {"one", "two", "three","four"};
    vector<int> views       = {5,10,5,4};

    vector<vector<string>> answer = sol.mostPopularCreator(creators, ids, views);

    printResult(answer); // [["alice","one"],["bob","two"]]
}