struct cmp {
    bool operator() (const pair<int, string> &p1, const pair<int, string> &p2) const {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }
};

class FoodRatings {
    unordered_map<string, int> food_rat;
    unordered_map<string, string> food_cuis;
    unordered_map<string, set<pair<int, string>, cmp>> cuis_food_rat;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++)
            food_rat.insert({foods[i], ratings[i]});
        for(int i = 0; i < foods.size(); i++)
            food_cuis.insert({foods[i], cuisines[i]});
        for(int i = 0; i < cuisines.size(); i++) 
            cuis_food_rat[cuisines[i]].
            insert({ratings[i], foods[i]});   
    }
    
    void changeRating(string food, int newRating) {
        string foodCuisine = food_cuis[food];
        int curRating = food_rat[food];
        
        cuis_food_rat[foodCuisine].erase({curRating, food});
        cuis_food_rat[foodCuisine].insert({newRating, food});
        food_rat[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto p = *((cuis_food_rat[cuisine]).begin());
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */