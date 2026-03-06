#include "../common.hpp"

/*
You are asked to design an auction system that manages bids from multiple users in real time.

Each bid is associated with a userId, an itemId, and a bidAmount.

Implement the AuctionSystem class:​​​​​​​

AuctionSystem(): Initializes the AuctionSystem object.
void addBid(int userId, int itemId, int bidAmount): 
Adds a new bid for itemId by userId with bidAmount. If the same userId already has a bid on itemId, replace it with the new bidAmount.

void updateBid(int userId, int itemId, int newAmount): 
Updates the existing bid of userId for itemId to newAmount. It is guaranteed that this bid exists.

void removeBid(int userId, int itemId): Removes the bid of userId for itemId. 
It is guaranteed that this bid exists.

int getHighestBidder(int itemId): Returns the userId of the highest bidder for itemId.
If multiple users have the same highest bidAmount, return the user with the highest userId. If no bids exist for the item, return -1.

*/
/*
Thought Process:
    we can use two maps to map each item to its bid sorted by highest amount and another map to map each item to their user and
    and user mapped to their amount
    Map1:
        item -> a set of pairs of (amount, user)
    
    Map2
        item -> another map of user -> amount

    to add a bid we check if this user is already in the map of users -> amount 
    if user present we update user amount with new amount and remove bid pair from map1 set and add new amount pair
    if not present just make new entries to each map

    removing a bid:
        we index the second map to get the amount bid and remove the pair (amount, user) from map 1 set
        we also remove user entry from map2 by indexing map[item] gives us map of this items and doing secondmap.remove(user)

    gethighest bidder we just return top pair in set of map1  
*/

class AuctionSystem {
public:
    unordered_map<int, set<pair<int, int>>>     map1;
    unordered_map<int, unordered_map<int, int>> map2;
    AuctionSystem() {

    }
    // if user exists update both maps else make new entries to both maps 
    void addBid(int userId, int itemId, int bidAmount) {
        if (map2[itemId].contains(userId)){
            int oldAmount = map2[itemId][userId];

            pair<int, int> pairToRemove = {oldAmount, userId};
            pair<int, int> pairToAdd    = {bidAmount, userId};

            map1[itemId].erase(pairToRemove);
            map1[itemId].insert(pairToAdd);

            map2[itemId][userId] = bidAmount;
            return; 
        }

        map1[itemId].insert({bidAmount, userId});
        map2[itemId][userId] = bidAmount;
    }
    
    // update amount in both maps 
    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = map2[itemId][userId];

        pair<int, int> pairToRemove = {oldAmount, userId};
        pair<int, int> pairToAdd    = {newAmount, userId};
        map1[itemId].erase(pairToRemove);
        map1[itemId].insert(pairToAdd);

        map2[itemId][userId] = newAmount;
    }

    // get amount from map2 and remove entry from both map1 and map2 
    void removeBid(int userId, int itemId) {
        int amount = map2[itemId][userId];

        pair<int, int> pairToRemove = {amount, userId};
        map1[itemId].erase(pairToRemove);

        map2[itemId].erase(userId);
    }
    
    // map1 set is ordered ascendingly; get iterator to the last pair and return user of that pair 
    int getHighestBidder(int itemId) {
        set<pair<int, int>>& bidSet = map1[itemId];
        if (bidSet.empty()) return -1;

        set<pair<int, int>>::iterator bidSetEnd = bidSet.end();

        set<pair<int, int>>::iterator bidSetLastPair = prev(bidSetEnd);

        pair<int, int> lastPair = *bidSetLastPair;

        return lastPair.second;
    }
};

int main(){
    AuctionSystem system;

    system.addBid(1, 7, 5);
    system.addBid(2, 7, 6);
    cout << system.getHighestBidder(7) << endl;    // 2

    system.updateBid(1, 7, 8);
    cout << system.getHighestBidder(7) << endl;    // 1

    system.removeBid(2, 7); 
    cout << system.getHighestBidder(7) << endl;    // 1

    cout << system.getHighestBidder(3) << endl;    // 1
}
/*
map1
7 -> (8, 1)

map2
[7 -> [1 -> 8]


*/