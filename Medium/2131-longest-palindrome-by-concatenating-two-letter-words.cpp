class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> ump;

        int ans = 0;
        for(auto str: words){
            string temp = str;
            reverse(temp.begin(), temp.end());

            if(ump[temp] != 0){
                ans += 4;
                ump[temp]--;
            }
            else
                ump[str]++;
        }

        for(auto it: ump){
            string str = it.first;
            if(str[0] == str[1] && it.second != 0){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};