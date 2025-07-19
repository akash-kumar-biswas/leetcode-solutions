class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x_or = (a|b) ^ c;
        return __builtin_popcount(x_or) + 
        __builtin_popcount(x_or & (a&b));
    }
};