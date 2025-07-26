class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> ust;
        int neg_max = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
                ust.insert(nums[i]);
            else
                neg_max = max(neg_max, nums[i]);
        }
        if (!ust.size())
            return neg_max;
        int ans = 0;

        for (auto it : ust)
        {
            ans += it;
        }
        return ans;
    }
};