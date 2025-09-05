class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxNum = *max_element(nums.begin(), nums.end());

        int sec_max = 0;
        int cnt_max = 0;
        for (auto num : nums)
        {
            if (maxNum == num)
                cnt_max++;
            else
                sec_max = max(sec_max, num);
        }

        return (cnt_max > 1) ? (maxNum - 1) * (maxNum - 1) : (maxNum - 1) * (sec_max - 1);
    }
};

// Time Complexity = O(N)