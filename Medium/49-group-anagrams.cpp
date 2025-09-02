class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(auto str: strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            ump[temp].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(auto it: ump){
            ans.push_back(it.second);
        }
        return ans;
    }
};