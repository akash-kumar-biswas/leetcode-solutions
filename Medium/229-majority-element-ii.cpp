class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(candidate1 == nums[i]){
                cnt1++;
            }
            else if(candidate2 == nums[i]){
                cnt2++;
            }
            else if(cnt1 == 0){
                candidate1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                candidate2 = nums[i];
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int c1 = 0, c2 = 0;
        for(auto num: nums){
            if(candidate1 == num)
                c1++;
            else if(candidate2 == num)
                c2++;
        }
        vector<int> ans;
        int n = nums.size();
        if(c1 > n/3)
            ans.push_back(candidate1);
        if(c2 > n/3)
            ans.push_back(candidate2);
        return ans;
    }
};