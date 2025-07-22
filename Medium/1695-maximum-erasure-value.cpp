class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> ust;
        int max_score = INT_MIN;
        int i = 0, j = 0;
        int sum = 0;

        while (j < nums.size())
        {
            sum += nums[j];
            while (ust.find(nums[j]) != ust.end())
            {
                sum -= nums[i];
                ust.erase(nums[i]);
                i++;
            }
            max_score = max(max_score, sum);
            ust.insert(nums[j]);
            j++;
        }
        return max_score;
    }
};