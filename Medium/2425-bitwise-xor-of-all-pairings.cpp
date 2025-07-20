class Solution {
public:
    int xorSum(vector<int>& nums){
        int xorSum = 0;
        for(auto num: nums){
            xorSum ^= num;
        }
        return xorSum;
    }

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor_nums1 = (nums2.size() & 1)? xorSum(nums1) : 0;
        int xor_nums2 = (nums1.size() & 1)? xorSum(nums2) : 0;

        return xor_nums1 ^ xor_nums2;
    }
};