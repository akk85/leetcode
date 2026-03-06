#include "../common.hpp"
#include <set>
/*
Design a food rating system that can do the following:

Modify the rating of a food item listed in the system.
Return the highest-rated food item for a type of cuisine in the system.
Implement the FoodRatings class:

FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. The food items are described by foods, cuisines and ratings, all of which have a length of n.
foods[i] is the name of the ith food,
cuisines[i] is the type of cuisine of the ith food, and
ratings[i] is the initial rating of the ith food.
void changeRating(String food, int newRating) Changes the rating of the food item with the name food.
String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. If there is a tie, return the item with the lexicographically smaller name.
Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, 

that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

map for food -> cousine, rating

food -> cuisine, rating
kimchi -> {korean
miso  -> {japanese,
sushi -> {japanese, 
moussaka -> {greek,
ramen -> {japanese,
bulgogi -> {korean,


map for cuisine -> pair<rating, food>
korean -> (7, bulgoi) (9, kimchi)
japanese ->  (8 sushi), {12, miso) {14 ramen}
greek - > {15 moussaka}

since set orderes values in increasing fashion in a binary tree we will negate ratig to have highest rating beciome less na dbe stored at top of tree

pseudo code
public:
    unordered_map<string, string> food to cuisine 
    unordredmap<string, int> food to rating 
    unorededmap<cusine, set<pair<int, string >>> cusinetoratingFood // cusine -> {rating, food}

    constructur
        for each index in foods, cuisines, ratings
            food = foods[i]
            cusine  = cuisines[i]
            rating = ratings[i];
            foodtocuisine[food] = cuisisne;
            foodtorating[ffood] = rating;
            cusinestofood[cusines].insert({-rating, food})

    changerating<string food, int newRating>
        cusines = foodtocusine[food]
        old rating = foodtorting[food]
        cuisinestofoodrating.erase({-oldrating, cuisnes})
        cuisinestofoodrating.insert({-oldrating, cuisnes})
        foodtorating[food] = newrating

    highestrated<cusines>
    cuisinestofoodrating[cuisine].begin().second


 */
class FoodRatings {
public:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int>    foodToRating;
    unordered_map<string, set<pair<int, string>>> cuisineToFoodRating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int index = 0; index < n; index++){
            string food = foods[index];
            int rating = ratings[index];
            string cuisine = cuisines[index];

            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;
            cuisineToFoodRating[cuisine].insert({-rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating = foodToRating[food];
        foodToRating[food] = newRating;

        string cuisine = foodToCuisine[food];
        cuisineToFoodRating[cuisine].erase({-oldRating, food});
        cuisineToFoodRating[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto topFoodRatingPair = cuisineToFoodRating[cuisine].begin();

        string food = topFoodRatingPair->second;
        return food;

    }
};

int main(){
    vector<string> food = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};
    FoodRatings foodRatings(food, cuisines, ratings);

    cout << foodRatings.highestRated("korean") << endl;  // kimchi

    cout << foodRatings.highestRated("japanese") << endl;  // ramen

    foodRatings.changeRating("sushi", 16);

    cout << foodRatings.highestRated("japanese") << endl; // sushi

    foodRatings.changeRating("ramen", 16);

    cout << foodRatings.highestRated("japanese") << endl; // ramen

}
