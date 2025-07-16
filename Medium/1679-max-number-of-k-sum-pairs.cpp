class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int len = 0 ;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;

        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum == k){
                len++;
                l++;
                r--;
            }
            else if(sum < k)
                l++;
            else
                r--;
        }
        return len;
    }
};