class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if (A.size() < 3) return 0;
        sort(A.begin(), A.end(), greater<int>());
        for (auto it = A.begin(); it != A.end() - 2; ++it) {
            if (*it < *(it + 1) + *(it + 2))
                return *it + *(it + 1) + *(it + 2);            
        }
        return 0;
    }
};

