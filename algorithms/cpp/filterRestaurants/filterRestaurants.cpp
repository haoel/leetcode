static bool cmp(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] == v2[1] ? v1[0] > v2[0] : v1[1] > v2[1];
}
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> res;
        
        for(int i = 0; i < restaurants.size(); i++) {
            if (!restaurants[i][2] && veganFriendly) continue;
            if (restaurants[i][3] > maxPrice) continue;
            if (restaurants[i][4] > maxDistance) continue;
            res.push_back(restaurants[i]);
        }
        
        sort(res.begin(), res.end(), cmp);
        
        vector<int> ids;
        for(int i = 0; i < res.size(); i++) ids.push_back(res[i][0]);
        return ids;        
    }
};