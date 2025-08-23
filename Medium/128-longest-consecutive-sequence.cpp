class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> st;

        for (auto it : nums)
        {
            st.insert(it);
        }
        vector<int> temp;
        for (auto it : st)
        {
            temp.push_back(it);
        }
        int ans = 1;
        int cnt = 1;
        for (int i = 1; i < temp.size(); i++)
        {
            if (temp[i] == temp[i - 1] + 1)
                cnt++;
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return (nums.size() == 0) ? 0 : ans;
    }
};