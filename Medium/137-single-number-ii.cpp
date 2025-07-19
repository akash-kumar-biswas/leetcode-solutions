class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i <= 31; i++){
            int cnt_1 = 0;
            for(auto num: nums){
                if(num & (1<<i))
                    cnt_1++;
            }
            if(cnt_1 % 3)
                ans = ans | (1<<i);
        }
        return ans;
    }
};