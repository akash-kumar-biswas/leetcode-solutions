class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> ust;

        for(auto it: nums){
            ust.insert(it);
        }
        vector<int> ans;
        for(int i = 1; i <= nums.size(); i++){
            if(ust.find(i) == ust.end())
                ans.push_back(i);
        }
        return ans;
    }
};