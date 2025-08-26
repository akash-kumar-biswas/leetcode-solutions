class Solution
{
public:
    bool isExist(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        int mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;
            else if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }

    int firstOccurrence(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        int mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (target <= nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }

    int lastOccurrence(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        int mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (!isExist(nums, target))
            return {-1, -1};
        int start = firstOccurrence(nums, target);
        int end = lastOccurrence(nums, target);

        return {start, end};
    }
};