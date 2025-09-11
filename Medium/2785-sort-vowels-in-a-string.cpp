class Solution {
public:
    string vowel = "AEIOUaeiou";
    string sortVowels(string s) {
        string t;
        t.resize(s.size(), '0');

        for(int i = 0; i < s.size(); i++){
            if(vowel.find(s[i]) == string::npos)
                t[i] = s[i];
        }

        sort(s.begin(), s.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(vowel.find(s[i]) != string::npos){
                while(j < s.size() && t[j] != '0')
                    j++;
                t[j] = s[i];
            }
        }
        return t;
    }
};