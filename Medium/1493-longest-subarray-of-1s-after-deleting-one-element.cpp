class Solution {
public:

    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int cnt_0 = 0, ans = 0;

        while(j < n){
            if(nums[j] == 0)
                cnt_0++;
            while(i <= j && cnt_0 > 1){
                if(nums[i] == 0)
                    cnt_0--;
                i++;
            }
            ans = max(ans, j-i);
            j++;
        }
        return ans;
    }
};