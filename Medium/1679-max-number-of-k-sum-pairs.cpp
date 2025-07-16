class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> ump;

        int len = 0 ;
        for(auto ele: nums){
            if(ump[ele] != 0){
                len++;
                ump[ele]--;
            }
            else
                ump[k - ele]++;
        }
        return len;
    }
};