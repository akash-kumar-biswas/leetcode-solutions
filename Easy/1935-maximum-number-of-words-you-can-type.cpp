class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int map[26] = {0};
        for(auto cha: brokenLetters){
            map[cha - 'a'] = 1;
        }
        int ans = 0;
        int f = 1;
        for(auto cha: text){
            if(cha != ' ' && map[cha - 'a'])
                f = 0;
            if(cha == ' '){
                if(f)
                    ans++;
                else
                    f = 1;
            }
        }
        if(f)
            ans++;
        return ans;

    }
};