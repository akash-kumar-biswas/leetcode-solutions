class Solution {
public:
    int solve(vector<int>& nums){
        vector<int> vec;
        for(auto it: nums){
            int lb = lower_bound(vec.begin(), vec.end(), it) - vec.begin();
            if(lb == vec.size())
                vec.push_back(it);
            else
                vec[lb] = it;
        }
        return vec.size();
    }

    bool increasingTriplet(vector<int>& nums) {
        int lisLength = solve(nums);
        return lisLength >= 3;
    }
};