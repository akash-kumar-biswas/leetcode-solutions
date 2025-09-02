class Solution
{
public:
    string withoutSorting(vector<int> &arr, string str)
    {
        for (auto cha : str)
        {
            arr[cha - 'a']++;
        }

        string temp;
        for (int i = 0; i < 26; i++)
        {
            char cha = 'a' + i;
            while (arr[i]--)
                temp.push_back(cha);
        }
        return temp;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> ump;
        for (auto str : strs)
        {
            vector<int> arr(26, 0);
            string temp = withoutSorting(arr, str);
            ump[temp].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto it : ump)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};