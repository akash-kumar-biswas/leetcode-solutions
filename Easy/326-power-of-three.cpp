const int N = 1162261467;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        return N%n == 0;
    }
};