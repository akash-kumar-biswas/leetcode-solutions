class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)
            return false;
        
        int f_vowel = false, f_const = false;
        for(int i = 0; i < word.size(); i++){
            if(string("AEIOUaeiou").find(word[i]) != string::npos)
                f_vowel = true;
            else if('A' <= word[i] && word[i] <= 'z') 
                f_const = true;
            else if(('0' <= word[i] && word[i] <= '9') == false)
                return false;
        }
        return f_vowel && f_const;
    }
};