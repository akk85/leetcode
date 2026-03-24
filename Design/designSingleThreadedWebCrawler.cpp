#include "../common.hpp"

class HtmlParser {
public:
    vector<string> getUrls(string url) {
        // hardcode a fake web graph for testing
        map<string, vector<string>> web = {
            {"http://example.com/page1", {"http://example.com/page2", "http://other.com"}},
            {"http://example.com/page2", {"http://example.com/page1", "http://example.com/page3"}},
            {"http://example.com/page3", {}}
        };
        if (web.contains(url)) {
            return web.at(url);
        }
        return {};     
    }
};

/*
queue = 
visited = http://example.com/page1, http://example.com/page2, http://example.com/page3
ans = http://example.com/page1, http://example.com/page2, http://example.com/page3
*/
class WebCrawler{
private:
    string getHostName(string url){
        int start = url.find("://") + 3;
        int end   = url.find("/", start);

        string hostname = url.substr(start, end - start);
        return hostname;
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser){
        queue<string> q;
        unordered_set<string> visited;
        q.push(startUrl);
        visited.insert(startUrl);
        string host = getHostName(startUrl);
        vector<string> ans;
        while(!q.empty()){
            string url = q.front(); q.pop();
            ans.push_back(url);

            vector<string> neighborUrls = htmlParser.getUrls(url);
            for (const string& neighb : neighborUrls){
                string urlHost = getHostName(neighb);

                if (urlHost == host && !visited.contains(neighb)){
                    q.push(neighb);
                    visited.insert(neighb);
                }
            }
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
    WebCrawler web;
    HtmlParser parser;
    vector<string> ans = web.crawl("http://example.com/page1", parser);

    print(ans);
}