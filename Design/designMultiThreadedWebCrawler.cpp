#include "../common.hpp"
#include <mutex>
#include <thread>
/*
Only URLs within the same host as the startUrl should be crawled.

The web server will only send one request at a time. If multiple requests are sent, the connection to the web server will be blocked.
*/

class WebCrawler{
private:
    queue<string>         sharedQueue;
    unordered_set<string> sharedVisitedSet;
    vector<string>        ans;
    string                host;
    mutex                 queueMutex;
    mutex                 visitedSetMutex;
    mutex                 ansMutex;
    int                   threadsRunning = 0;
    condition_variable    condition;
    string getHostName(string url){
        int start = url.find("://") + 3;
        int end   = url.find("/", start);

        string hostname = url.substr(start, end - start);
        return hostname;
    }
    
    vector<string> getUrls(string url) {
        map<string, vector<string>> web =  {{"http://example.com/page1", {"http://example.com/page2", "http://other.com"}},
                                            {"http://example.com/page2", {"http://example.com/page1", "http://example.com/page3"}},
                                            {"http://example.com/page3", {}}
                                           };
        if (web.contains(url)) {
            return web.at(url);
        }
        return {};     
    }
    void threadFunction(){
        while(true){
            unique_lock<mutex> queueLock(queueMutex);

            while(sharedQueue.empty() && threadsRunning != 0){ // empty queue but still have running threads, sleep this thread
                condition.wait(queueLock);
            }

            if (sharedQueue.empty() && threadsRunning == 0){ // empty queue and no running threads notify all threads to wake up and exit from loop.
                condition.notify_all();
                break;
            }

            string currentUrl = sharedQueue.front(); sharedQueue.pop();

            threadsRunning += 1;

            queueLock.unlock();  // unlock the lock to queue

            unique_lock<mutex> ansLock(ansMutex);
            ans.push_back(currentUrl);
            ansLock.unlock();

            vector<string> neighbors = getUrls(currentUrl);

            for (const string& neighborUrl : neighbors){
                string urlHost = getHostName(neighborUrl);

                unique_lock<mutex> queuePushLock(queueMutex);
                unique_lock<mutex> setLock(visitedSetMutex);

                if (urlHost == host && !sharedVisitedSet.contains(neighborUrl)){
                    sharedQueue.push(neighborUrl);
                    sharedVisitedSet.insert(neighborUrl);

                    condition.notify_one(); // notify a sleeping thread queue has a new item added to it 
                }
            }

            unique_lock<mutex> finalLock(queueMutex);
            threadsRunning -= 1;
            condition.notify_all(); // notify all threads to check if work is done and exit from sleep and while loop 
            finalLock.unlock();
        }
    }
public:
    vector<string> crawl(string startUrl, int numThreads = 4){
        sharedQueue.push(startUrl);
        sharedVisitedSet.insert(startUrl);

        host = getHostName(startUrl);

        vector<thread> threads;
        for (int i = 0; i < numThreads; i++){
            thread thred(&WebCrawler::threadFunction, this);
            threads.push_back(std::move(thred));
        }

        for (thread& t : threads){
            t.join();
        }

        return ans;
    }
};

void print(vector<string>& ans){
    for (const string& url : ans){
        cout << url << endl;
    }
    cout << endl;
}

int main(){
    WebCrawler crawler;
    vector<string> ans = crawler.crawl("http://example.com/page1");

    print(ans);
}