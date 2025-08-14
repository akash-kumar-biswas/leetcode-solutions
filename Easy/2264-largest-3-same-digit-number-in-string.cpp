class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();

        int max_digit = -1;
        for(int i = 0; i < n-2; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2])
                max_digit = max(max_digit, num[i] - '0');   
        }
        string s = to_string(max_digit);
        return (max_digit == -1)? "":s+s+s;
    }
};