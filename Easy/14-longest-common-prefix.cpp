
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs.back();

        int n = min(first.size(), last.size());
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (first[i] != last[i])
                return ans;
            else
                ans.push_back(first[i]);
        }
        return ans;
    }
};