class Solution {
public:
    vector<int> allSubsetOr;

    void solve(vector<int>& nums, int _or, int idx){
        if(idx == nums.size()){
            allSubsetOr.push_back(_or);
            return;
        }

        int temp = _or;
        _or |= nums[idx];
        solve(nums, _or, idx+1);
        _or = _or ^ (temp & nums[idx]) ^ nums[idx];
        solve(nums, _or, idx+1);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        solve(nums, 0, 0);
        int maxOr = *max_element(allSubsetOr.begin(), allSubsetOr.end());
        return count(allSubsetOr.begin(), allSubsetOr.end(), maxOr);
    }
};