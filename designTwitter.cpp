#include "common.hpp"

/*
Implement a simplified version of Twitter which allows users to post tweets, follow/unfollow each other, and view the 10 most recent tweets within their own news feed.

Users and tweets are uniquely identified by their IDs (integers).

Implement the following methods:

Twitter() Initializes the twitter object.
void postTweet(int userId, int tweetId) Publish a new tweet with ID tweetId by the user userId. You may assume that each tweetId is unique.
List<Integer> getNewsFeed(int userId) Fetches at most the 10 most recent tweet IDs in the user's news feed. Each item must be posted by users who the user is following or by the user themself. Tweets IDs should be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId follows the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId unfollows the user with ID followeeId.
*/

class Twitter {
private:
    int time;
    unordered_map<int, vector<pair<int, int>>> tweetMap;   // user -> array of tweets each tweet has a timestamp
    unordered_map<int, unordered_set<int>>     followMap;  // user -> set of followees
    

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time, tweetId});
        time ++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> maxHeap;        // {time, tweetID. followeeID, index}
        // get users tweets
        followMap[userId].insert(userId);

        for (const int& followee : followMap[userId]){
            if (tweetMap.count(followee)  && !tweetMap[followee].empty()){
                vector<pair<int, int>>& followeeTweets = tweetMap[followee];

                int lastIndex = followeeTweets.size() - 1;

                auto& [time, tweetID] = followeeTweets[lastIndex];

                maxHeap.push({time, tweetID, followee, lastIndex - 1});
            }
        }

        vector<int> result;
        while (!maxHeap.empty() && result.size() < 10){
            auto [time, tweetID, followee, nextIndex] = maxHeap.top(); maxHeap.pop();
            result.push_back(tweetID);

            if (nextIndex >= 0){
                vector<pair<int, int>>& followeeTweets = tweetMap[followee];
                auto [nextTime, nextTweetID] = followeeTweets[nextIndex];
                maxHeap.push(make_tuple(nextTime, nextTweetID, followee, nextIndex - 1));
            }
        }

        return result;

    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followMap[followerId].erase(followeeId);
        }
    }
};

void printResult(vector<int>& result){
    for (const int& val : result){
        cout << val << " ";
    }

    cout << endl;
}
int main(){
    Twitter twitter;

    twitter.postTweet(1, 10);
    twitter.postTweet(2, 20);

    vector<int> result = twitter.getNewsFeed(1); 
    printResult(result); // 10
    
    result = twitter.getNewsFeed(2); 
    printResult(result); // 20

    twitter.follow(1, 2);
    result = twitter.getNewsFeed(1);

    printResult(result); // 20 , 10
}

