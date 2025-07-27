class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int cnt = 0;
        int n = nums.size();

        vector<int> unique;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] == nums[i])
                continue;
            else
                unique.push_back(nums[i - 1]);
        }

        unique.push_back(nums[n - 1]);

        for (int i = 1; i < unique.size() - 1; i++)
        {
            if ((unique[i - 1] < unique[i] && unique[i] > unique[i + 1]) ||
                (unique[i - 1] > unique[i] && unique[i] < unique[i + 1]))
                cnt++;
        }
        return cnt;
    }
};